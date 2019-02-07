#ifndef _DisplayGxGDEW075Z09_H_
#define _DisplayGxGDEW075Z09_H_
#include "DisplayEPaper.h"

#include <GxGDEW075Z09/GxGDEW075Z09.h>      // 7.5" b/w/r
class DisplayGxGDEW075Z09 : public DisplayEPaper 
{
	public:
	DisplayGxGDEW075Z09(char CS, char DC, char RST, char Busy);

	void DrawModules();
	void Init();
	void InitWithLog(int logLevel, Print *output);
	// void drawLine();
	// void ModuleName();
	// void AddModuleContent();
	private :
	
};

#ifndef EPaper_Class
#define EPaper_Class DisplayGxGDEW075Z09
#endif

#endif // _DisplayGxGDEW075Z09_H_

