#ifndef _DisplayModule_H_
#define _DisplayModule_H_
#include <GxEPD.h>

class Point {
    public:
	int x,y;    
	Point(int xx, int yy) : x(xx), y(yy) { }
    Point(): x(0), y(0){};
    Point& operator=(const Point &source)    {x = source.x; y = source.y; return *this; };
};

class ModuleDimmensions
{
    public:
    ModuleDimmensions(int width, int height, int cornerThickness):
    m_width(width), m_height(height), m_cornerThickness(cornerThickness){};
    int m_width;
    int m_height;    
    int m_cornerThickness;
};



class DisplayModule 
{
	public:
    explicit DisplayModule(const ModuleDimmensions & dimensions);
    int GetID() const {return m_id;} // TODO : actually it is not using ...
    int GetWidth() const {return m_dimensions.m_width;}
    int GetHeight() const {return m_dimensions.m_height;}
    int GetThickness() const {return m_dimensions.m_cornerThickness;}
    Point GetPosRelative() const {return m_positionRelative;}
    void UpdateRelativePos(int posX, int posY){m_positionRelative = Point(posX, posY);}
    virtual void FillModule(GxEPD&) = 0;

	// void drawLine();
	// void ModuleName(int cornerWidth);
	protected:
    ModuleDimmensions m_dimensions;
    int m_id;

    private:
    Point m_positionRelative;
};

#endif

