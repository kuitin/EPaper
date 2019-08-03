#ifndef _ControllerModuleWeather_H_
#define _ControllerModuleWeather_H_
#include "Modules/ControllerModule.h"
#include "DisplayModuleWeather.h"

#include "Modules/DisplayModuleCommunicationWifi.h"

class ControllerModuleWeather : public ControllerModule 
{
	public:
    ControllerModuleWeather(const String & forecastURL) ;
    void UpdateData();
    void UpdateDataView();
    ~ControllerModuleWeather();
     // Setter
    void SeteCO2(int newValue){m_dataWeather->eCO2 = newValue;}
    void SetTVOC(int newValue){m_dataWeather->TVOC = newValue;}
    void SetTemperatureIn(float newValue){m_dataWeather->TemperatureIn = newValue;}
    void SetHumidity(float newValue){m_dataWeather->humidity = newValue;}

	private :
    void GetServerData(String forecastURL);
    String m_forecastURL;
    DataViewWeather* m_dataWeather;
    bool m_flagNeedUpdate;
    IconWeatherImage::IconWeater IconCodeToIconImg(String iconTable);
    void CollectWeatherOfWeek(JsonArray& array);

   
};


#endif // _ControllerModuleWeather_H_
