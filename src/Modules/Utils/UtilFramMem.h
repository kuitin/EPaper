#ifndef _UtilFramMem_H_
#define _UtilFramMem_H_
//#include "iostream"
#include <vector>
#include "UtilAbstractMem.h"
#include "Adafruit_FRAM_I2C.h"


class UtilFramMem : public UtilAbstractMem
{
    public:  
        UtilFramMem(Adafruit_FRAM_I2C* fram );
        ~UtilFramMem();
        void     write8 (uint16_t framAddr, uint16_t value);
        uint8_t  read8  (uint16_t framAddr);
        void     write16 (uint16_t framAddr, uint16_t value) ;
        uint16_t  read16  (uint16_t framAddr) ;
        void     write32 (uint16_t framAddr, uint32_t value) ;
        uint32_t  read32  (uint16_t framAddr) ;
        int      WriteDouble(uint16_t framAddr, double value); 
        int  ReadDouble  (uint16_t framAddr, double& value) ;

        template <class T> int writeBlock(int address, const T value[], int items)
        {	
            unsigned int i;
            unsigned int newStartAddress = address;
            for (i = 0; i < (unsigned int)items; i++)
                newStartAddress = writeBlock<T>(newStartAddress,value[i]);
            return i;
        }

        /**
         * Template function to write any type of variable, such as structs
        */		
        template <class T> int writeBlock(int address, const T& value)
        {
            int newStartAddress = address;
            byte* valuePtr = (byte*) &value;
            unsigned int sizeValue = sizeof(value);
            for (int i = 0 ; i < sizeValue ; i++) 
            {
                m_fram->write8( newStartAddress, valuePtr[i] ); 
                newStartAddress ++;
            }	  			  
            return newStartAddress;
        }

                /**
         * Template function to write any type of variable, such as structs
        */		
        template <class T> int readBlock(int address,  T& value)
        {
            byte* valuePtr = (byte*) &value;
            int newStartAddress = 0;
            for (int i = 0 ; i < sizeof(value) ; i++) 
            {
                valuePtr[i] = m_fram->read8( newStartAddress );            
                newStartAddress ++;
            }
            return sizeof(value);

        }

    private:
        Adafruit_FRAM_I2C* m_fram  ;
    
};


#endif //_UtilFramMem_H_
