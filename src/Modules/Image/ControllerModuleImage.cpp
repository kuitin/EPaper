#include <Modules/Image/ControllerModuleImage.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Modules/Utils/UtilTime.h>

ControllerModuleImage::ControllerModuleImage (const ModuleDimmensions & dimensions, const String & imageUrl) :
    m_imageUrl(imageUrl)
{
    m_view = new DisplayModuleImage(dimensions, &m_viewData);
}


void ControllerModuleImage::UpdateData()
{
   
}

void ControllerModuleImage::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}