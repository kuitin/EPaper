#ifndef _DisplayEPaper_H_
#define _DisplayEPaper_H_

#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <DisplayModuleTimeLine.h>
#include <DisplayModule.h>
#include "DisplayModuleClock.h"
#include "DisplayModuleWeather.h"
#include <vector>
class DisplayEPaper 
{
	public:
	DisplayEPaper(char CS, char DC, char RST);
	virtual void AddNewModule(DisplayModule* currentModule);
	virtual void TestAddNewTimeLineModule();
	virtual void TestAddNewWeatherModule();
	virtual	void AddNewClockModule(int cornerThickness, int width, int height,bool updateTime);
	virtual void AddNewTimeLineModule(const std::vector<DateContent>& data);
	virtual void DrawModules() = 0;

	protected :
	GxEPD* m_GxEPD;
	GxIO_Class* m_io;
	std::vector<DisplayModule*> m_modules;
};

#endif

