#ifndef _UtilGoogle_H_
#define _UtilGoogle_H_
#include <Modules/DisplayModule.h>
//#include "iostream"




class UtilGoogle
{
    public:  
    
    static String GetDataGoogleScript(const String& url, String & error);
    static String ConvertASCIIToUTF8(const String& stAscii);
};


#endif //_UtilGoogle_H_
