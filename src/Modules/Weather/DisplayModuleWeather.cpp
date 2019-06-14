#include <Modules/Weather/DisplayModuleWeather.h>
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
      m_GxEPD.println(String(m_dataViewWeather->Pression) + " hPa");
      const GFXfont* f18 = &FreeMonoBold18pt7b;
      m_GxEPD.setFont(f18);
      m_GxEPD.setTextColor(GxEPD_BLACK);
      m_GxEPD.drawExampleBitmap(gImage_IMG_0001, relativePos.x +90, relativePos.y + 28, 26, 24, GxEPD_BLACK);
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 50 );
      m_GxEPD.println(String(m_dataViewWeather->TemperatureOut, 1 ) );
      
      m_GxEPD.setFont(f);
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 100 );
      m_GxEPD.println(String(WEATHER_TEMPERATUREINDOOR) + String(m_dataViewWeather->TemperatureIn, 1 ) + "C" );
      tImage config;
      const uint8_t* iconWeather =  weatherToIcon(m_dataViewWeather->weather, &config);
      m_GxEPD.drawExampleBitmap(iconWeather, relativePos.x + 130, relativePos.y + 3, config.width, config.height, GxEPD_BLACK);
      
      // Display weather of the weekWeather
      for (int itrDay = 0; itrDay < MAX_DAY_WEATHER ; itrDay ++ )
      {
            m_GxEPD.setCursor(relativePos.x, relativePos.y + 130 + itrDay*25);
            if(m_dataViewWeather->weekWeather[itrDay].weatherMorning != IconWeatherImage::none)
            {
                  tImage configMorning;
                  const uint8_t* iconWeatherMorning = weatherToIcon(m_dataViewWeather->weekWeather[itrDay].weatherMorning, &configMorning, true);
                  m_GxEPD.drawExampleBitmap(iconWeatherMorning, relativePos.x + 40, relativePos.y + 110 + itrDay*25, 
                                          configMorning.width, configMorning.height, GxEPD_BLACK);
            }
            if(m_dataViewWeather->weekWeather[itrDay].weatherAfternoon != IconWeatherImage::none)
            {
                  tImage configAfternoon;
                  const uint8_t* iconWeatherAfternoon = weatherToIcon(m_dataViewWeather->weekWeather[itrDay].weatherAfternoon, &configAfternoon, true);
                  m_GxEPD.drawExampleBitmap(iconWeatherAfternoon, relativePos.x + 75, relativePos.y + 110 + itrDay*25, 
                                            configAfternoon.width, configAfternoon.height, GxEPD_BLACK);
            }
            m_GxEPD.println(String(UtilTime::getDayOfWeekStr(m_dataViewWeather->weekWeather[itrDay].DayOfWeek)) + "       " +
                      String(m_dataViewWeather->weekWeather[itrDay].TemperatureMax, 1 ) + "  " +
                      String(m_dataViewWeather->weekWeather[itrDay].TemperatureMin, 1 )  );
      }
      

      
}

const uint8_t* DisplayModuleWeather::weatherToIcon(IconWeatherImage::IconWeater value, tImage * config,  bool lowDef)
{
      switch(value)
      {
            case IconWeatherImage::cloud:
                  if(lowDef)
                  {
                        *config = wicloudy_Low;
                        return image_data_wicloudy_Low;
                  }else
                  {
                        *config = wicloudy;
                        return image_data_wicloudy;
                  }
            break;

            case IconWeatherImage::rain:
                  if(lowDef)
                  {
                        *config = wihail_low;
                        return image_data_wihail_low;
                  }else
                  {
                        *config = wihail;
                        return image_data_wihail;
                  }
            break;

            case IconWeatherImage::sun:
                  if(lowDef)
                  {
                        *config = widaysunny_low;
                        return image_data_widaysunny_low;
                  }else
                  {
                        *config = widaysunny;
                        return image_data_widaysunny;
                  }
            break;

            default:
                  if(lowDef)
                  {
                        *config = wialien_low;
                        return image_data_wialien_low;
                  }else
                  {
                        *config = wialien;
                        return image_data_wialien;
                  }
            break;
      }
}