#include "DisplayGxGDEW075Z09/DisplayGxGDEW075Z09.h"

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

void DisplayGxGDEW075Z09::InitWithLog(int logLevel, Print *output)
{
   // DisplayEPaper::InitWithLog(logLevel, output);
   // LOG_DEBUG("INIT DisplayGxGDEW075Z09");
    GxGDEW075Z09* currentcontext = reinterpret_cast<GxGDEW075Z09*>(m_GxEPD);
    m_GxEPD->init();
}



void DisplayGxGDEW075Z09::DrawModules()
{
    GxGDEW075Z09* currentcontext = reinterpret_cast<GxGDEW075Z09*>(m_GxEPD);
    if(nullptr != currentcontext)
    {
        Point positionNextModule;
        const GFXfont* f = &FreeMonoBold9pt7b;

        for (ControllerModule* module : m_modules) // Problem part
        {
            DisplayModule* currentView = module->getView();
            if(currentView != nullptr)
            {
                if(module->PositionModule()  == ControllerModule::bottomMiddle)
                {
                    currentcontext->setCursor(positionNextModule.x, GxGDEW075Z09_HEIGHT - currentView->GetHeight());
                    currentcontext->drawRect(positionNextModule.x, GxGDEW075Z09_HEIGHT - currentView->GetHeight(), currentView->GetWidth(), currentView->GetHeight(), GxEPD_BLACK);
                    // Update relative position:
                    currentView->UpdateRelativePos(positionNextModule.x + currentView->GetThickness(), GxGDEW075Z09_HEIGHT - currentView->GetHeight());
                    //currentView->UpdateViewData(ModelData);
                    currentView->FillModule(*currentcontext);
                    // positionNextModule.x += currentView->GetWidth();
                    // positionNextModule.y += GxGDEW075Z09_HEIGHT- currentView->GetHeight();
                }
                else if(module->PositionModule()  == ControllerModule::topMiddle)
                {
                    currentcontext->setCursor(positionNextModule.x, positionNextModule.y);
                    currentcontext->drawRect(positionNextModule.x, positionNextModule.y, currentView->GetWidth(), currentView->GetHeight(), GxEPD_BLACK);
                    // Update relative position:
                    currentView->UpdateRelativePos(positionNextModule.x + currentView->GetThickness(), positionNextModule.y);
                    //currentView->UpdateViewData(ModelData);
                    currentView->FillModule(*currentcontext);
                    positionNextModule.x += currentView->GetWidth();
                    // positionNextModule.y += currentView->GetHeight();
                }
                else
                {       
                    if(GxGDEW075Z09_WIDTH < (positionNextModule.x + currentView->GetThickness() + currentView->GetWidth()))
                    {
                        // Change Line
                        positionNextModule.y += currentView->GetHeight();
                        positionNextModule.x = 0;
                    }
                    currentcontext->setCursor(positionNextModule.x, positionNextModule.y);
                    currentcontext->drawRect(positionNextModule.x, positionNextModule.y, currentView->GetWidth(), currentView->GetHeight(), GxEPD_BLACK);
                    // Update relative position:
                    currentView->UpdateRelativePos(positionNextModule.x + currentView->GetThickness(), positionNextModule.y);
                    //currentView->UpdateViewData(ModelData);
                    currentView->FillModule(*currentcontext);

                    // Compute next position of the module

                    positionNextModule.x += currentView->GetWidth();
                }
            }
        }

        currentcontext->updateWindow(0,0, GxEPD_WIDTH, GxEPD_HEIGHT,  true);
        //currentcontext->update();
    }
}