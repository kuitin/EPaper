#include <Modules/Weather/DisplayModuleWeather.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
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
      
      const GFXfont* f_light = &FreeMono9pt7b;
      m_GxEPD.setFont(f_light);
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 78 );
      m_GxEPD.println(String(WEATHER_TEMPERATUREINDOOR));
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 98 );
      m_GxEPD.println("  " + String(m_dataViewWeather->eCO2 ) + " ppm"  );
      m_GxEPD.setCursor(relativePos.x + 140, relativePos.y + 98 );
      m_GxEPD.println(String(m_dataViewWeather->TVOC ) + " ppb");

      m_GxEPD.setFont(f_light);
      m_GxEPD.setCursor(relativePos.x, relativePos.y + 118 );
      m_GxEPD.println("  " + String(m_dataViewWeather->TemperatureIn, 2 ) + "C" );
      m_GxEPD.setCursor(relativePos.x + 140, relativePos.y + 118 );
      m_GxEPD.println( String(m_dataViewWeather->humidity, 2 ) + "%");
      
      m_GxEPD.setFont(f);
      tImage config;
      const uint8_t* iconWeather =  weatherToIcon(m_dataViewWeather->weather, &config);
      m_GxEPD.drawExampleBitmap(iconWeather, relativePos.x + 130, relativePos.y + 3, config.width, config.height, GxEPD_BLACK);
      
      // Display weather of the weekWeather
      // int maxDayDisplay = m_dataViewWeather->weekWeather.size() < MAX_DAY_WEATHER : 0 ? MAX_DAY_WEATHER;
      for (int itrDay = 0; itrDay < MAX_DAY_WEATHER ; itrDay ++ )
      {
            m_GxEPD.setCursor(relativePos.x, relativePos.y + 143 + itrDay*25);
            if(m_dataViewWeather->weekWeather[itrDay].weatherMorning != IconWeatherImage::none)
            {
                  tImage configMorning;
                  const uint8_t* iconWeatherMorning = weatherToIcon(m_dataViewWeather->weekWeather[itrDay].weatherMorning, &configMorning, true);
                  m_GxEPD.drawExampleBitmap(iconWeatherMorning, relativePos.x + 40, relativePos.y + 123 + itrDay*25, 
                                          configMorning.width, configMorning.height, GxEPD_BLACK);
            }
            if(m_dataViewWeather->weekWeather[itrDay].weatherAfternoon != IconWeatherImage::none)
            {
                  tImage configAfternoon;
                  const uint8_t* iconWeatherAfternoon = weatherToIcon(m_dataViewWeather->weekWeather[itrDay].weatherAfternoon, &configAfternoon, true);
                  m_GxEPD.drawExampleBitmap(iconWeatherAfternoon, relativePos.x + 75, relativePos.y + 123 + itrDay*25, 
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
                        *config = wicloud_Low;
                        return image_data_wicloud_Low;
                  }else
                  {
                        *config = wicloud;
                        return image_data_wicloud;
                  }
            break;

            case IconWeatherImage::brokenCloud:
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

            case IconWeatherImage::ChanceRain:
                  if(lowDef)
                  {
                        *config = wirain_Low;
                        return image_data_wirain_Low;
                  }else
                  {
                        *config = wirain;
                        return image_data_wirain;
                  }
            break;

            case IconWeatherImage::sun:
                  if(lowDef)
                  {
                        *config = widaysunny_Low;
                        return image_data_widaysunny_Low;
                  }else
                  {
                        *config = widaysunny;
                        return image_data_widaysunny;
                  }
            break;

            case IconWeatherImage::MostlySunny:
                  if(lowDef)
                  {
                         *config = widaycloudy_Low;
                        return image_data_widaycloudy_Low;
                  }else
                  {
                        *config = widaycloudy;
                        return image_data_widaycloudy;
                  }
            break;

            case IconWeatherImage::rain:
                  if(lowDef)
                  {
                         *config = widayrainmix_Low;
                        return image_data_widayrainmix_Low;
                  }else
                  {
                        *config = widayrainmix;
                        return image_data_widayrainmix;
                  }
            break;

            case IconWeatherImage::Tstorms:
                  if(lowDef)
                  {
                         *config = widaylightning_Low;
                        return image_data_widaylightning_Low;
                  }else
                  {
                        *config = widaylightning;
                        return image_data_widaylightning;
                  }
            break;

            case IconWeatherImage::Snow:
                  if(lowDef)
                  {
                         *config = widaysnow_Low;
                        return image_data_widaysnow_Low;
                  }else
                  {
                        *config = widaysnow;
                        return image_data_widaysnow;
                  }
            break;

             case IconWeatherImage::Haze:
                  if(lowDef)
                  {
                         *config = widayhaze_Low;
                        return image_data_widayhaze_Low;
                  }else
                  {
                        *config = widayhaze;
                        return image_data_widayhaze;
                  }
            break;

             case IconWeatherImage::Fog:
                  if(lowDef)
                  {
                         *config = widayfog_Low;
                        return image_data_widayfog_Low;
                  }else
                  {
                        *config = widayfog;
                        return image_data_widayfog;
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