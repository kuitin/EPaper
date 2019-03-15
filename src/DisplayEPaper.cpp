#include "DisplayEPaper.h"

DisplayEPaper::DisplayEPaper(char CS, char DC, char RST)
{
    m_io = new GxIO_Class(SPI, CS, DC, RST); 
}

void DisplayEPaper::Init()
{
}

// void DisplayEPaper::InitWithLog(int logLevel, Print *output)
// {
//     LogInterface.begin(logLevel, output);
// }

void DisplayEPaper::TestAddNewTimeLineModule()
{
   // Date currentDate;   
    // std::vector<DateContent> data;
    // DateContent tempData {1540572729,"hello123456789123456777777"};
    // DateContent tempData2 {1540572729,"hello"};
    // data.push_back(tempData);
    // data.push_back(tempData2);
    // DisplayModule* currentModule = new DisplayModuleTimeLine(1537387581, 5256000, data);
    // m_modules.push_back(currentModule);
}

void DisplayEPaper::GetServerData(String forecastURL, DataViewWeather& data)
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

void DisplayEPaper::TestAddNewWeatherModule(const String & forecastURL)
{    
    // DataViewWeather data;
    // data.TemperatureIn = 20;
    // data.TemperatureOut = 12;
    // data.Pression = 1013;
    // data.weather = DataViewWeather::cloud;
    // GetServerData(forecastURL, data);
    // DisplayModule* currentModule = new DisplayModuleWeather(data);
    ControllerModuleWeather* currentModule = new ControllerModuleWeather(forecastURL);
    AddNewModule(currentModule);
}


void DisplayEPaper::AddNewClockModule(int cornerThickness, int width, int height, bool updateTime)
{
    // DisplayModule* currentModule = new DisplayModuleClock(cornerThickness, width, height, updateTime);
    // AddNewModule(currentModule);
}

void DisplayEPaper::AddNewTimeLineModule(const std::vector<DateContent>& data)
{
    // DisplayModule* currentModule = new DisplayModuleTimeLine(1537387581, 5256000, data);
    // AddNewModule(currentModule);
}

void DisplayEPaper::AddNewModule(ControllerModule* currentModule)
{
	m_modules.push_back(currentModule);
}

void DisplayEPaper::UpdateAllDatas()
{
    for (ControllerModule* module : m_modules) // Problem part
    {
        module->UpdateData();
    }
}

void DisplayEPaper::UpdateAllViewwDatas()
{
    for (ControllerModule* module : m_modules) // Problem part
    {
        module->UpdateDataView();
    }
}
