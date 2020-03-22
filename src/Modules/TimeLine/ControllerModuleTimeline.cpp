#include <Modules/TimeLine/ControllerModuleTimeline.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <TimeLib.h> 
#include "WiFiClientSecure.h"
#include <Modules/Utils/UtilTime.h>

ControllerModuleTimeline::ControllerModuleTimeline (const String& calandarUrl, int utc) :
    m_flagNeedUpdate(false),
    m_calandarUrl(calandarUrl),
    m_Utc(utc)
{
    m_dataView = new DataViewTimeline();
    m_dataView->utc = utc;
    m_view = new DisplayModuleTimeLine(m_dataView);
    
}

ControllerModuleTimeline::~ControllerModuleTimeline()
{
    if(m_dataView)
    {
        delete m_dataView;
        m_dataView = nullptr;
    }
}


void ControllerModuleTimeline::UpdateData(UtilAbstractMem* memories)
{
    if(nullptr != memories)    m_memories = memories;
    bool m_isDSTEnable;
    unsigned long currentTime = UtilTime::GetTime(m_isDSTEnable);
    m_dataView->m_isDSTEnable = m_isDSTEnable;
    if(currentTime != 0)
    {
        bool isOk = ParseGoogleCalendar();
        if(!isOk) isOk = ParseGoogleCalendar();
        if(!isOk) 
        {
            LoadDatas(m_memories);
        }
        else
        {
            SaveDatas(m_memories);
        }
        m_dataView->currentDate = currentTime;
        m_dataView->period = 5256000;
    }
}

void ControllerModuleTimeline::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}


 
const char*  server = "script.google.com";  // Server URL
// google script key
const char* key = "AKfycby0T0QaLhodlDRiBNyYSWYwq9bNM-Y17YrzFVeZ8V6im9FL42c"; 
WiFiClientSecure client;
bool ControllerModuleTimeline::ParseGoogleCalendar()
{

    String movedURL;
    String line;

    // if (1)Serial.println("Connection to script.google.com");
    if (!client.connect(server, 443))
    {
        if (1) Serial.println("Connection to server failed!");
        return false;
    }

    // if (1) Serial.println("Connecté!");
    // ESP32 Erzeugt HTTPS Anfrage an Google sheets
    client.println("GET " + m_calandarUrl );
    client.println("Host: script.google.com" );
    client.println("Connection: close");
    client.println();

     // ESP32 empfängt antwort vom Google sheets
  int timeout = 0;
  int maxTimeout = 25;
  while (client.connected() && timeout < maxTimeout )     // ESP32  empfängt Header
  {
    line = client.readStringUntil('\n');
    // if (1) Serial.println(line);
   if (line == "\r") break;      // Ende Des Headers empfangen
    if (line.indexOf ( "Location" ) >= 0)   // Weiterleitung im Header?
    { // Neue URL merken
      movedURL = line.substring ( line.indexOf ( ":" ) + 2 ) ;
     
    }
    Serial.println(timeout);
    timeout++;
    
  }
  if(timeout >= maxTimeout) 
  {
    Serial.println(" out 1");
    client.stop();
    return false;
  }
  timeout = 0;
  client.stop();
  if(timeout >= maxTimeout) 
  {
    Serial.println("2");
     return false;
  }

  movedURL.trim(); // leerzeichen, \n entfernen

  if (!client.connect(server, 443))
  {
    if (1) Serial.println("Connection to server failed!");
    return false;
  }

  // // ESP32 Erzeugt HTTPS Anfrage an Google Tabellen
  client.println("GET " + movedURL );
  client.println("Host: script.google.com");
  client.println("Connection: close");
  client.println();
  // Serial.print("END ------------ END");
  timeout = 0;
  while (client.connected() && timeout < maxTimeout) // ESP32  empfängt Header
  {
    line = client.readStringUntil('\n');
    if (line == "\r")break;
    Serial.println(timeout);
    timeout ++;
  }
  if(timeout >= maxTimeout) 
  {
    Serial.println("3");
    client.stop();
    return false;
  }
  
   timeout = 0;
  while (client.connected() && timeout < maxTimeout) // Google Antwort HTML Zeilenweise Lesen
  {
    if (client.available())
    {
      line = client.readStringUntil('\r');
      const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
      DynamicJsonBuffer jsonBuffer(capacity);
      JsonObject& root = jsonBuffer.parseObject(line);
      if (!root.success()) {
          Serial.println(F("Parsing failed!"));
          return false;
      }
      JsonArray& arrayCalendar = root["list"].as<JsonArray&>();
      for(JsonVariant currentJson : arrayCalendar) { 

          DateContent tempData {currentJson["startTime"].as<unsigned int>(),
                                currentJson["endTime"].as<unsigned int>(),
                                currentJson["title"].as<String>(),
                                currentJson["isAllDay"].as<bool>()};
          m_dataView->listEvent.push_back(tempData);
      }      
      client.stop();
      // if (1) Serial.print(line);
    }
    timeout ++;
  }
  if(timeout >= maxTimeout) 
  {
    Serial.println("google timeout");
    client.stop();
    return false;
  }
  client.stop();
  return true;
  // Serial.print("client stop");
}

#define WEATHERSTARTADDRESS 400
void ControllerModuleTimeline::SaveDatas(UtilAbstractMem* ) 
{
    if(nullptr == m_memories) return;    
    // Serial.print("[Timeline] Save datas to fram: \n"); 
  // TODO probleme memoire avec la meteo qui en utilise trop enqueter sur le weather.
    uint32_t framAddresss = WEATHERSTARTADDRESS;
    framAddresss = m_memories->WriteBool(framAddresss, m_dataView->m_isDSTEnable);
    // Serial.print("[Timeline] Save framAddresss : ");  Serial.print(framAddresss);  Serial.print(" \n");
    framAddresss = m_memories->writeInt(framAddresss, m_dataView->utc);
    // Serial.print("[Timeline] Save framAddresss : ");  Serial.print(framAddresss);  Serial.print(" \n");
    framAddresss = m_memories->writeInt(framAddresss, m_dataView->listEvent.size());
    // Serial.print("[Timeline] Save eventCount : ");  Serial.print( m_dataView->listEvent.size());  Serial.print(" \n");
    for(int itrCount = 0;  itrCount < m_dataView->listEvent.size(); itrCount ++ )
    {
        // Serial.print("[Timeline] Save line : ");  Serial.print(itrCount);  Serial.print(" \n ");
        const DateContent& currentData = m_dataView->listEvent[itrCount];

        framAddresss = m_memories->writeU32(framAddresss, currentData.startDate);
        framAddresss = m_memories->writeU32(framAddresss, currentData.endDate);
        framAddresss = m_memories->WriteBool(framAddresss, currentData.isAllDay);
        framAddresss = m_memories->WriteString2(framAddresss, currentData.eventDetails);

    }

     Serial.print("[Timeline] END ***** Save eventCount : ");
}

void ControllerModuleTimeline::LoadDatas(UtilAbstractMem* ) 
{
    if(nullptr == m_memories) return;    
    // Serial.print("[Timeline] Load from fram: \n"); 
    uint32_t framAddresss = WEATHERSTARTADDRESS;
    framAddresss = m_memories->ReadBool(framAddresss, m_dataView->m_isDSTEnable);
    // Serial.print("[Timeline] read framAddresss : ");  Serial.print(framAddresss);  Serial.print(" \n");
    // Serial.print("[Timeline] read m_dataView->m_isDSTEnable : ");  Serial.print(m_dataView->m_isDSTEnable);  Serial.print(" \n");
    framAddresss = m_memories->readInt(framAddresss, m_dataView->utc);
    // Serial.print("[Timeline] read framAddresss : ");  Serial.print(framAddresss);  Serial.print(" \n");
    // Serial.print("[Timeline] read m_dataView->utc : ");  Serial.print(m_dataView->utc);  Serial.print(" \n");
    int  eventCount = 0;
    framAddresss = m_memories->readInt(framAddresss, eventCount);
    // Serial.print("[Timeline] read eventCount : ");  Serial.print(eventCount);  Serial.print(" \n");
    for(int itrCount = 0;  itrCount < eventCount; itrCount ++ )
    {
        DateContent currentData ;
        // Serial.print("[Timeline] read line : ");  Serial.print(itrCount);  Serial.print(" \n ");
        framAddresss = m_memories->readU32(framAddresss, currentData.startDate);
        framAddresss = m_memories->readU32(framAddresss, currentData.endDate);
        framAddresss = m_memories->ReadBool(framAddresss, currentData.isAllDay);
        // Serial.print("framAddresss : ");  Serial.print(framAddresss);  Serial.print(" \n ");
        framAddresss = m_memories->ReadString2(framAddresss, currentData.eventDetails);
        Serial.print(currentData.eventDetails);  Serial.print(" \n ");
        // Serial.print("framAddresss: ");  Serial.print(framAddresss);  Serial.print(" \n ");

        m_dataView->listEvent.push_back(currentData);
    }
}