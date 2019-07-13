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
    ControllerModuleTimeline(const String & calendarUrl) ;
    ~ControllerModuleTimeline();
    void UpdateData();
    void UpdateDataView();
    unsigned long  GetTime();
    void ParseGoogleCalendar();

	private :
    DataViewTimeline* m_dataView;
    bool m_flagNeedUpdate;
    String m_calandarUrl;
    
};


#endif // _ControllerModuleTimeline_H_
