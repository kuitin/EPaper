#include "DisplayEPaper.h"

DisplayEPaper::DisplayEPaper(char CS, char DC, char RST)
{
    m_io = new GxIO_Class(SPI, CS, DC, RST); 
}

void DisplayEPaper::TestAddNewTimeLineModule()
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

void DisplayEPaper::AddNewClockModule(int cornerThickness, int width, int height, bool updateTime)
{
    DisplayModule* currentModule = new DisplayModuleClock(cornerThickness, width, height, updateTime);
    m_modules.push_back(currentModule);
}

void DisplayEPaper::AddNewTimeLineModule(const std::vector<DateContent>& data)
{
    DisplayModule* currentModule = new DisplayModuleTimeLine(1537387581, 5256000, data);
    m_modules.push_back(currentModule);
}

void DisplayEPaper::AddNewModule(DisplayModule* currentModule)
{
	m_modules.push_back(currentModule);
}



