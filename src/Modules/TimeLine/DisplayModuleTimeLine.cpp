#include <Modules/TimeLine/DisplayModuleTimeLine.h>
#include <Fonts/FreeSans9pt7b.h>


#define DISPLAYMODULETIMELINE_LINEPOS_X 10
#define DISPLAYMODULETIMELINE_12HOURTOSEC 43200
#define DISPLAYMODULETIMELINE_HIGHTPIXELLETTER 18
#define DISPLAYMODULETIMELINE_MAXLENGTHCONTENT 17
#define DISPLAYMODULETIMELINE_LENGTHCONTENT 20

using namespace std;
DisplayModuleTimeLine::DisplayModuleTimeLine(DataViewTimeline* viewData) :
 m_viewDatas(viewData), 
 DisplayModule( ModuleDimmensions(1,  200,  384) ), updateTimeOnly(true)
{

}


void DisplayModuleTimeLine::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();
      
      m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, 0, relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, GetHeight(), GxEPD_BLACK);

      // Get all event in a period
      std::vector<DateContent> dataInPeriod;
      for ( int itrData=0; itrData < m_data.size(); itrData ++ )
      {
            DateContent currentData = m_data.at(itrData);
            if ( currentData.date < m_period + m_currentDate && currentData.date > m_currentDate - DISPLAYMODULETIMELINE_12HOURTOSEC )
            {
                  dataInPeriod.push_back(currentData);
            }
      }      

      //Get number of event to display
      int eventCount = dataInPeriod.size();
      unsigned int dateFirstEvent = dataInPeriod.at( 0 ).date;
      unsigned int dateLastEvent = dataInPeriod.at( eventCount - 1 ).date;
      unsigned int maxEvent = GetHeight() / DISPLAYMODULETIMELINE_HIGHTPIXELLETTER;
      
      unsigned int gridUnit = GetHeight() / eventCount;
      const GFXfont* f = &FreeSans9pt7b;
      m_GxEPD.setFont(f);
      m_GxEPD.setTextColor(GxEPD_BLACK);
      m_GxEPD.setTextSize(1);
      // Display Module Title
       m_GxEPD.setCursor(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, DISPLAYMODULETIMELINE_HIGHTPIXELLETTER);
      m_GxEPD.println(TIMELINE_TITLE);
      int deltaStart = DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + 5;
      for ( int itrData=0; itrData < dataInPeriod.size(); itrData ++ )
      {
            DateContent currentData = dataInPeriod.at(itrData);           
           
            m_GxEPD.setCursor(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER + deltaStart);
            // Print event date            
            m_GxEPD.println(makeTime(currentData.date));

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
            m_GxEPD.setCursor(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER * 2 + deltaStart);
            m_GxEPD.println(sentenceToDisplay);
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

String DisplayModuleTimeLine::makeTime(unsigned long timestamp ){
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

    result = String(d) + "/" + String(m) + "/" + String(y) + " " + String(hour) + ":" + String(minute);

    return result;
}