#ifndef _ControllerModule_H_
#define _ControllerModule_H_
#include "Modules/DisplayModule.h"
#include "Modules/Utils/UtilAbstractMem.h"

class ControllerModule 
{
	public:
    enum Posistion { topMiddle, bottomMiddle, topRight, none };

    explicit ControllerModule() : m_view(nullptr), m_newData(false) {}
    ~ControllerModule();
    virtual void UpdateData(UtilAbstractMem* m_memories = nullptr) {}
    virtual void UpdateDataView() {}
    virtual bool NeedUpdate() {return m_newData;}
    virtual Posistion PositionModule() {return bottomMiddle;}
    DisplayModule* getView() {return m_view;}
    void ResetFlagNewData() {m_newData = false;}
    virtual void SaveDatas(UtilAbstractMem* m_memories) {}
    virtual void LoadDatas(UtilAbstractMem* m_memories) {}
    void startMemAddress(uint16_t startMemAddress){m_startMemAddress = startMemAddress; }

    protected:
    DisplayModule* m_view;
    bool m_newData;
    bool m_isSaveDataEnable;
    uint16_t m_startMemAddress;
    
    



};

#endif // _ControllerModule_H_

