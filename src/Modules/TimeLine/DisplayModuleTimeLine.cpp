#include <Modules/TimeLine/DisplayModuleTimeLine.h>
#include <Fonts/FreeSans9pt7b.h>
#include <TimeLib.h>
#include <Modules/Utils/UtilTime.h>

#define DISPLAYMODULETIMELINE_LINEPOS_X 10
#define DISPLAYMODULETIMELINE_12HOURTOSEC 43200
#define DISPLAYMODULETIMELINE_HIGHTPIXELLETTER 18
#define DISPLAYMODULETIMELINE_MAXLENGTHCONTENT 17
#define DISPLAYMODULETIMELINE_LENGTHCONTENT 20
#define DISPLAYMODULETIMELINE_SLIDE_LENGTH_Y 10

#define DISPLAYMODULETIMELINE_EVENT_LINEPOS_X 15
#define DISPLAYMODULETIMELINE_EVENT_LENGTH_Y (DISPLAYMODULETIMELINE_SLIDE_LENGTH_Y + 5)

using namespace std;
DisplayModuleTimeLine::DisplayModuleTimeLine(DataViewTimeline* viewData) :
 m_viewDatas(viewData), 
 DisplayModule( ModuleDimmensions(200,  384, 1) ), updateTimeOnly(true)
{

}

#define DISPLAYMODULETIMELINE_MAXEVENT 5
void DisplayModuleTimeLine::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();
      
      m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, 0, relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, GetHeight(), GxEPD_BLACK);
      if(m_viewDatas->listEvent.size() == 0)
      return;
      // Get all event in a period
      std::vector<DateContent> dataInPeriod;
      int maxEventCoutn = m_viewDatas->listEvent.size() <  DISPLAYMODULETIMELINE_MAXEVENT ? m_viewDatas->listEvent.size() : DISPLAYMODULETIMELINE_MAXEVENT;
      for ( int itrData=0; itrData <  maxEventCoutn; itrData ++ )
      {
          if((m_viewDatas->listEvent.at(itrData).endDate > m_viewDatas->currentDate &&
             m_viewDatas->listEvent.at(itrData).startDate < m_viewDatas->currentDate) ||
             m_viewDatas->listEvent.at(itrData).startDate > m_viewDatas->currentDate )
          {
            DateContent currentData =  m_viewDatas->listEvent.at(itrData);
            dataInPeriod.push_back(currentData);
          }
      }      

      const GFXfont* f = &FreeSans9pt7b;
      m_GxEPD.setFont(f);
      m_GxEPD.setTextColor(GxEPD_BLACK);
      m_GxEPD.setTextSize(1);
      // Display Module Title
      m_GxEPD.setCursor(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, DISPLAYMODULETIMELINE_HIGHTPIXELLETTER);
      m_GxEPD.println(TIMELINE_TITLE);

      //Get number of event to display
      int eventCount = dataInPeriod.size();
      // If nothing to display, no event, so no need to do anything.
      if(eventCount == 0)
      return;

    //   unsigned int dateFirstEvent = dataInPeriod.at( 0 ).startDate;
    //   unsigned int dateLastEvent = dataInPeriod.at( eventCount - 1 ).startDate;
        unsigned int maxEvent = GetHeight() / DISPLAYMODULETIMELINE_HIGHTPIXELLETTER;
      
    int deltaStart = DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + 5;
    unsigned int gridUnit = deltaStart * 3;//GetHeight() / eventCount;
    for ( int itrData=0; itrData < dataInPeriod.size(); itrData ++ )
    {
            // Draw horizontal line
            m_GxEPD.drawLine(relativePos.x , itrData * gridUnit + deltaStart , 
                             relativePos.x +GetWidth() - 1, itrData * gridUnit + deltaStart, 
                             GxEPD_RED);
            // upper array
            if (itrData != 0)
            {
                // Not draw the upper to hide the title
                for( int itrLine=1; itrLine < 10; itrLine ++ )
                {
                    m_GxEPD.drawLine(relativePos.x + itrLine*2, itrData * gridUnit + deltaStart - itrLine -1, 
                                    relativePos.x + GetWidth() - 1 - itrLine*2, itrData * gridUnit + deltaStart- itrLine -1, 
                                    GxEPD_BLACK);
                }
            }
            //Draw one more  array
            if (itrData == dataInPeriod.size() -1)
            {
                // Not draw the upper to hide the title
                for( int itrLine=1; itrLine < 10; itrLine ++ )
                {
                    m_GxEPD.drawLine(relativePos.x + itrLine*2, (itrData+1)  * gridUnit + deltaStart - itrLine, 
                                    relativePos.x +GetWidth() - 1 - itrLine*2, (itrData+1) * gridUnit + deltaStart- itrLine, 
                                    GxEPD_BLACK);
                }
                 m_GxEPD.drawLine(relativePos.x , (itrData+1) * gridUnit + deltaStart +1 , 
                             relativePos.x +GetWidth()  - 1, (itrData+1) * gridUnit + deltaStart +1, 
                             GxEPD_RED);
            }
            //Down array
            for( int itrLine=1; itrLine < 10; itrLine ++ )
            {
                m_GxEPD.drawLine(relativePos.x + itrLine*2, itrData * gridUnit + deltaStart + itrLine+1, 
                                relativePos.x +GetWidth() - 1 - itrLine*2, itrData * gridUnit + deltaStart + itrLine+1, 
                                GxEPD_BLACK);
            }
            
            // Draw vertical line
            int lineDrawVerticalCount = 10;
            for( int itrLine=4; itrLine < lineDrawVerticalCount; itrLine ++ )
            {
                m_GxEPD.drawLine(relativePos.x + itrLine*2 , itrData * gridUnit + deltaStart + itrLine +2 , 
                                relativePos.x + itrLine*2, (itrData+1) * gridUnit + deltaStart  - itrLine -1, 
                                GxEPD_RED);
                m_GxEPD.drawLine(relativePos.x + itrLine*2 +1, itrData * gridUnit + deltaStart + itrLine +2, 
                                relativePos.x + itrLine*2+1, (itrData+1) * gridUnit + deltaStart  - itrLine-1, 
                                GxEPD_RED);
            }
          
            DateContent currentData = dataInPeriod.at(itrData);           
           
            m_GxEPD.setCursor(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + DISPLAYMODULETIMELINE_EVENT_LINEPOS_X,
                              itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y - 3);
            
            int lineDayUpY = -18;
            int lineDayMiddleY = -8;
            int lineDayDownY = 2;
            m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 9 , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayDownY,
                                GxEPD_RED);
             m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 10 , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 16, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayDownY,
                                GxEPD_RED);

            m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15 , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayDownY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15*11, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayDownY,
                                GxEPD_RED);

            m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15 *11, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayDownY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15*11 + 6, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY,
                                GxEPD_RED);
            m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15 *11 -1, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayDownY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15*11 + 5, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY,
                                GxEPD_RED);

            m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15 *11 + 6, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15*11 , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayUpY,
                                GxEPD_RED);
            m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15 *11+ 5 , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15*11 -1, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayUpY,
                                GxEPD_RED);
            m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15 , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayUpY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15*11, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayUpY,
                                GxEPD_RED);
             m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 15 , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayUpY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 9, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY,
                                GxEPD_RED);
             m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X +16  , 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayUpY, 
                             relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + 10, 
                             itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y + lineDayMiddleY,
                                GxEPD_RED);
            // Print event date            
            // m_GxEPD.println(makeTimeFromTimestamp(currentData.startDate));
            m_GxEPD.println(formatDate(currentData));

            // Print event content
            String sentenceToDisplay ( currentData.eventDetails);
            if ( sentenceToDisplay.length() > DISPLAYMODULETIMELINE_MAXLENGTHCONTENT )
            {
                  sentenceToDisplay.remove( DISPLAYMODULETIMELINE_MAXLENGTHCONTENT , sentenceToDisplay.length() );
                  sentenceToDisplay += "...";
                 // strncpy (sentenceToDisplay, currentData.eventDetails, DISPLAYMODULETIMELINE_MAXLENGTHCONTENT);
                 // strncat (sentenceToDisplay, "...\0", DISPLAYMODULETIMELINE_LENGTHCONTENT);
            }
            else
            {
                //  strncpy (sentenceToDisplay, currentData.eventDetails, DISPLAYMODULETIMELINE_MAXLENGTHCONTENT);
            }
            m_GxEPD.setCursor(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X + DISPLAYMODULETIMELINE_EVENT_LINEPOS_X,
                              itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER * 2 + deltaStart + DISPLAYMODULETIMELINE_EVENT_LENGTH_Y);
            m_GxEPD.println(sentenceToDisplay);
      }
}
#define TIMELINE_TODAY "Today"
#define TIMELINE_TOMORROW "Tomorrow"
#define TIMELINE_ENDDAYS "End in %d days"
String DisplayModuleTimeLine::formatDate(DateContent currentData ){
    tmElements_t tmTemp;
    breakTime(m_viewDatas->currentDate , tmTemp);
    String strDate = makeTimeFromTimestamp(m_viewDatas->currentDate);
    // int Year, Month, Day, Hour, Minute, Second ;
    // sscanf(strDate.c_str(), "%d-%d-%d %d:%d:%d", &Day, &Month, &Year, &Hour, &Minute, &Second);
    char buffer [50];
    sprintf (buffer, "%d-%d-%d %d:%d:%d", tmTemp.Day, tmTemp.Month, 1970 + tmTemp.Year,0,0,0);
    unsigned long morningTimestamp = getTimeStampFromDate(buffer);

    if(currentData.isAllDay == true)
    {
        
        
        if(currentData.startDate < morningTimestamp)
        {
            Serial.println("morningTimestamp " + String(morningTimestamp) );
            Serial.println("currentData.endDate " + String(currentData.endDate) );
            // Already started
            int numberOfDays = (currentData.endDate - morningTimestamp) / (24*60*60) ;
            char displayDate [50];
            sprintf (displayDate, TIMELINE_ENDDAYS, numberOfDays);
            return displayDate;
        }
        // Today
        else if(currentData.startDate >= morningTimestamp &&
                currentData.startDate < morningTimestamp + 24*60*60)
        {
            // Start Today
            return TIMELINE_TODAY;
        }
        else if(currentData.startDate >= morningTimestamp + 24*60*60 &&
                currentData.startDate < morningTimestamp + 24*60*60*2){
            // Start Tomorrow
            return TIMELINE_TOMORROW;
        }
        else if(currentData.startDate >= morningTimestamp + 24*60*60*2 &&
                currentData.startDate < morningTimestamp + 24*60*60*5){
            // Start Day in week
            tmElements_t newTimeDate;
            breakTime(currentData.startDate + m_viewDatas->m_isDSTEnable*3600 + m_viewDatas->utc * 3600, newTimeDate);
            // Time_data newTimeDate =  UtilTime::makeTimeToDataTime(currentData.startDate);
            // DAY_OF_WEEK currentDay = UtilTime::day_Of_Week( newTimeDate.year,  newTimeDate.month, newTimeDate.day);
            return dayStr(newTimeDate.Day);// UtilTime::getDayOfWeekStr(currentDay);
        }
        else
        {
            // Later
            tmElements_t tm;
            breakTime(currentData.startDate + m_viewDatas->m_isDSTEnable*3600 + m_viewDatas->utc * 3600 , tm);
            return String(tm.Day) + "-" + String(tm.Month) + "-" + String(1970 + tm.Year) + " " + String(tm.Hour) + ":" + String(tm.Minute);
        }     
    }
    else
    {
         // Today
         Serial.println("morningTimestamp " + String(morningTimestamp) );
         Serial.println("currentData.startDate " + String(currentData.startDate) );
        if(currentData.startDate >= morningTimestamp &&
           currentData.startDate < morningTimestamp + 24*60*60)
        {
            // Start Today
            tmElements_t newTimeDate;
            breakTime(currentData.startDate + m_viewDatas->m_isDSTEnable*3600 + m_viewDatas->utc * 3600, newTimeDate);
            String message = String(TIMELINE_TODAY) + " " + String(newTimeDate.Hour) + ":" + String(newTimeDate.Minute);
            return message;
        }
        else if(currentData.startDate >= morningTimestamp + 24*60*60 &&
                currentData.startDate < morningTimestamp + 24*60*60*2){
            // Start Tomorrow
            tmElements_t newTimeDate;
            breakTime(currentData.startDate + m_viewDatas->m_isDSTEnable*3600 + m_viewDatas->utc * 3600, newTimeDate);
            String message = String(TIMELINE_TOMORROW) + " " + String(newTimeDate.Hour) + ":" + String(newTimeDate.Minute);
            return message;
        }
        else if(currentData.startDate >= morningTimestamp + 24*60*60*2 &&
                currentData.startDate < morningTimestamp + 24*60*60*7){
            // Start Day in week
            tmElements_t newTimeDate;
            breakTime(currentData.startDate + m_viewDatas->m_isDSTEnable*3600 + m_viewDatas->utc * 3600, newTimeDate);
            String message = String(dayStr(newTimeDate.Wday)) + " " + String(newTimeDate.Hour) + ":" + String(newTimeDate.Minute);
            return message;
        }
        else
        {
            // Later
            tmElements_t tm;
            breakTime(currentData.startDate + m_viewDatas->m_isDSTEnable*3600 + m_viewDatas->utc * 3600 , tm);
            return String(tm.Day) + "-" + String(tm.Month) + "-" + String(1970 + tm.Year) + " " + String(tm.Hour) + ":" + String(tm.Minute);
        }   
    }
    
   
    
    
}
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

String DisplayModuleTimeLine::makeTimeFromTimestamp(unsigned long timestamp ){
// source:https://stackoverflow.com/questions/7136385/calculate-day-number-from-an-unix-timestamp-in-a-math-way
// note year argument is full four digit year (or digits since 2000), i.e.1975, (year 8 is 2008)
     // Manage Winter/Summer time
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

    result = String(d) + "-" + String(m) + "-" + String(y) + " " + String(hour) + ":" + String(minute);

    return result;
}

unsigned long DisplayModuleTimeLine::getTimeStampFromDate(String date ){
// source:https://forum.arduino.cc/index.php?topic=465881.0

    tmElements_t tm;
    int Year, Month, Day, Hour, Minute, Second ;
    sscanf(date.c_str(), "%d-%d-%d %d:%d:%d", &Day, &Month, &Year, &Hour, &Minute, &Second);
    tm.Year = CalendarYrToTm(Year);
    tm.Month = Month;
    tm.Day = Day;
    tm.Hour = Hour;
    tm.Minute = Minute;
    tm.Second = Second;
    return makeTime(tm);
}