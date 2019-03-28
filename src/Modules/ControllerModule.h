#ifndef _ControllerModule_H_
#define _ControllerModule_H_
#include "Modules/DisplayModule.h"

class ControllerModule 
{
	public:
    explicit ControllerModule() {}
    ~ControllerModule();
    virtual void UpdateData() {}
    virtual void UpdateDataView() {}
    DisplayModule* getView() {return m_view;}
    //bool isNewData() const {return m_newdata;}



    protected:
    DisplayModule* m_view;
    bool m_newData;



};

#endif // _ControllerModule_H_

