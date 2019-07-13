#ifndef _UtilTime_H_
#define _UtilTime_H_
#include <Modules/DisplayModule.h>
#include "iostream"
#include <vector>


// TODO manage namespace
struct Time_data
{
   unsigned day;
   unsigned month;
   unsigned year;
   unsigned hour;
   unsigned minute; 
};

 enum  DAY_OF_WEEK{
        Saturday = 0,
        Sunday   = 1,
        Monday   = 2,
        Tuesday,
        Wednesday,
        Thursday,
        Friday        
    };

class UtilTime
{
    public:  
    
    static String makeTimeToStr(unsigned long timestamp );
    static Time_data makeTimeToDataTime(unsigned long timestamp );
    static DAY_OF_WEEK day_Of_Week(uint16_t year, uint8_t month, uint8_t day);
    static String getDayOfWeekStr(int dayOfWeekNbr);
};


#endif //_UtilTime_H_
