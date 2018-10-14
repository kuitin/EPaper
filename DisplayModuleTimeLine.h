#ifndef _DisplayModuleTimeLine_H_
#define _DisplayModuleTimeLine_H_
#include <DisplayModule.h>
#include "iostream"
#include <vector>

struct  DateContent {    
    unsigned int date;
    String eventDetails;
};

class DisplayModuleTimeLine : public DisplayModule 
{
	public:
    DisplayModuleTimeLine(unsigned int currentDate, unsigned int period, const std::vector<DateContent>& data);
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
    
	private :
    std::vector<DateContent> m_data;
    unsigned int m_currentDate = 0;
    unsigned int m_period = 0;

};


#endif
