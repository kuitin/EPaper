#include <Modules/Clock/DisplayModuleClock.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
void DisplayModuleClock::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();
      
      m_GxEPD.fillRect(relativePos.x, relativePos.y, GetWidth(), GetHeight(), GxEPD_BLACK);
      const GFXfont* f12 = &FreeMonoBold12pt7b;
      m_GxEPD.setFont(f12);
      m_GxEPD.setTextColor(GxEPD_WHITE);
      m_GxEPD.setCursor(relativePos.x + 17, relativePos.y + 20 );
      m_GxEPD.setTextSize(1);
      m_GxEPD.println(m_dataView->dayName);

      const GFXfont* f = &FreeMonoBold24pt7b;
      m_GxEPD.setFont(f);
      m_GxEPD.setTextColor(GxEPD_RED);
      m_GxEPD.setCursor(relativePos.x + 55, relativePos.y + 55 );
      m_GxEPD.setTextSize(1);
      m_GxEPD.println(m_dataView->dayNumber);

      m_GxEPD.setFont(f12);
      m_GxEPD.setTextColor(GxEPD_WHITE);
      m_GxEPD.setCursor(relativePos.x + 17, relativePos.y + 85 );
      m_GxEPD.setTextSize(1);
      String monthAndYear = String(m_dataView->month) + "   " + String(m_dataView->year);
      m_GxEPD.println(monthAndYear);
}