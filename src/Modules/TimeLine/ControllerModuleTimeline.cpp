#include <Modules/TimeLine/ControllerModuleTimeline.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <TimeLib.h> 
#include "WiFiClientSecure.h"

ControllerModuleTimeline::ControllerModuleTimeline (const String& calandarUrl) :
    m_flagNeedUpdate(false),
    m_calandarUrl(calandarUrl)
{
    m_dataView = new DataViewTimeline();
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
    unsigned long currentTime = GetTime();
    if(currentTime != 0)
    {
        ParseGoogleCalendar();
        // std::vector<DateContent> data;
        // DateContent tempData {currentTime +100,"hello123456789123456777777"};
        // DateContent tempData2 {currentTime + 200,"hello"};
        // m_dataView->listEvent.push_back(tempData);
        // m_dataView->listEvent.push_back(tempData2);
        // Get Time from server
        m_dataView->currentDate = currentTime;
        m_dataView->period = 5256000;
    }
}

void ControllerModuleTimeline::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;
unsigned long  ControllerModuleTimeline::GetTime()
{
    unsigned long result = 0;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return 0;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    time_t now;

    time(&now);
    Serial.println(now);
    return now;
}
 
const char*  server = "script.google.com";  // Server URL
// google script key
const char* key = "AKfycby0T0QaLhodlDRiBNyYSWYwq9bNM-Y17YrzFVeZ8V6im9FL42c"; 
WiFiClientSecure client;
void ControllerModuleTimeline::ParseGoogleCalendar()
{


    String movedURL;
    String line;

    if (1)Serial.println("Verbinde zum script.google.com");
    if (!client.connect(server, 443))
    {
        if (1) Serial.println("Verbindung fehlgeschlagen!");
        return;
    }

    if (1) Serial.println("Verbunden!");
    // ESP32 Erzeugt HTTPS Anfrage an Google sheets
    client.println("GET " + m_calandarUrl );
    client.println("Host: script.google.com" );
    client.println("Connection: close");
    client.println();

     // ESP32 empfängt antwort vom Google sheets
  while (client.connected())     // ESP32  empfängt Header
  {
    line = client.readStringUntil('\n');
    if (1) Serial.println(line);
//    if (line == "\r") return;      // Ende Des Headers empfangen
    if (line.indexOf ( "Location" ) >= 0)   // Weiterleitung im Header?
    { // Neue URL merken
      movedURL = line.substring ( line.indexOf ( ":" ) + 2 ) ;
     
    }
    
  }
  Serial.println("movedURL");
    Serial.println(movedURL);

//   while (client.connected())    // Google Antwort HTML Zeilenweise Lesen
//   {
//     if (client.available())
//     {
//       line = client.readStringUntil('\r');
//       if (1) Serial.print(line);
//     }
//   }
  client.stop();

  movedURL.trim(); // leerzeichen, \n entfernen
  if (1) Serial.println("Weiterleitungs URL: \"" + movedURL + "\"");

//   if (movedURL.length() < 10) return; // Weiterleitung nicht da

  if (1) Serial.println("\n Starte Weiterleitung...");
  if (!client.connect(server, 443))
  {
    if (1) Serial.println("Weiterleitung fehlgeschlagen!");
    return;
  }

  Serial.println("Verbunden!");
  // // ESP32 Erzeugt HTTPS Anfrage an Google Tabellen
  client.println("GET " + movedURL );
  client.println("Host: script.google.com");
  client.println("Connection: close");
  client.println();
    Serial.print("END ------------ END");
  while (client.connected()) // ESP32  empfängt Header
  {
    line = client.readStringUntil('\n');
    if (1) Serial.println(line);
    if (line == "\r")break;
  }
  
  while (client.connected()) // Google Antwort HTML Zeilenweise Lesen
  {
    if (client.available())
    {
      line = client.readStringUntil('\r');
      const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
      DynamicJsonBuffer jsonBuffer(capacity);
      JsonObject& root = jsonBuffer.parseObject(line);
      if (!root.success()) {
          Serial.println(F("Parsing failed!"));
          return;
      }
      JsonArray& arrayCalendar = root["list"].as<JsonArray&>();
      for(JsonVariant currentJson : arrayCalendar) { 

          DateContent tempData {currentJson["startTime"].as<unsigned int>(),
                                currentJson["title"].as<String>()};
          m_dataView->listEvent.push_back(tempData);
      }
      client.stop();
      if (1) Serial.print(line);
    }
  }
  client.stop();
  Serial.print("client stop");
}