#ifndef _DisplayModuleTimeLine_H_
#define _DisplayModuleTimeLine_H_
#include <Modules/DisplayModule.h>
#include "iostream"
#include <vector>
#include "Trad/DisplayEPaperTrad.h"


struct  DateContent {    
    unsigned int startDate;
    unsigned int endDate;
    String eventDetails;
    bool isAllDay;
};
class DataViewTimeline 
{
    public:
    std::vector<DateContent> listEvent;
    unsigned int currentDate = 0;
    unsigned int period = 0;
    bool m_isDSTEnable = false;
    int utc = 0;
};

class DisplayModuleTimeLine : public DisplayModule 
{
	public:
    DisplayModuleTimeLine(DataViewTimeline* viewData);
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
    
	private :
    DataViewTimeline* m_viewDatas;
    String makeTimeFromTimestamp(unsigned long timestamp );
    String formatDate(DateContent data );
    unsigned long getTimeStampFromDate(String date );

};


#endif
