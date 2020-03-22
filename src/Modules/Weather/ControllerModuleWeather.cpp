#include <Modules/Weather/ControllerModuleWeather.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Modules/Utils/UtilTime.h>
#include <Modules/Utils/UtilFramMem.h>
#include <WiFi.h>

ControllerModuleWeather::ControllerModuleWeather (const String & forecastURL) :
    m_forecastURL(forecastURL) , 
    m_flagNeedUpdate(false)
{
    m_dataWeather = new DataViewWeather();
    m_view = new DisplayModuleWeather(m_dataWeather);
}

ControllerModuleWeather::~ControllerModuleWeather()
{
    if(m_dataWeather)
    {
        delete m_dataWeather;
        m_dataWeather = nullptr;
    }
}

void ControllerModuleWeather::GetServerData(String forecastURL)
{
        if (WiFi.status() != WL_CONNECTED)
        {
            Serial.printf("[ControllerModuleWeather] no wifi ");  
            Serial.printf( "Load old weather datas\n" );        
            LoadDatas(m_memories);    
            return;
        }
        HTTPClient http;
        http.setTimeout(5000);
        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin(forecastURL); //HTTP

        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                //Serial.println(payload);
                const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
                DynamicJsonBuffer jsonBuffer(capacity);

                JsonObject& root = jsonBuffer.parseObject(payload);
                if (!root.success()) {
                    Serial.println(F("Parsing failed!"));
                    return;
                }
                JsonArray& arrayWeather = root["list"].as<JsonArray&>();
                // Get Humidity
                double humidity = arrayWeather[0]["main"]["humidity"].as<double>();
                // Get current outside temperature
                m_dataWeather->TemperatureOut = arrayWeather[0]["main"]["temp"].as<double>() - 273.15;
                // Get current pression 
                m_dataWeather->Pression = arrayWeather[0]["main"]["pressure"].as<double>();
                // Get current cloud state
                m_dataWeather->weather = IconCodeToIconImg(arrayWeather[0]["weather"][0]["icon"].as<String>());
                CollectWeatherOfWeek(arrayWeather);
                // int Year, Month, Day, Hour, Minute, Second ;
                // sscanf(arrayWeather[1]["dt_txt"].as<char*>(), "%d-%d-%d %d:%d:%d", &Year, &Month, &Day, &Hour, &Minute, &Second);
                // Serial.println(arrayWeather[1]["dt_txt"].as<char*>());
                // UtilTime::dayOfWeek(Year, Month, Day);
                // Serial.print("day 2: ");Serial.println(UtilTime::getDayOfWeekStr(UtilTime::dayOfWeek(Year, Month, Day)));
                // // Extract values
                // Serial.println(F("Response:"));
                // Serial.print("humidity: ");Serial.println(humidity,3);
                // Serial.print("temperature: ");Serial.println(m_dataWeather->TemperatureOut, 3);
                Serial.printf( "SaveDatas weather datas\n" ); 
                SaveDatas(m_memories);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());  
            Serial.printf( "[ControllerModuleWeather] Load old weather datas\n" );        
            LoadDatas(m_memories);       
        }

        http.end();
}

void ControllerModuleWeather::CollectWeatherOfWeek(JsonArray& array)
{
    int FirstYear, FirstMonth, FirstDay, FirstHour, Minute, Second ;
    sscanf(array[0]["dt_txt"].as<char*>(), "%d-%d-%d %d:%d:%d", &FirstYear, &FirstMonth, &FirstDay, &FirstHour, &Minute, &Second);
    int itrDay = -1;
    // Serial.printf("FirstDay= %d; FirstHour=%d\n",  FirstDay, FirstHour);
    double lastDay = 0;
    // Serial.printf(" lastDay=%f; itrDay=%i\n",  lastDay, itrDay);
    for(JsonVariant currentJson : array) {   
        int Year , Month, Day, Hour ;    
        sscanf(currentJson["dt_txt"].as<char*>(), "%d-%d-%d %d:%d:%d", &Year, &Month, &Day, &Hour, &Minute, &Second);
        // Serial.printf("Day= %d; Hour=%d\n",  Day, Hour);
        if (Hour <= 8 || Hour >= 20)
        {
            // We don't care about the weather during the night.
            continue;
        }
        if (Day != lastDay) 
        {            
            itrDay = itrDay + 1;
            if(itrDay >= MAX_DAY_WEATHER) break;
            //Serial.printf("Day= %d; lastDay=%f; itrDay=%i\n",  Day, lastDay, itrDay);
            m_dataWeather->weekWeather[itrDay].DayOfWeek = UtilTime::day_Of_Week(Year, Month, Day);
            m_dataWeather->weekWeather[itrDay].TemperatureMin   = atof(currentJson["main"]["temp"].as<char*>()) - 273.15;
            m_dataWeather->weekWeather[itrDay].TemperatureMax   = atof(currentJson["main"]["temp"].as<char*>()) - 273.15;
            m_dataWeather->weekWeather[itrDay].weatherMorning   =  IconWeatherImage::none;
            m_dataWeather->weekWeather[itrDay].weatherAfternoon =  IconWeatherImage::none;
			lastDay = Day;
        }else 
        {
            m_dataWeather->weekWeather[itrDay].TemperatureMin   =   (atof(currentJson["main"]["temp"].as<char*>()) - 273.15) < m_dataWeather->weekWeather[itrDay].TemperatureMin ?
                                                                    (atof(currentJson["main"]["temp"].as<char*>()) - 273.15) : m_dataWeather->weekWeather[itrDay].TemperatureMin ;
            
            m_dataWeather->weekWeather[itrDay].TemperatureMax   =   (atof(currentJson["main"]["temp"].as<char*>()) - 273.15) > m_dataWeather->weekWeather[itrDay].TemperatureMax ?
                                                                    (atof(currentJson["main"]["temp"].as<char*>()) - 273.15) : m_dataWeather->weekWeather[itrDay].TemperatureMax;

            // Since we don't want an icon from the start of the day (in the middle of the night)
            // we update the icon as long as it's somewhere during the day.
            if ( Hour <= 12 ) {
                // Serial.printf(" icon m =%s\n",  currentJson["weather"][0]["icon"].as<char*>());
                if(m_dataWeather->weekWeather[itrDay].weatherMorning != IconWeatherImage::ChanceRain && // If it rains we keep this logo
                   m_dataWeather->weekWeather[itrDay].weatherMorning != IconWeatherImage::rain && 
                   m_dataWeather->weekWeather[itrDay].weatherMorning != IconWeatherImage::Tstorms &&
                   m_dataWeather->weekWeather[itrDay].weatherMorning != IconWeatherImage::Snow)
                   {
                        m_dataWeather->weekWeather[itrDay].weatherMorning   = IconCodeToIconImg(currentJson["weather"][0]["icon"].as<char*>());
                   }
            }
            else
            {
                // Serial.printf(" icon a =%s\n",  currentJson["weather"][0]["icon"].as<char*>());
                if(m_dataWeather->weekWeather[itrDay].weatherAfternoon != IconWeatherImage::ChanceRain && // If it rains we keep this logo
                   m_dataWeather->weekWeather[itrDay].weatherAfternoon != IconWeatherImage::rain && 
                   m_dataWeather->weekWeather[itrDay].weatherAfternoon != IconWeatherImage::Tstorms &&
                   m_dataWeather->weekWeather[itrDay].weatherAfternoon != IconWeatherImage::Snow)
                   {
                        m_dataWeather->weekWeather[itrDay].weatherAfternoon   = IconCodeToIconImg(currentJson["weather"][0]["icon"].as<char*>());
                   }
            }
            
        }        
    }
}

IconWeatherImage::IconWeater ControllerModuleWeather::IconCodeToIconImg(String iconTable)
{
    IconWeatherImage::IconWeater result;

    if( iconTable == "01d" || iconTable == "01n" )
    {
        result = IconWeatherImage::sun;
    }
    else if( iconTable == "02d" || iconTable == "02n" )
    {
        result = IconWeatherImage::MostlySunny;
    }
    else if( iconTable == "03d" || iconTable == "03n" )
    {
        result = IconWeatherImage::cloud;
    }
    else if( iconTable == "04d" || iconTable == "04n" )
    {
        result = IconWeatherImage::brokenCloud;
    }
     else if( iconTable == "09d" || iconTable == "09n")
    {
        result = IconWeatherImage::ChanceRain;
    }
    else if( iconTable == "10d" || iconTable == "10n")
    {
        result = IconWeatherImage::rain;
    }
    else if( iconTable == "11d" || iconTable == "11n")
    {
        result = IconWeatherImage::Tstorms;
    }
    else if( iconTable == "13d" || iconTable == "13n")
    {
        result = IconWeatherImage::Snow;
    }
    else if( iconTable == "50d" )
    {
        result = IconWeatherImage::Haze;
    }
    else if( iconTable == "50n" )
    {
        result = IconWeatherImage::Fog;
    }
    else
    {
        result = IconWeatherImage::unkonwn;
    }
			// "01d": "wi-day-sunny",
			// "02d": "wi-day-cloudy",
			// "03d": "wi-cloudy",
			// "04d": "wi-cloudy-windy",
			// "09d": "wi-showers",
			// "10d": "wi-rain",
			// "11d": "wi-thunderstorm",
			// "13d": "wi-snow",
			// "50d": "wi-fog",
			// "01n": "wi-night-clear",
			// "02n": "wi-night-cloudy",
			// "03n": "wi-night-cloudy",
			// "04n": "wi-night-cloudy",
			// "09n": "wi-night-showers",
			// "10n": "wi-night-rain",
			// "11n": "wi-night-thunderstorm",
			// "13n": "wi-night-snow",
			// "50n": "wi-night-alt-cloudy-windy"

    return result;
}

void ControllerModuleWeather::UpdateData(UtilAbstractMem* memories)
{   
    if(nullptr != memories)    m_memories = memories;
    GetServerData(m_forecastURL);
}

void ControllerModuleWeather::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}
#define WEATHERSTARTADDRESS 0
void ControllerModuleWeather::SaveDatas(UtilAbstractMem* ) 
{
    if(nullptr == m_memories) return;
    Serial.print("[WEATHER] Save to fram, TemperatureOut: " );  
    Serial.print(m_dataWeather->TemperatureOut);
    Serial.println("° C");
    Serial.print(m_dataWeather->weekWeather[2].TemperatureMax);
    Serial.println("° C");
    // m_memories->WriteDouble(WEATHERSTARTADDRESS, m_dataWeather->TemperatureOut);
    ((UtilFramMem*)m_memories)->writeBlock<DataViewWeather>(WEATHERSTARTADDRESS, *m_dataWeather);
    //WriteDouble(m_frameI2C, WEATHERSTARTADDRESS, m_dataWeather->TemperatureOut);
}

// int ControllerModuleWeather::WriteDouble(Adafruit_FRAM_I2C* frameI2C, int address, double value) 
// {
//     int newStartAddress = address;
//     byte* doublePtr= (byte*) &value;
//     for (int i = 0 ; i < 2 ; i++) 
//     {
//         frameI2C->write8( newStartAddress, doublePtr[i] ); 
//         newStartAddress += 1;
//     }
//     return newStartAddress;
// }

void ControllerModuleWeather::LoadDatas(UtilAbstractMem* ) 
{
    if(nullptr == m_memories) return;
    // m_memories->ReadDouble(WEATHERSTARTADDRESS, m_dataWeather->TemperatureOut);    
    Serial.print("[WEATHER] Load from fram, TemperatureOut: \n"); 
    Serial.print(m_dataWeather->TemperatureOut);
    Serial.println("° C"); 
    Serial.print(m_dataWeather->weekWeather[2].TemperatureMax);
    Serial.println("° C");
    ((UtilFramMem*)m_memories)->readBlock<DataViewWeather>(WEATHERSTARTADDRESS, *m_dataWeather);
}

// void ControllerModuleWeather::SaveDataToEEPROM()
// {

// }
