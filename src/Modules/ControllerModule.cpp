
#include "ControllerModule.h"

ControllerModule::~ControllerModule(){
    if(m_view)
    {
        delete m_view;
        m_view = nullptr;
    }
};


