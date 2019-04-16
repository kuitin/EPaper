#include <Modules/TimeLine/ControllerModuleTimeline.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

ControllerModuleTimeline::ControllerModuleTimeline () :
    m_flagNeedUpdate(false)
{
    m_dataView = new DataViewTimeline();
    m_view = new DisplayModuleTimeLine(m_dataView);
}

ControllerModuleTimeline::~ControllerModuleTimeline()
{
    if(m_dataView)
    {
        delete m_dataView;
        m_dataView = nullptr;
    }
}


void ControllerModuleTimeline::UpdateData()
{
    std::vector<DateContent> data;
    DateContent tempData {1540572729,"hello123456789123456777777"};
    DateContent tempData2 {1540572729,"hello"};
    m_dataView->listEvent.push_back(tempData);
    m_dataView->listEvent.push_back(tempData2);
    m_dataView->currentDate = 1537387581;
    m_dataView->period = 5256000;
}

void ControllerModuleTimeline::UpdateDataView()
{
    // No need because the datamodel = data = pointer.
}