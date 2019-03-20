#ifndef _ControllerModuleClock_H_
#define _ControllerModuleClock_H_
#include "Modules/ControllerModule.h"
#include "DisplayModuleClock.h"

#include "Modules/DisplayModuleCommunicationWifi.h"

class ControllerModuleClock : public ControllerModule 
{
	public:
    ControllerModuleClock(const ModuleDimmensions & dimensions, bool updateTime) ;
    void UpdateData();
    void UpdateDataView();

	private :
    bool m_flagNeedUpdate;

};


#endif // _ControllerModuleClock_H_
