#include <Modules/Utils/UtilTime.h>


static const unsigned char countTime = 15;
static const unsigned long summerTime [countTime] = { 1553994000,
                                                      1585443600,
                                                      1616893200,
                                                      1648342800,
                                                      1679792400,
                                                      1711846800,
                                                      1743296400,
                                                      1774746000,
                                                      1806195600,
                                                      1837645200,
                                                      1869094800,
                                                      1901149200,
                                                      1932598800,
                                                      1964048400};
                                                      
static const unsigned long winterTime [countTime] = { 1540688400, 
                                                      1572138000,
                                                      1603587600,
                                                      1635642000,
                                                      1667091600,
                                                      1698541200,
                                                      1729990800,
                                                      1761440400,
                                                      1792890000,
                                                      1824944400,
                                                      1856394000,
                                                      1887843600,
                                                      1919293200,
                                                      1950742800,
                                                      1982797200 };

Time_data UtilTime::makeTimeToDataTime(unsigned long timestamp ){
// source:https://stackoverflow.com/questions/7136385/calculate-day-number-from-an-unix-timestamp-in-a-math-way
// note year argument is full four digit year (or digits since 2000), i.e.1975, (year 8 is 2008)
     // Manage Winter/Summer time

     Time_data dataResult;
     int utf = 2;
     bool isfound = false;

     if(timestamp < summerTime[0] || 
        timestamp > winterTime[countTime - 1])
     {
         // winter time
         utf -= 1; 
         isfound = true;
     }
     
     for(int itr = 0; itr < countTime && false == isfound; itr++)
     {        
        if( timestamp >= summerTime[itr] &&
            timestamp < winterTime[itr] )
            {
               // SUmmer time do nothing
               isfound = true;
            }
     }
     if( isfound == false )
     {
         // winter time
         utf -= 1; 
         isfound = true;
     }
 // Convert time stamp to string date
    String result;
    unsigned char minute = (timestamp / 60) % 60;
    unsigned char hour = (timestamp / 3600) % 24;

    int z = timestamp / 86400 + 719468;
    int era = (z >= 0 ? z : z - 146096) / 146097;
    unsigned doe = static_cast<unsigned>(z - era * 146097);
    unsigned yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;
    int y = static_cast<int>(yoe) + era * 400;
    unsigned doy = doe - (365*yoe + yoe/4 - yoe/100);
    unsigned mp = (5*doy + 2)/153;
    unsigned d = doy - (153*mp+2)/5 + 1;
    unsigned m = mp + (mp < 10 ? 3 : -9);
    y += (m <= 2);

    dataResult.day = d;
    dataResult.month = m;
    dataResult.year = y;
    dataResult.hour = hour;
    dataResult.minute = minute;

    return dataResult;
}

String UtilTime::makeTimeToStr(unsigned long timestamp ){

    String result;
    Time_data dataTime = makeTimeToDataTime(timestamp );
    

    result = String(dataTime.day) + "/" + String(dataTime.month) + "/" +
             String(dataTime.year) + " " + String(dataTime.hour) + ":" +
             String(dataTime.minute);

    return result;
}

#define LEAP_YEAR(Y)     ( (Y>0) && !(Y%4) && ( (Y%100) || !(Y%400) ))     // from time-lib

DAY_OF_WEEK UtilTime::dayOfWeek(uint16_t year, uint8_t month, uint8_t day)
{
  uint16_t months[] = {
    0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365         };   // days until 1st of month

  uint32_t days = year * 365;        // days until year 
  for (uint16_t i = 4; i < year; i += 4) if (LEAP_YEAR(i) ) days++;     // adjust leap years, test only multiple of 4 of course

  days += months[month-1] + day;    // add the days of this year
  if ((month > 2) && LEAP_YEAR(year)) days++;  // adjust 1 if this year is a leap year, but only after febr

  return (DAY_OF_WEEK) (days % 7);   // remove all multiples of 7
}

String UtilTime::getDayOfWeekStr(int dayOfWeekNbr)
{
    switch (dayOfWeekNbr) {
        case DAY_OF_WEEK::Sunday:      return "Sunday" ;
        case DAY_OF_WEEK::Monday:      return "Monday" ;
        case DAY_OF_WEEK::Tuesday:     return "Tuesday" ;
        case DAY_OF_WEEK::Wednesday:   return "Wednesday" ;
        case DAY_OF_WEEK::Thursday:    return "Thursday" ;
        case DAY_OF_WEEK::Friday:      return "Friday" ;
        case DAY_OF_WEEK::Saturday:    return "Saturday" ;
        default :                      return "unknown";
    }
}