#include <Modules/Image/DisplayModuleImage.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/OpenSans-Semibold9pt.h>
// #include "utility/zelda2BIS.h"
#include "utility/zelda2BISRed2.h"
void DisplayModuleImage::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();

      if(m_dataView->image_data != nullptr)
      {
            m_GxEPD.drawExampleBitmap(m_dataView->image_data, relativePos.x , relativePos.y , 
                                    m_dataView->width, m_dataView->height, GxEPD_RED);

             const GFXfont* f12 = &OpenSans_Semibold9pt7b;
            m_GxEPD.setFont(f12);
            m_GxEPD.setTextColor(GxEPD_BLACK);
            //double dayOffsetx = (double)strlen(m_dataView->dayName.c_str());
            m_GxEPD.setCursor(relativePos.x + 10, GetHeight() - 20 );
            m_GxEPD.setTextSize(1);
            String dateLastUpdate = String(m_dataView->dayName) + "  " + String(m_dataView->hour)+ ":" +  String(m_dataView->minute);
            m_GxEPD.println(dateLastUpdate);                        
      }
     
}