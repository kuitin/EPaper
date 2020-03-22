#ifndef _UtilAbstractMem_H_
#define _UtilAbstractMem_H_
#include "iostream"


 #include "Modules/DisplayModuleCommunicationWifi.h"



class UtilAbstractMem
{
    public:  
        virtual uint16_t     write8 (uint16_t framAddr, uint8_t value) = 0;
        virtual uint16_t  read8  (uint16_t framAddr, uint8_t& value) = 0;
        virtual void     write16 (uint16_t framAddr, uint16_t value) = 0;
        virtual uint16_t  read16  (uint16_t framAddr) = 0;
        virtual uint16_t     writeU32 (uint16_t framAddr, uint32_t value) = 0;
        virtual uint16_t  readU32  (uint16_t framAddr, uint32_t& value) = 0;
        virtual uint16_t      WriteDouble(uint16_t framAddr, double value) = 0; 
        virtual uint16_t   ReadDouble  (uint16_t framAddr, double& value) = 0;
        virtual   uint16_t     writeInt (uint16_t framAddr, int value) = 0;
        virtual uint16_t   readInt  (uint16_t framAddr, int & result)  = 0;
        virtual   uint16_t     WriteBool(uint16_t framAddr, bool value) = 0;
        virtual uint16_t   ReadBool  (uint16_t framAddr, bool & result)  = 0;

        virtual   uint16_t  WriteString(uint16_t framAddr, const String & value) = 0;
        virtual   uint16_t  WriteString2(uint16_t framAddr, const String & value) = 0;
        virtual uint16_t   ReadString  (uint16_t framAddr, String & result)  = 0;
        virtual uint16_t   ReadString2  (uint16_t framAddr, String & result)  = 0;
    
};


#endif //_UtilAbstractMem_H_
