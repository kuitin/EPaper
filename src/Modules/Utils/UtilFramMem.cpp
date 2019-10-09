#include <Modules/Utils/UtilFramMem.h>

UtilFramMem::UtilFramMem(Adafruit_FRAM_I2C* fram )
{
    m_fram = fram;
}
UtilFramMem::~UtilFramMem( )
{
    m_fram = nullptr;
}
void     UtilFramMem::write8 (uint16_t framAddr, uint16_t value) 
{

}
uint8_t  UtilFramMem::read8  (uint16_t framAddr) 
{
    uint8_t result;

    return result;
}
void     UtilFramMem::write16 (uint16_t framAddr, uint16_t value) 
{
    
}
uint16_t  UtilFramMem::read16  (uint16_t framAddr) 
{
    uint16_t result;

    return result;
}
void     UtilFramMem::write32 (uint16_t framAddr, uint32_t value) 
{
    
}
uint32_t  UtilFramMem::read32  (uint16_t framAddr) 
{
    uint32_t result;

    return result;
}

int  UtilFramMem::WriteDouble(uint16_t framAddr, double value)
{
    return writeBlock<double>(framAddr, value);
    // int newStartAddress = framAddr;
    // byte* doublePtr = (byte*) &value;
    // for (int i = 0 ; i < 2 ; i++) 
    // {
    //     m_fram->write8( newStartAddress, doublePtr[i] ); 
    //     newStartAddress ++;
    // }
    // return newStartAddress;
}

int  UtilFramMem::ReadDouble  (uint16_t framAddr, double & result) 
{
    int frameAddrUpdated = framAddr;
    frameAddrUpdated = readBlock<double>(framAddr,  result);


    // int newStartAddress = framAddr;
    // double result = 0;

    // byte* doublePtr = (byte*) &result;
    // for (int i = 0 ; i < 2 ; i++) 
    // {
    //     doublePtr[i] = m_fram->read8( newStartAddress ); 
    //     newStartAddress ++;
    // }

    return frameAddrUpdated;
}