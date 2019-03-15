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
    int m_width;
    int m_height;    
    int m_cornerThickness;
};



class DisplayModule 
{
	public:
    explicit DisplayModule(int cornerThickness, int width, int height);
    int GetID() const {return m_id;} // TODO : actually it is not using ...
    int GetWidth() const {return m_width;}
    int GetHeight() const {return m_height;}
    int GetThickness() const {return m_cornerThickness;}
    Point GetPosRelative() const {return m_positionRelative;}
    void UpdateRelativePos(int posX, int posY){m_positionRelative = Point(posX, posY);}
    virtual void FillModule(GxEPD&) = 0;

	// void drawLine();
	// void ModuleName(int cornerWidth);
	protected:
    int m_width;
    int m_height;    
    int m_cornerThickness;
    int m_id;

    private:
    Point m_positionRelative;
};

#endif

