#include <DisplayModuleWeather.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include "utility/BitmapExamples.h"
#include "utility/IMG_0001.h"
#include "utility/IMG_0002.h"
void DisplayModuleWeather::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();

      const GFXfont* f = &FreeMonoBold9pt7b;
      m_GxEPD.setFont(f);
      m_GxEPD.setTextColor(GxEPD_BLACK);
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 15 );
      m_GxEPD.setTextSize(1);
      m_GxEPD.println(String(m_dataWeather.Pression) + " hPa");
      const GFXfont* f18 = &FreeMonoBold18pt7b;
      m_GxEPD.setFont(f18);
      m_GxEPD.setTextColor(GxEPD_BLACK);
      m_GxEPD.drawExampleBitmap(gImage_IMG_0001, relativePos.x +90, relativePos.y + 28, 26, 24, GxEPD_BLACK);
      m_GxEPD.drawExampleBitmap(gImage_IMG_0001, relativePos.x +90, relativePos.y + 128, 26, 24, GxEPD_BLACK);
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 50 );
      m_GxEPD.println(String(m_dataWeather.TemperatureOut, 1 ) );
      
      
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 150 );
      m_GxEPD.println(String(m_dataWeather.TemperatureIn, 1 ) );
      m_GxEPD.drawExampleBitmap(gImage_IMG_0002, relativePos.x + 130, relativePos.y + 3, 83, 62, GxEPD_BLACK);
      
      
}