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

// Declare Fram memory
//Adafruit_FRAM_I2C fram     = Adafruit_FRAM_I2C(); (optionnal)


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
  // Initialise Fram.(optionnal)
  /*   if (fram.begin()) {  // you can stick the new i2c addr in here, e.g. begin(0x51);
    Serial.println("Found I2C FRAM");
  } else {
    Serial.println("I2C FRAM not identified ... check your connections?\r\n");
    Serial.println("Will continue in case this processor doesn't support repeated start\r\n");
  }*/

  
  // Initialise E-Paper.
  displaya.Init();
  Serial.println("setup done");
}


void loop() {
  // Set Fram memory
  //displaya.setFramMemory(&fram); // (optionnal)

  // Compute view to display weather
  displaya.TestAddNewTimeLineModule("Link to your server to collect Json");
  
  // Please update your Weather Identifier and city identifier in the following URL.
  ControllerModuleWeather* currentModule = new ControllerModuleWeather("http://api.openweathermap.org/data/2.5/forecast?id=YOURCITY&APPID=YOURTOKENID");
  displaya.AddNewModule(currentModule);
  // update Air quality
  currentModule->SeteCO2(400); 
  currentModule->SetTVOC(0);
  // Update humidity and temperature
  currentModule->SetTemperatureIn( 20);
  currentModule->SetHumidity(50);
  
  Serial.println("Compute pixel position for Clock");
  displaya.AddNewClockModule(1,224,120, false);

  displaya.TestAddNewImageModule(1,224,384, "Link to your server to collect Json"); // note: Image width max 223 pixel
	
  // Update all data fo each module
  displaya.UpdateAllDatas();
   
  // Update View
  Serial.println("Refresh E-paper view");
  displaya.DrawModules();

  while(1)
  {
    delay(1000);
  }
  
}
