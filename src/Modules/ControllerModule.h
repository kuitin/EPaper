#ifndef _ControllerModule_H_
#define _ControllerModule_H_
#include "Modules/DisplayModule.h"

class ControllerModule 
{
	public:
    enum Posistion { topMiddle, bottomMiddle, none };

    explicit ControllerModule() : m_view(nullptr), m_newData(false){}
    ~ControllerModule();
    virtual void UpdateData() {}
    virtual void UpdateDataView() {}
    virtual bool NeedUpdate() {return m_newData;}
    virtual Posistion PositionModule() {return bottomMiddle;}
    DisplayModule* getView() {return m_view;}
    void ResetFlagNewData() {m_newData = false;}


    protected:
    DisplayModule* m_view;
    bool m_newData;



};

#endif // _ControllerModule_H_

