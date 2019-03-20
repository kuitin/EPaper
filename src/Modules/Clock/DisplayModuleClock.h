#ifndef _DisplayModuleClock_H_
#define _DisplayModuleClock_H_
#include <Modules/DisplayModule.h>



class DisplayModuleClock : public DisplayModule 
{
	public:
    DisplayModuleClock(const ModuleDimmensions & dimensions, bool updateTime) : 
    DisplayModule( dimensions ), updateTimeOnly(updateTime){};
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;

};


#endif
