#ifndef _ControllerModuleTimeline_H_
#define _ControllerModuleTimeline_H_
#include "Modules/ControllerModule.h"
#include "DisplayModuleTimeline.h"

#include "Modules/DisplayModuleCommunicationWifi.h"
#include <SPI.h>
#include <WiFi.h>

class ControllerModuleTimeline : public ControllerModule 
{
	public:
    ControllerModuleTimeline(const String & calendarUrl, int utc = 1) ;
    ~ControllerModuleTimeline();
    void UpdateData();
    void UpdateDataView();
    unsigned long  GetTime();
    void ParseGoogleCalendar();

	private :
    DataViewTimeline* m_dataView;
    bool m_flagNeedUpdate;
    String m_calandarUrl;
    int m_Utc;
    bool m_isDSTEnable;
    
};


#endif // _ControllerModuleTimeline_H_
