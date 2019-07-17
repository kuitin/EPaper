#include <Modules/Clock/ControllerModuleClock.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Modules/Utils/UtilTime.h>

ControllerModuleClock::ControllerModuleClock (const ModuleDimmensions & dimensions, bool updateTime) :
    m_flagNeedUpdate(false)
{
    
    m_view = new DisplayModuleClock(dimensions, updateTime, &m_viewData);
}


void ControllerModuleClock::UpdateData()
{
    bool m_isDSTEnable;
    unsigned long currentTime = UtilTime::GetTime(m_isDSTEnable);
    tmElements_t newTimeDate;
            breakTime(currentTime, newTimeDate);
    m_viewData.dayNumber = newTimeDate.Day;
    m_viewData.dayName = dayStr(newTimeDate.Wday);
    m_viewData.month = monthStr(newTimeDate.Month);
    m_viewData.year = newTimeDate.Year + 1970;
}

void ControllerModuleClock::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}