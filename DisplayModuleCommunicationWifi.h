#ifndef _DisplayModuleCommunicationWifi_H_
#define _DisplayModuleCommunicationWifi_H_
#include "DisplayModuleCommunication.h"
#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

class DisplayModuleCommunicationWifi : public DisplayModuleCommunication 
{
	public:
    DisplayModuleCommunicationWifi() {};
    int sendHttpRequest() {};
    JsonObject getStringResult() {};
    

};


#endif // _DisplayModuleCommunicationWifi_H_
