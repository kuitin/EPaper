#ifndef _DisplayModuleWeather_H_
#define _DisplayModuleWeather_H_
#include "Modules/DisplayModule.h"
#include "svg/header/wi-cloudy.h"
#include "svg/header/wi-cloud.h"
#include "svg/header/wi-hail.h"
#include "svg/header/wi-day-sunny.h"
#include "svg/header/wi-alien.h"
#include "svg/header/wi-day-fog.h"
#include "svg/header/wi-day-haze.h"
#include "svg/header/wi-day-lightning.h"
#include "svg/header/wi-day-rain-mix.h"
#include "svg/header/wi-day-snow.h"
#include "svg/header/wi-rain.h"
#include "svg/header/wi-day-cloudy.h"

#include "svg/headerLowDef/wi-cloudy.h"
#include "svg/headerLowDef/wi-cloud.h"
#include "svg/headerLowDef/wi-hail.h"
#include "svg/headerLowDef/wi-day-sunny.h"
#include "svg/headerLowDef/wi-alien.h"
#include "svg/headerLowDef/wi-day-fog.h"
#include "svg/headerLowDef/wi-day-haze.h"
#include "svg/headerLowDef/wi-day-lightning.h"
#include "svg/headerLowDef/wi-day-rain-mix.h"
#include "svg/headerLowDef/wi-day-snow.h"
#include "svg/headerLowDef/wi-rain.h"
#include "svg/headerLowDef/wi-day-cloudy.h"

#include <Modules/Utils/UtilTime.h>

#include "Modules/DisplayModuleCommunicationWifi.h"

#define MAX_DAY_WEATHER 5
class IconWeatherImage 
{
    public:
    enum IconWeater
    {
        MostlySunny,
        cloud,
        brokenCloud,
        ChanceRain,
        rain,
        sun,
        Tstorms,
        Snow,
        Haze,
        Fog,
        none,
        unkonwn
    };
};

class DataViewWeatherOfFullDay 
{
 public:
    double TemperatureMin;
    double TemperatureMax;
    IconWeatherImage::IconWeater weatherMorning;
    IconWeatherImage::IconWeater weatherAfternoon;
    DAY_OF_WEEK DayOfWeek;
};

class DataViewWeather 
{
    public:
    double TemperatureIn;
    double TemperatureOut;
    double Pression;
    IconWeatherImage::IconWeater weather;
    DataViewWeatherOfFullDay weekWeather [MAX_DAY_WEATHER];
    DataViewWeather(): TemperatureIn(0),TemperatureOut(0), Pression(0), weather(IconWeatherImage::unkonwn){
        for (int itr = 0; itr < MAX_DAY_WEATHER ; itr ++)
        {
            weekWeather[itr].TemperatureMin = 0;
            weekWeather[itr].TemperatureMax = 0;
            weekWeather[itr].weatherMorning = IconWeatherImage::unkonwn;
            weekWeather[itr].weatherAfternoon = IconWeatherImage::unkonwn;
            weekWeather[itr].DayOfWeek = DAY_OF_WEEK::Sunday;
        }
    }
    
    
};


class DisplayModuleWeather : public DisplayModule 
{
	public:
    DisplayModuleWeather(DataViewWeather* dataViewWeather ) :  DisplayModule( ModuleDimmensions(225,  245, 1)), m_dataViewWeather(dataViewWeather){};
    const uint8_t* weatherToIcon(IconWeatherImage::IconWeater value, tImage * config, bool lowDef = false);
    void FillModule(GxEPD& m_GxEPD);
    void updateViewData();
    bool updateTimeOnly = false;
	private :
    std::string m_forecastURL;
    DataViewWeather* m_dataViewWeather;

};


#endif // _DisplayModuleWeather_H_
