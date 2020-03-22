#include <Modules/Utils/UtilFramMem.h>

UtilFramMem::UtilFramMem(Adafruit_FRAM_I2C* fram )
{
    m_fram = fram;
}
UtilFramMem::~UtilFramMem( )
{
    m_fram = nullptr;
}
uint16_t     UtilFramMem::write8 (uint16_t framAddr, uint8_t value) 
{
    return writeBlock<uint8_t>(framAddr, value);
}
uint16_t  UtilFramMem::read8  (uint16_t framAddr, uint8_t& result) 
{
    int frameAddrUpdated = framAddr;
    frameAddrUpdated = readBlock<uint8_t>(framAddr,  result);

    return frameAddrUpdated;
}
void     UtilFramMem::write16 (uint16_t framAddr, uint16_t value) 
{
    
}
uint16_t  UtilFramMem::read16  (uint16_t framAddr) 
{
    uint16_t result;

    return result;
}
uint16_t     UtilFramMem::writeU32 (uint16_t framAddr, uint32_t value) 
{
    return writeBlock<uint32_t>(framAddr, value);
}
uint16_t  UtilFramMem::readU32  (uint16_t framAddr, uint32_t & result) 
{
    int frameAddrUpdated = framAddr;
    frameAddrUpdated = readBlock<uint32_t>(framAddr,  result);

    return frameAddrUpdated;
}
uint16_t     UtilFramMem::writeInt (uint16_t framAddr, int value) 
{
    return writeBlock<int>(framAddr, value);
}
uint16_t  UtilFramMem::readInt  (uint16_t framAddr, int & result) 
{
    int frameAddrUpdated = framAddr;
    frameAddrUpdated = readBlock<int>(framAddr,  result);

    return frameAddrUpdated;
}

uint16_t     UtilFramMem::WriteBool (uint16_t framAddr, bool value) 
{
    return writeBlock<bool>(framAddr, value);
}
uint16_t  UtilFramMem::ReadBool  (uint16_t framAddr, bool & result) 
{
    uint16_t frameAddrUpdated = framAddr;
    frameAddrUpdated = readBlock<bool>(framAddr,  result);

    return frameAddrUpdated;
}


uint16_t  UtilFramMem::WriteDouble(uint16_t framAddr, double value)
{
    return writeBlock<double>(framAddr, value);
}

uint16_t  UtilFramMem::ReadDouble  (uint16_t framAddr, double & result) 
{
    uint16_t frameAddrUpdated = framAddr;
    frameAddrUpdated = readBlock<double>(framAddr,  result);
    return frameAddrUpdated;
}

uint16_t  UtilFramMem::WriteString(uint16_t framAddr, const String& value)
{
    return writeBlock<char>(framAddr, value.c_str(), value.length());
}

uint16_t  UtilFramMem::ReadString  (uint16_t framAddr, String & result) 
{
    int caracterCount = 0;
    uint16_t framAddrResult = framAddr;
    char*  resultStr = nullptr;
    resultStr = readArrayBlock<char>(framAddrResult, caracterCount);
    result = resultStr; 
    // the string will delete the pointer.

    return framAddrResult;
}

uint16_t  UtilFramMem::ReadString2  (uint16_t framAddr, String & result) 
{
    unsigned int i;
    int  items= 0;
    framAddr = readInt (framAddr, items) ;
    
    for (i = 0; i < (unsigned int)items; i++)
    {
        result += (char) m_fram->read8( framAddr );        
        framAddr ++;  
    }

    return framAddr;
}

uint16_t  UtilFramMem::WriteString2(uint16_t framAddr, const String& value)
{  

    unsigned int i = 0;
    uint16_t newStartAddress = framAddr;
    newStartAddress = writeInt (newStartAddress, value.length()) ;
    for (i = 0; i < (unsigned int)value.length(); i++)
    {
        m_fram->write8( newStartAddress, value.c_str()[i]); 
        newStartAddress++;
    }
    return newStartAddress;
}
       