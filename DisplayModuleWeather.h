#ifndef _DisplayModuleWeather_H_
#define _DisplayModuleWeather_H_
#include <DisplayModule.h>



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
    DisplayModuleWeather(int cornerThickness, int width, int height, DataWeather dataWeather ) : DisplayModule( cornerThickness,  width,  height), m_dataWeather(dataWeather){};
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
	private :
    DataWeather m_dataWeather;

};


#endif // _DisplayModuleWeather_H_
