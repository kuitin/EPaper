#ifndef _DisplayModuleClock_H_
#define _DisplayModuleClock_H_
#include <Modules/DisplayModule.h>

class DataViewClock 
{
    public:
    int dayNumber;
    String dayName;
    String month;
    int year;
    DataViewClock(){
        dayNumber = 0;
        dayName = "";
        month = "";
        year = 0;
    }
};

class DisplayModuleClock : public DisplayModule 
{
	public:
    DisplayModuleClock(const ModuleDimmensions & dimensions, bool updateTime, DataViewClock* dataView) : 
    DisplayModule( dimensions ), updateTimeOnly(updateTime), m_dataView(dataView){};
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
    private:
    DataViewClock* m_dataView;

};


#endif
