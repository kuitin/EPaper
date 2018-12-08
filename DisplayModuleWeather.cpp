#include <DisplayModuleWeather.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include "utility/BitmapExamples.h"
#include "utility/IMG_0001.h"
#include "utility/IMG_0002.h"
#include "Trad/DisplayEPaperTrad.h"


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
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 50 );
      m_GxEPD.println(String(m_dataWeather.TemperatureOut, 1 ) );
      
      m_GxEPD.setFont(f);
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 100 );
      m_GxEPD.println(String(WEATHER_TEMPERATUREINDOOR) + String(m_dataWeather.TemperatureIn, 1 ) + "C" );
      tImage config;
      const uint8_t* iconWeather =  weatherToIcon(DataWeather::cloud, &config);
      m_GxEPD.drawExampleBitmap(image_data_wicloudy, relativePos.x + 130, relativePos.y + 3, config.width, config.height, GxEPD_BLACK);
      
      
}

const uint8_t* DisplayModuleWeather::weatherToIcon(DataWeather::IconWeater value, tImage * config)
{
      switch(value)
      {
            case DataWeather::cloud:
                  *config = wicloudy;
                  return image_data_wicloudy;
            break;

            case DataWeather::rain:
                  *config = wihail;
                  return image_data_wihail;
            break;

            case DataWeather::sun:
                  *config = widaysunny;
                  return image_data_widaysunny;
            break;

            default:
                  *config = wialien;
                  return image_data_wialien;
            break;
      }
}