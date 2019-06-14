#ifndef _DisplayModuleWeather_H_
#define _DisplayModuleWeather_H_
#include "Modules/DisplayModule.h"
#include "svg/header/wi-cloudy.h"
#include "svg/header/wi-hail.h"
#include "svg/header/wi-day-sunny.h"
#include "svg/header/wi-alien.h"
#include <Modules/Utils/UtilTime.h>

#include "Modules/DisplayModuleCommunicationWifi.h"

#define MAX_DAY_WEATHER 5
class IconWeatherImage 
{
    public:
    enum IconWeater
    {
        cloud,
        rain,
        sun,
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
    DataViewWeather() {}
    double TemperatureIn;
    double TemperatureOut;
    double Pression;
    IconWeatherImage::IconWeater weather;
    DataViewWeatherOfFullDay weekWeather [MAX_DAY_WEATHER];
    
};


class DisplayModuleWeather : public DisplayModule 
{
	public:
    DisplayModuleWeather(DataViewWeather* dataViewWeather ) :  DisplayModule( ModuleDimmensions(225,  230, 1)), m_dataViewWeather(dataViewWeather){};
    const uint8_t* weatherToIcon(IconWeatherImage::IconWeater value, tImage * config);
    void FillModule(GxEPD& m_GxEPD);
    void updateViewData();
    bool updateTimeOnly = false;
	private :
    std::string m_forecastURL;
    DataViewWeather* m_dataViewWeather;

};


#endif // _DisplayModuleWeather_H_
