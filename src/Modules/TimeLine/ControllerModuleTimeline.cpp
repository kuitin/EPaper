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


void ControllerModuleTimeline::UpdateData()
{
    bool m_isDSTEnable;
    unsigned long currentTime = UtilTime::GetTime(m_isDSTEnable);
    m_dataView->m_isDSTEnable = m_isDSTEnable;
    if(currentTime != 0)
    {
        bool isOk = ParseGoogleCalendar();
        if(!isOk) isOk = ParseGoogleCalendar();
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