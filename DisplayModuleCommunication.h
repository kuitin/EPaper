#ifndef _DisplayModuleCommunication_H_
#define _DisplayModuleCommunication_H_

#include <ArduinoJson.h>

// Maybe do template
class DisplayModuleCommunication 
{
	public:
    DisplayModuleCommunication( ) {};
    int sendHttpRequest() ;
    JsonObject getStringResult() ;
    

};


#endif // _DisplayModuleCommunication_H_
