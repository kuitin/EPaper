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

      for ( int itrData=0; itrData < dataInPeriod.size(); itrData ++ )
      {
            DateContent currentData = dataInPeriod.at(itrData);
            const GFXfont* f = &FreeSans9pt7b;
            m_GxEPD.setFont(f);
            m_GxEPD.setTextColor(GxEPD_BLACK);
            m_GxEPD.setCursor(relativePos.x + DISPLAYMODULETIMELINE_LINEPOS_X, itrData * gridUnit + DISPLAYMODULETIMELINE_HIGHTPIXELLETTER);
            m_GxEPD.setTextSize(1);
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
            m_GxEPD.println(sentenceToDisplay);
      }
}