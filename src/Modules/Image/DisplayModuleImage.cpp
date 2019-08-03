#include <Modules/Image/DisplayModuleImage.h>
#include <Fonts/FreeMonoBold24pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
// #include "utility/zelda2BIS.h"
#include "utility/zelda2BISRed2.h"
void DisplayModuleImage::FillModule(GxEPD& m_GxEPD)
{
      Point relativePos = GetPosRelative();

      if(m_dataView->image_data != nullptr)
      {
            m_GxEPD.drawExampleBitmap(m_dataView->image_data, relativePos.x , relativePos.y , 
                                    m_dataView->width, m_dataView->height, GxEPD_RED);
      }
     
}