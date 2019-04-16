#ifndef _DisplayModuleTimeLine_H_
#define _DisplayModuleTimeLine_H_
#include <Modules/DisplayModule.h>
#include "iostream"
#include <vector>
#include "Trad/DisplayEPaperTrad.h"


struct  DateContent {    
    unsigned int date;
    String eventDetails;
};
class DataViewTimeline 
{
    public:
    std::vector<DateContent> listEvent;
    unsigned int currentDate = 0;
    unsigned int period = 0;
};

class DisplayModuleTimeLine : public DisplayModule 
{
	public:
    DisplayModuleTimeLine(DataViewTimeline* viewData);
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
    
	private :
    DataViewTimeline* m_viewDatas;
    String makeTime(unsigned long timestamp );

};


#endif
