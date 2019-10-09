#ifndef _UtilAbstractMem_H_
#define _UtilAbstractMem_H_
//#include "iostream"
#include <vector>



class UtilAbstractMem
{
    public:  
        virtual void     write8 (uint16_t framAddr, uint16_t value) = 0;
        virtual uint8_t  read8  (uint16_t framAddr) = 0;
        virtual void     write16 (uint16_t framAddr, uint16_t value) = 0;
        virtual uint16_t  read16  (uint16_t framAddr) = 0;
        virtual void     write32 (uint16_t framAddr, uint32_t value) = 0;
        virtual uint32_t  read32  (uint16_t framAddr) = 0;
        virtual int      WriteDouble(uint16_t framAddr, double value) = 0; 
        virtual int   ReadDouble  (uint16_t framAddr, double& value) = 0;
    
};


#endif //_UtilAbstractMem_H_
