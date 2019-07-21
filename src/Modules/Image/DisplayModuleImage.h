#ifndef _DisplayModuleImage_H_
#define _DisplayModuleImage_H_
#include <Modules/DisplayModule.h>

class DataViewImage 
{
    public:
    DataViewImage(){}
};

class DisplayModuleImage : public DisplayModule 
{
	public:
    DisplayModuleImage(const ModuleDimmensions & dimensions, DataViewImage* dataView) : 
    DisplayModule( dimensions ), m_dataView(dataView){};
    void FillModule(GxEPD& m_GxEPD);
    bool updateTimeOnly = false;
    private:
    DataViewImage* m_dataView;

};


#endif
