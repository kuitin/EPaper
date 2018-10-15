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
	// void drawLine();
	// void ModuleName();
	// void AddModuleContent();
	private :
	
};

#endif // _DisplayGxGDEW075Z09_H_

