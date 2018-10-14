#include "DisplayGxGDEW075Z09.h"

 #include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
 #include <GxIO/GxIO.cpp>
 #include <GxGDEW075Z09/GxGDEW075Z09.cpp>      // 7.5" b/w/r
 #include <DisplayModule.h>
// FreeFonts from Adafruit_GFX
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold24pt7b.h>
DisplayGxGDEW075Z09::DisplayGxGDEW075Z09(char CS, char DC, char RST, char Busy):DisplayEPaper( CS,  DC,  RST)
{
    m_GxEPD = new GxGDEW075Z09(*m_io, RST, Busy);    
}

void DisplayGxGDEW075Z09::Init()
{
	GxGDEW075Z09* currentcontext = reinterpret_cast<GxGDEW075Z09*>(m_GxEPD);
    m_GxEPD->init();
}

void DisplayGxGDEW075Z09::AddNewModule(DisplayModule* currentModule)
{
	m_modules.push_back(currentModule);
}

void DisplayGxGDEW075Z09::AddNewClockModule(int cornerThickness, int width, int height, bool updateTime)
{
    DisplayModule* currentModule = new DisplayModuleClock(cornerThickness, width, height, updateTime);
    m_modules.push_back(currentModule);
}

void DisplayGxGDEW075Z09::AddNewTimeLineModule(const std::vector<DateContent>& data)
{
    DisplayModule* currentModule = new DisplayModuleTimeLine(1537387581, 5256000, data);
    m_modules.push_back(currentModule);
}

void DisplayGxGDEW075Z09::TestAddNewTimeLineModule()
{
   // Date currentDate;   
    std::vector<DateContent> data;
    DateContent tempData {1537387991,"hello123456789123456777777"};
    DateContent tempData2 {1537647210,"hello"};
    data.push_back(tempData);
    data.push_back(tempData2);
    DisplayModule* currentModule = new DisplayModuleTimeLine(1537387581, 5256000, data);
    m_modules.push_back(currentModule);
}


void DisplayGxGDEW075Z09::DrawModules()
{
    GxGDEW075Z09* currentcontext = reinterpret_cast<GxGDEW075Z09*>(m_GxEPD);
    if(nullptr != currentcontext)
    {
        //currentcontext->fillScreen(GxEPD_WHITE);
        Point positionNextModule;
        const GFXfont* f = &FreeMonoBold9pt7b;
        //currentcontext->updateWindow(0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, false);
        // currentcontext->fillScreen(GxEPD_WHITE);
        // currentcontext->setTextColor(GxEPD_BLACK);
        // currentcontext->setFont(f);
        // currentcontext->setCursor(0, 50 );
        //  currentcontext->println();
        // currentcontext->setTextSize(5);
        // currentcontext->println("12:25");
         
        for (auto& module : m_modules) // Problem part
        {  
            if(GxGDEW075Z09_WIDTH < (positionNextModule.x + module->GetThickness() + module->GetWidth())) 
            {
                // Change Line
                positionNextModule.y += module->GetHeight();
                positionNextModule.x = 0;
            }   
            currentcontext->setCursor(positionNextModule.x, positionNextModule.y);
            currentcontext->drawRect(positionNextModule.x, positionNextModule.y, module->GetWidth(), module->GetHeight(), GxEPD_BLACK);
            // Update relative position:
            module->UpdateRelativePos(positionNextModule.x + module->GetThickness(), positionNextModule.y);
            module->FillModule(*currentcontext);

            // Compute next position of the module
           
            positionNextModule.x += module->GetWidth();            
        }
        
        // currentcontext->fillRect(0, 0, 8, 8, GxEPD_BLACK);
        // currentcontext->fillRect(currentcontext->width() - 18, 0, 16, 16, GxEPD_BLACK);
        // currentcontext->fillRect(currentcontext->width() - 25, currentcontext->height() - 25, 24, 24, GxEPD_BLACK);
        // currentcontext->fillRect(0, currentcontext->height() - 33, 32, 32, GxEPD_BLACK);
        currentcontext->updateWindow(0,0, GxEPD_WIDTH, GxEPD_HEIGHT,  true);
        //currentcontext->update();
    }
}