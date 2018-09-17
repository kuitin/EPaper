#ifndef _DisplayModuleTimeLine_H_
#define _DisplayModuleTimeLine_H_
#include <DisplayModule.h>
#include "iostream"
#include <vector>

struct  DateContent {    
    int day;
    int month;
    int year;
    char* eventDetails;
};

class DisplayModuleTimeLine : public DisplayModule 
{
	public:
    DisplayModuleTimeLine(const std::vector<DateContent>& data);
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
	private :

};


#endif
