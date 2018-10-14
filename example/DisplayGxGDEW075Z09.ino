#include <DisplayGxGDEW075Z09.h>
//Config Pin of Epaper
static const int8_t cs = 17;
static const int8_t dc = 16;
static const int8_t rst = 5;
static const int8_t busy = 19;
DisplayGxGDEW075Z09 displaya(cs,dc,rst,busy);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  displaya.Init();
  Serial.println("setup done");
}


void loop() {
  // put your main code here, to run repeatedly:
   Serial.println("init");
  
   Serial.println("draw");
 

  
  
//  displaya.AddNewClockModule(1,100,100, false);
  
  
//  displaya.DrawModules();
    Serial.println("endDraw 1");
  displaya.TestAddNewTimeLineModule();
  displaya.AddNewClockModule(1,100,100, false);
 // displaya.AddNewClockModule(1,100,100, true);
  displaya.DrawModules();
    Serial.println("endDraw 2");

  while(1)
  {
    delay(1000);
  }
  
}
