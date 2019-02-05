#ifndef _DisplayModuleWeather_H_
#define _DisplayModuleWeather_H_
#include <DisplayModule.h>
#include "svg/header/wi-cloudy.h"
#include "svg/header/wi-hail.h"
#include "svg/header/wi-day-sunny.h"
#include "svg/header/wi-alien.h"


#include "DisplayModuleCommunicationWifi.h"

class DataWeather 
{
    public:
    enum IconWeater
    {
        cloud,
        rain,
        sun
    };
    double TemperatureIn;
    double TemperatureOut;
    double Pression;
    IconWeater weather;
    
};


class DisplayModuleWeather : public DisplayModule 
{
	public:
    DisplayModuleWeather(DataWeather dataWeather ) :  DisplayModule( 1,  225,  200), m_dataWeather(dataWeather){};
    const uint8_t* weatherToIcon(DataWeather::IconWeater value, tImage * config);
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
	private :
    std::string m_forecastURL;
    DataWeather m_dataWeather;

};


#endif // _DisplayModuleWeather_H_
