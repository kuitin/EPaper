#include <Modules/Clock/ControllerModuleClock.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

ControllerModuleClock::ControllerModuleClock (const ModuleDimmensions & dimensions, bool updateTime) :
    m_flagNeedUpdate(false)
{
    m_view = new DisplayModuleClock(dimensions, updateTime);
}


void ControllerModuleClock::UpdateData()
{
   
}

void ControllerModuleClock::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}