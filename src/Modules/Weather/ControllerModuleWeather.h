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

	private :
    void GetServerData(String forecastURL, DataViewWeather& data);
    String m_forecastURL;
    DataViewWeather* m_dataWeather;
    bool m_flagNeedUpdate;

};


#endif // _ControllerModuleWeather_H_
