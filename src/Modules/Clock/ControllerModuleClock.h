#ifndef _ControllerModuleClock_H_
#define _ControllerModuleClock_H_
#include "Modules/ControllerModule.h"
#include "DisplayModuleClock.h"

#include "Modules/DisplayModuleCommunicationWifi.h"

class ControllerModuleClock : public ControllerModule 
{
	public:
    ControllerModuleClock(const ModuleDimmensions & dimensions, bool updateTime) ;
    ~ControllerModuleClock(){}
    void UpdateData(UtilAbstractMem* memories);
    void UpdateDataView();
    virtual Posistion PositionModule() {return topMiddle;}

	private :
    bool m_flagNeedUpdate;
    DataViewClock m_viewData;

};


#endif // _ControllerModuleClock_H_
