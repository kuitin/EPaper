#include <Modules/Image/ControllerModuleImage.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Modules/Utils/UtilTime.h>
#include <Modules/Utils/UtilGoogle.h>

ControllerModuleImage::ControllerModuleImage (const ModuleDimmensions & dimensions, const String & imageUrl) :
    m_imageUrl(imageUrl)
{
    m_view = new DisplayModuleImage(dimensions, &m_viewData);
}


void ControllerModuleImage::UpdateData()
{
    bool isOK = GetDataFromGoogle();
    int counter = 0;
    while(!isOK && counter < 5)
    {
        isOK = GetDataFromGoogle();
        counter ++;
    }   
}

bool ControllerModuleImage::GetDataFromGoogle()
{
    int endPos = 0;
    String fileName = "";
    bool isFinished = false;
    String error;
    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
    String urlParams = "";
    int imageIndex = 0;
    while(isFinished == false)
    {
        String result = UtilGoogle::GetDataGoogleScript(m_imageUrl + urlParams, error);
        DynamicJsonBuffer jsonBuffer(capacity);
        //Serial.println(result);
        JsonObject& root = jsonBuffer.parseObject(result);
        if (!root.success()) {
            Serial.println(F("Parsing failed!"));
            return false;
        }
        fileName = root["filename"].as<String>();
        endPos = root["endPos"].as<int>();
        isFinished = root["isFinished"].as<bool>();
        m_viewData.width = root["width"].as<int>();
        m_viewData.height = root["height"].as<int>();
        if(imageIndex == 0)
        {
            m_viewData.freeArray();
            m_viewData.image_data = new uint8_t[root["length"].as<int>()];
        }
        JsonArray& arrayCalendar = root["list"].as<JsonArray&>();

        for(JsonVariant currentJson : arrayCalendar) { 
            String currentHexValue = currentJson.as<String>();
            const char* hexValue = currentHexValue.c_str();
            int hexToChar = hexValue[2] > 0x39 ? ((hexValue[2] - 'a') * 16 + 160) : (hexValue[2] - '0') * 16;
            hexToChar += hexValue[3] > 0x39 ? (hexValue[3] - 'a' + 10) : (hexValue[3] - '0');
            m_viewData.image_data[imageIndex] = hexToChar;
            imageIndex ++;
        }  
        if(!isFinished)
        {
            urlParams = String("{\"filename\":") +String("\"")+ fileName + String("\"") + String(",\"endPos\":") + String(endPos) + String("}") ;
        }
        //Serial.println("");
       // Serial.println(result);
    }    
}

void ControllerModuleImage::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}