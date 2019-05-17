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

	private :
    void GetServerData(String forecastURL);
    String m_forecastURL;
    DataViewWeather* m_dataWeather;
    bool m_flagNeedUpdate;
    IconWeatherImage::IconWeater IconCodeToIconImg(String iconTable);
    void CollectWeatherOfWeek(JsonArray& array);

};


#endif // _ControllerModuleWeather_H_
