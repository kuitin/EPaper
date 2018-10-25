#include <DisplayModuleTimeLine.h>
#include <Fonts/FreeSans9pt7b.h>


#define DISPLAYMODULETIMELINE_LINEPOS_X 10
#define DISPLAYMODULETIMELINE_12HOURTOSEC 43200
#define DISPLAYMODULETIMELINE_HIGHTPIXELLETTER 18
#define DISPLAYMODULETIMELINE_MAXLENGTHCONTENT 17
#define DISPLAYMODULETIMELINE_LENGTHCONTENT 20

using namespace std;
DisplayModuleTimeLine::DisplayModuleTimeLine(unsigned int date, unsigned int period, const std::vector<DateContent>& data) 
: DisplayModule( 1,  200,  384), updateTimeOnly(true)
{
      m_data = data;
      m_currentDate = date;
      m_period = period;
}


void DisplayModuleTimeLine::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();
      
      m_GxEPD.drawLine(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, 0, relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, m_height, GxEPD_BLACK);

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
      unsigned int maxEvent = m_height / DISPLAYMODULETIMELINE_HIGHTPIXELLETTER;
      
      unsigned int gridUnit = m_height / eventCount;
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

String DisplayModuleTimeLine::makeTime(unsigned long timestamp ){
// source:https://stackoverflow.com/questions/7136385/calculate-day-number-from-an-unix-timestamp-in-a-math-way
// note year argument is full four digit year (or digits since 2000), i.e.1975, (year 8 is 2008)
  
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