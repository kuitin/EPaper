#ifndef _DisplayEPaper_H_
#define _DisplayEPaper_H_

#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <Modules/TimeLine/DisplayModuleTimeLine.h>
#include "Modules/Clock/DisplayModuleClock.h"
#include "Modules/Weather/DisplayModuleWeather.h"
#include <vector>
#define PRINT_LOG
#include "LogInterface.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

class DisplayEPaper 
{
	public:
	DisplayEPaper(char CS, char DC, char RST);
	virtual void Init();
	//virtual void InitWithLog(int logLevel, Print *output);
	virtual void AddNewModule(DisplayModule* currentModule);
	virtual void TestAddNewTimeLineModule();
	virtual void TestAddNewWeatherModule(const String & forecastURL);
	virtual	void AddNewClockModule(int cornerThickness, int width, int height,bool updateTime);
	virtual void AddNewTimeLineModule(const std::vector<DateContent>& data);
	virtual void DrawModules() = 0;

	private:
	virtual void GetServerData(String forecastURL, DataWeather& data);

	protected :
	GxEPD* m_GxEPD;
	GxIO_Class* m_io;
	std::vector<DisplayModule*> m_modules;
};

#endif

