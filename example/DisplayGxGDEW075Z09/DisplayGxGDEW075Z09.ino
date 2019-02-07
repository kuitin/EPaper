#include <DisplayEPaper.h>
#include <DisplayGxGDEW075Z09/DisplayGxGDEW075Z09.h>
#include <WiFi.h>
#include <WiFiMulti.h>

//Config Pin of Epaper
static const int8_t cs = 17;
static const int8_t dc = 16;
static const int8_t rst = 5;
static const int8_t busy = 19;
EPaper_Class displaya(cs,dc,rst,busy);
WiFiMulti wifiMulti;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initialize Wifi and E-Paper");
  // Initialise Wifi
  // Please set the ID of your wifi and Key.
   wifiMulti.addAP("ID-WIFI", "KEY-WIFI");
   if((wifiMulti.run() != WL_CONNECTED)) {
    Serial.print("No wifi\n");
   }
  // Initialise E-Paper.
  displaya.Init();
  Serial.println("setup done");
}


void loop() {
  
  Serial.println("Compute pixel position for time line");
  displaya.TestAddNewTimeLineModule();
  Serial.println("Compute pixel position for wheather");
  // Please update your Weather Identifier and city identifier in the following URL.
  displaya.TestAddNewWeatherModule("http://api.openweathermap.org/data/2.5/forecast?id=YOURCITY&APPID=YOURTOKENID");
  Serial.println("Compute pixel position for Clock");
  displaya.AddNewClockModule(1,100,100, false);

  Serial.println("Refresh E-paper view");
  displaya.DrawModules();

  while(1)
  {
    delay(1000);
  }
  
}