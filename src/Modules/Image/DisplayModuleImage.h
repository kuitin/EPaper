#ifndef _DisplayModuleImage_H_
#define _DisplayModuleImage_H_
#include <Modules/DisplayModule.h>
#define IMAGE_LENGTH 8344
#define IMAGE_WIDTH 224
#define IMAGE_HEIGHT 298
class DataViewImage 
{
    public:
    uint8_t* image_data;
    int length;
    int  width;
    int height;
    DataViewImage(){image_data= nullptr; length = 0; width=0;height=0;}
    ~DataViewImage()
    {
        if(image_data != nullptr)
        {
            delete image_data;
            image_data = nullptr;
        }
    }
    void freeArray()
    {
        if(image_data != nullptr)
        {
            delete image_data;
            image_data = nullptr;
        }
    }
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
