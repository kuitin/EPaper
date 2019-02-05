#ifndef _LogInterface_H_
#define _LogInterface_H_
#include <ArduinoLog.h>

#ifdef PRINT_LOG
static  Logging LogInterface;

#define LOG_DEBUG(...) \
 ( \
  LogInterface.trace(__VA_ARGS__) \
 )




#else // Warrior mode: Log is too easy

#define LOG_DEBUG(X)
#endif // printLog

#endif //_LogInterface_H_
