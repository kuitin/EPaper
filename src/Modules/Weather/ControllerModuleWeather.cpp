#include <Modules/Weather/ControllerModuleWeather.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

ControllerModuleWeather::ControllerModuleWeather (const String & forecastURL) :
    m_forecastURL(forecastURL) ,
    m_flagNeedUpdate(false)
{
    m_dataWeather = new DataViewWeather();
    m_view = new DisplayModuleWeather(m_dataWeather);
}


void ControllerModuleWeather::GetServerData(String forecastURL, DataViewWeather& data)
{
       HTTPClient http;

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
                double humidity = arrayWeather[0]["main"]["humidity"].as<double>();
                data.TemperatureOut = arrayWeather[0]["main"]["temp"].as<double>() - 273.15;
              
                // Extract values
                Serial.println(F("Response:"));
                Serial.print("humidity: ");Serial.println(humidity,3);
                Serial.print("temperature: ");Serial.println(data.TemperatureOut, 3);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
}

void ControllerModuleWeather::UpdateData()
{
    m_dataWeather->TemperatureIn = 20;
    m_dataWeather->TemperatureOut = 12;
    m_dataWeather->Pression = 1013;
    m_dataWeather->weather = DataViewWeather::cloud;
    GetServerData(m_forecastURL, *m_dataWeather);
}

void ControllerModuleWeather::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}