#ifndef _DisplayModuleWeather_H_
#define _DisplayModuleWeather_H_
#include "Modules/DisplayModule.h"
#include "svg/header/wi-cloudy.h"
#include "svg/header/wi-hail.h"
#include "svg/header/wi-day-sunny.h"
#include "svg/header/wi-alien.h"


#include "Modules/DisplayModuleCommunicationWifi.h"

class DataViewWeather 
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
    DisplayModuleWeather(DataViewWeather* dataViewWeather ) :  DisplayModule( 1,  225,  200), m_dataViewWeather(dataViewWeather){};
    const uint8_t* weatherToIcon(DataViewWeather::IconWeater value, tImage * config);
    void FillModule(GxEPD& m_GxEPD);
    void updateViewData();
    bool updateTimeOnly = false;
	private :
    std::string m_forecastURL;
    DataViewWeather* m_dataViewWeather;

};


#endif // _DisplayModuleWeather_H_
