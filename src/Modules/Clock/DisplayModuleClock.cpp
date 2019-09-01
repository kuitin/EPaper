#include <Modules/Clock/DisplayModuleClock.h>

#include <Fonts/OpenSans-Semibold12pt.h>
#include <Fonts/OpenSans-Semibold24pt.h>

void DisplayModuleClock::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();
      
      m_GxEPD.fillRect(relativePos.x, relativePos.y, GetWidth(), GetHeight(), GxEPD_BLACK);
      const GFXfont* f12 = &OpenSans_Semibold12pt7b;
      m_GxEPD.setFont(f12);
      m_GxEPD.setTextColor(GxEPD_WHITE);
      double dayOffsetx = (double)strlen(m_dataView->dayName.c_str());
      m_GxEPD.setCursor(relativePos.x + GetWidth()/2 - (dayOffsetx/2.0)*15, relativePos.y + 20 );
      m_GxEPD.setTextSize(1);
      m_GxEPD.println(m_dataView->dayName);

      const GFXfont* f = &OpenSans_Semibold24pt7b;
      m_GxEPD.setFont(f);
      m_GxEPD.setTextColor(GxEPD_RED);
      dayOffsetx = (double)m_dataView->dayNumber >= 10 ? 2 : 1;
      m_GxEPD.setCursor(relativePos.x + GetWidth()/2 - (dayOffsetx/2.0)*30, relativePos.y + 65 );
      m_GxEPD.setTextSize(1);
      m_GxEPD.println(m_dataView->dayNumber);

      m_GxEPD.setFont(f12);
      m_GxEPD.setTextColor(GxEPD_WHITE);
      String monthAndYear = String(m_dataView->month) + "  " + String(m_dataView->year);
      dayOffsetx = (double)strlen(monthAndYear.c_str());
      m_GxEPD.setCursor(relativePos.x + GetWidth()/2 - (dayOffsetx/2.0)*15, relativePos.y + 95 );
      m_GxEPD.setTextSize(1);
      
      m_GxEPD.println(monthAndYear);
}