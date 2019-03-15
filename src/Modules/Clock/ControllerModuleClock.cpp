#include <Modules/Clock/ControllerModuleClock.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

ControllerModuleClock::ControllerModuleClock (int cornerThickness, int width, int height, bool updateTime) :
    m_flagNeedUpdate(false)
{
    m_view = new DisplayModuleClock(cornerThickness, width, height, updateTime);
}


void ControllerModuleClock::UpdateData()
{
   
}

void ControllerModuleClock::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}