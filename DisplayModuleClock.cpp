#include <DisplayModuleClock.h>
#include <Fonts/FreeMonoBold18pt7b.h>
void DisplayModuleClock::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();
      
      m_GxEPD.drawRect(relativePos.x, relativePos.y, 50, 50, GxEPD_BLACK);
      const GFXfont* f = &FreeMonoBold18pt7b;
      m_GxEPD.setFont(f);
      m_GxEPD.setTextColor(GxEPD_BLACK);
      m_GxEPD.setCursor(relativePos.x, 50 );
      m_GxEPD.setTextSize(1);
      m_GxEPD.println("12:25");
}