#ifndef _DEBUG_H_
#define _DEBUG_H_

#define debbug_on

#ifdef debbug_on
  #define DBG_PRINT(...)    Serial.print(__VA_ARGS__)
  #define DBG_PRINTLN(...)  Serial.println(__VA_ARGS__)
#else
  #define DBG_PRINT(...)
  #define DBG_PRINTLN(...)
#endif

#endif
