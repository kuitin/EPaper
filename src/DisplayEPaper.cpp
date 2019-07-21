#include "DisplayEPaper.h"

DisplayEPaper::DisplayEPaper(char CS, char DC, char RST)
{
    m_io = new GxIO_Class(SPI, CS, DC, RST); 
}

void DisplayEPaper::Init()
{
}

// void DisplayEPaper::InitWithLog(int logLevel, Print *output)
// {
//     LogInterface.begin(logLevel, output);
// }

void DisplayEPaper::TestAddNewTimeLineModule(const String & calendarUrl)
{
    ControllerModuleTimeline* currentModule = new ControllerModuleTimeline(calendarUrl);
    AddNewModule(currentModule);
}

void DisplayEPaper::TestAddNewWeatherModule(const String & forecastURL)
{    
    ControllerModuleWeather* currentModule = new ControllerModuleWeather(forecastURL);
    AddNewModule(currentModule);
}


void DisplayEPaper::AddNewClockModule(int cornerThickness, int width, int height, bool updateTime)
{
    ControllerModuleClock* currentModule = new ControllerModuleClock(
                                            ModuleDimmensions(width, height, cornerThickness), updateTime);
    AddNewModule(currentModule);
}

void DisplayEPaper::AddNewModule(ControllerModule* currentModule)
{
	m_modules.push_back(currentModule);
}

void DisplayEPaper::UpdateAllDatas()
{
    for (ControllerModule* module : m_modules) // Problem part
    {
        module->UpdateData();
    }
}

void DisplayEPaper::UpdateAllViewwDatas()
{
    for (ControllerModule* module : m_modules) // Problem part
    {
        module->UpdateDataView();
    }
}

bool DisplayEPaper::NeedUpdateScreen()
{
    bool needUpdate = false;
    for (ControllerModule* module : m_modules) // Problem part
    {
        needUpdate |= module->NeedUpdate();
        module->ResetFlagNewData();
    }
    return needUpdate;
}

void DisplayEPaper::TestAddNewImageModule(int cornerThickness, int width, int height, const String & imageUrl)
{
    ControllerModuleImage* currentModule = new ControllerModuleImage(ModuleDimmensions(width, height, cornerThickness),
                                                                    imageUrl);
    AddNewModule(currentModule);
}
