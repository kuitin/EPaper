#ifndef _ControllerModuleImage_H_
#define _ControllerModuleImage_H_
#include "Modules/ControllerModule.h"
#include "DisplayModuleImage.h"

#include "Modules/DisplayModuleCommunicationWifi.h"

class ControllerModuleImage : public ControllerModule 
{
	public:
    ControllerModuleImage(const ModuleDimmensions & dimensions, const String & imageUrl) ;
    ~ControllerModuleImage(){}
    void UpdateData();
    void UpdateDataView();
    virtual Posistion PositionModule() {return topRight;}

	private :
    bool m_flagNeedUpdate;
    DataViewImage m_viewData;
    String m_imageUrl;

};


#endif // ControllerModuleImage
