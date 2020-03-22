#ifndef _ControllerModuleImage_H_
#define _ControllerModuleImage_H_
#include "Modules/ControllerModule.h"
#include "DisplayModuleImage.h"
#include <Modules/Utils/UtilFramMem.h>
#include "Modules/DisplayModuleCommunicationWifi.h"

class ControllerModuleImage : public ControllerModule 
{
	public:
    ControllerModuleImage(const ModuleDimmensions & dimensions, const String & imageUrl) ;
    ~ControllerModuleImage(){}
    void UpdateData(UtilAbstractMem* memories);
    void UpdateDataView();
    virtual Posistion PositionModule() {return topRight;}
    bool GetDataFromGoogle();
    void SaveDatas(UtilAbstractMem* ) ;
    void LoadDatas(UtilAbstractMem* ) ;

	private :
    bool m_flagNeedUpdate;
    DataViewImage m_viewData;
    String m_imageUrl;
    UtilAbstractMem* m_memories;

};


#endif // ControllerModuleImage
