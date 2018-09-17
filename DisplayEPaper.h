#ifndef _DisplayEPaper_H_
#define _DisplayEPaper_H_

#include <GxEPD.h>
// #include <GxGDEW075Z09/GxGDEW075Z09.cpp>      // 7.5" b/w/r
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
// #include <GxIO/GxIO.cpp>

#include <DisplayModule.h>
#include <vector>
class DisplayEPaper 
{
	public:
	DisplayEPaper(char CS, char DC, char RST);
	// void drawLine();
	// void ModuleName();
	virtual void AddNewModule(DisplayModule* currentModule) = 0;
	// void GetModuleContent();
	// void UpdateModuleContent();
	// void DrawModule(int moduleID);
	//virtual void DrawModules() = 0;
	protected :
	GxEPD* m_GxEPD;
	GxIO_Class* m_io;
	std::vector<DisplayModule*> m_modules;
};

#endif

