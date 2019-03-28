#ifndef _ControllerModuleTimeline_H_
#define _ControllerModuleTimeline_H_
#include "Modules/ControllerModule.h"
#include "DisplayModuleTimeline.h"

#include "Modules/DisplayModuleCommunicationWifi.h"

class ControllerModuleTimeline : public ControllerModule 
{
	public:
    ControllerModuleTimeline() ;
    ~ControllerModuleTimeline();
    void UpdateData();
    void UpdateDataView();

	private :
    DataViewTimeline* m_dataView;
    bool m_flagNeedUpdate;

};


#endif // _ControllerModuleTimeline_H_
