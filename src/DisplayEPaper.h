#ifndef _DisplayEPaper_H_
#define _DisplayEPaper_H_

#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <Modules/TimeLine/ControllerModuleTimeline.h>
#include "Modules/Clock/ControllerModuleClock.h"
#include "Modules/Weather/DisplayModuleWeather.h"
#include <vector>
#define PRINT_LOG
#include "LogInterface.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "Modules/Weather/ControllerModuleWeather.h"

class DisplayEPaper 
{
	public:
	DisplayEPaper(char CS, char DC, char RST);
	virtual void Init();
	//virtual void InitWithLog(int logLevel, Print *output);
	virtual void AddNewModule(ControllerModule* currentModule);
	virtual void TestAddNewTimeLineModule(const String & calendarUrl);
	virtual void TestAddNewWeatherModule(const String & forecastURL);
	virtual	void AddNewClockModule(int cornerThickness, int width, int height,bool updateTime);
	virtual void DrawModules() = 0;
	virtual void UpdateAllDatas();
	virtual void UpdateAllViewwDatas();
	virtual bool NeedUpdateScreen();

	private:

	protected :
	GxEPD* m_GxEPD;
	GxIO_Class* m_io;
	std::vector<ControllerModule*> m_modules;
};

#endif

