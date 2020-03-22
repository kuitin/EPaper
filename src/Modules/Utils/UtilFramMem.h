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
        uint16_t     write8 (uint16_t framAddr, uint8_t value);
        uint16_t  read8  (uint16_t framAddr, uint8_t& value);
        void     write16 (uint16_t framAddr, uint16_t value) ;
        uint16_t  read16  (uint16_t framAddr) ;
        uint16_t     writeU32 (uint16_t framAddr, uint32_t value) ;
        uint16_t   readU32  (uint16_t framAddr, uint32_t & result)  ;
        uint16_t     writeInt (uint16_t framAddr, int value) ;
        uint16_t   readInt  (uint16_t framAddr, int & result)  ;
        uint16_t      WriteDouble(uint16_t framAddr, double value); 
        uint16_t  ReadDouble  (uint16_t framAddr, double& value) ;
        uint16_t      WriteBool(uint16_t framAddr, bool value); 
        uint16_t  ReadBool  (uint16_t framAddr, bool& value) ;
        uint16_t  WriteString(uint16_t framAddr, const String & value);
        uint16_t  WriteString2(uint16_t framAddr, const String & value);
        uint16_t   ReadString  (uint16_t framAddr, String & result);
        uint16_t   ReadString2  (uint16_t framAddr, String & result);

        template <class T> uint16_t writeBlock(uint16_t address, const T value[], int items)
        {	
            unsigned int i;
            uint16_t newStartAddress = address;
            // Serial.print("writeBlock \n"); 
            // Serial.print(items); 
            // Serial.print("\n"); 
            newStartAddress = writeInt (newStartAddress, items) ;
            for (i = 0; i < (unsigned int)items; i++)
            {
                newStartAddress = writeBlock<T>(newStartAddress,value[i]);
                // Serial.print(value[i]); 
                // Serial.print(" new address : "); Serial.print(newStartAddress); 
                // Serial.print("\n"); 
            }
            return i;
        }

        template <class T> T* readArrayBlock(uint16_t& address,  int& items)
        {	
            unsigned int i;
            items = 0;
            address = readInt (address, items) ;
            Serial.print("readArrayBlock items count : "); Serial.print(items);Serial.print("\n"); 
            T* result = new T((unsigned int)items);
            
            
            for (i = 0; i < (unsigned int)items; i++)
            {
                result[i] = 0;
                result[i] = m_fram->read8( address );  
                address ++;                          
                
                //address = readBlock<T>( address, temp );
                Serial.print("address : "); Serial.print(address);Serial.print("\n"); 
            }
            return result;
        }

        /**
         * Template function to write any type of variable, such as structs
        */		
        template <class T> uint16_t writeBlock(uint16_t address, const T& value)
        {
            uint16_t newStartAddress = address;
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
        template <class T> uint16_t readBlock(uint16_t address,  T& value)
        {
            byte* valuePtr = (byte*) &value;
            uint16_t newStartAddress = address;
            for (int i = 0 ; i < sizeof(value) ; i++) 
            {
                valuePtr[i] = m_fram->read8( newStartAddress );            
                newStartAddress ++;
            }
            return newStartAddress;

        }

    private:
        Adafruit_FRAM_I2C* m_fram  ;
    
};


#endif //_UtilFramMem_H_
