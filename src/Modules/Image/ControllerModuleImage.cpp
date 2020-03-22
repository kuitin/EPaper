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
const char dayStr0a[] PROGMEM = "Sunday";
const char dayStr1a[] PROGMEM = "Monday";
const char dayStr2a[] PROGMEM = "Tuesday";
const char dayStr3a[] PROGMEM = "Wednesday";
const char dayStr4a[] PROGMEM = "Thursday";
const char dayStr5a[] PROGMEM = "Friday";
const char dayStr6a[] PROGMEM = "Saturday";

const PROGMEM char * const PROGMEM dayNames_Pa[] =
{
   dayStr0a,dayStr1a,dayStr2a,dayStr3a,dayStr4a,dayStr5a,dayStr6a
};

void ControllerModuleImage::UpdateData(UtilAbstractMem* memories)
{
    if(nullptr != memories)    m_memories = memories;
    bool isOK = GetDataFromGoogle();
    int counter = 0;
    while(!isOK && counter < 5)
    {
        isOK = GetDataFromGoogle();
        counter ++;
    }   
    if( isOK )
    {
        SaveDatas( m_memories );
    }
    else
    {
        LoadDatas( m_memories );
    }
    bool isDSTEnable = false;
    unsigned long currentTime = UtilTime::GetTime(isDSTEnable);
    tmElements_t newTimeDate;
    struct tm timeinfo;
    getLocalTime(&timeinfo);
    breakTime(currentTime + isDSTEnable*3600, newTimeDate);
    m_viewData.dayNumber = timeinfo.tm_mday;
    m_viewData.dayName = dayNames_Pa[timeinfo.tm_wday];
    m_viewData.month = monthStr(timeinfo.tm_mon);
    m_viewData.year = timeinfo.tm_year;
    m_viewData.hour = timeinfo.tm_hour;
    m_viewData.minute = timeinfo.tm_min;
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
        m_viewData.length = root["length"].as<int>();
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

#define IMAGETARTADDRESS 3100
void ControllerModuleImage::SaveDatas(UtilAbstractMem* ) 
{
    if(nullptr == m_memories) return;    
    // Serial.print("[Timeline] Save datas to fram: \n"); 
  // TODO probleme memoire avec la meteo qui en utilise trop enqueter sur le weather.
    uint32_t framAddresss = IMAGETARTADDRESS;
    framAddresss = m_memories->WriteBool(framAddresss, true );
    framAddresss = m_memories->writeInt(framAddresss, m_viewData.length);
    framAddresss = m_memories->writeInt(framAddresss, m_viewData.width);
    framAddresss = m_memories->writeInt(framAddresss, m_viewData.height);
    for(int itrCount = 0;  itrCount < m_viewData.length ; itrCount ++ )
    {
        framAddresss = m_memories->write8(framAddresss, m_viewData.image_data[itrCount]);
    }

     Serial.print("[ControllerModuleImage] END ***** Save eventCount : ");
}

void ControllerModuleImage::LoadDatas(UtilAbstractMem* ) 
{
    if(nullptr == m_memories) return;    
    uint32_t framAddresss = IMAGETARTADDRESS;
    bool isDataExist = false;
    framAddresss = m_memories->ReadBool(framAddresss, isDataExist);
    if(!isDataExist)
    {
        return;
    }
    framAddresss = m_memories->readInt(framAddresss, m_viewData.length);
    framAddresss = m_memories->readInt(framAddresss, m_viewData.width);
    framAddresss = m_memories->readInt(framAddresss, m_viewData.height);
    if(m_viewData.image_data != nullptr)
    {
        delete m_viewData.image_data;
        m_viewData.image_data = nullptr;
    }
    m_viewData.image_data = new uint8_t[m_viewData.length];
    for(int itrCount = 0;  itrCount < m_viewData.length ; itrCount ++ )
    {
        framAddresss = m_memories->read8(framAddresss, m_viewData.image_data[itrCount]);
    }
}