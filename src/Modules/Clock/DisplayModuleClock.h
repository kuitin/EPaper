#ifndef _DisplayModuleClock_H_
#define _DisplayModuleClock_H_
#include <Modules/DisplayModule.h>
class DisplayModuleClock : public DisplayModule 
{
	public:
    DisplayModuleClock(int cornerThickness, int width, int height, bool updateTime) : DisplayModule( cornerThickness,  width,  height), updateTimeOnly(updateTime){};
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
	private :

};


#endif
