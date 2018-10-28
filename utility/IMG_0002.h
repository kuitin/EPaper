#ifndef _GxIMAGE02_H_
#define _GxIMAGE02_H_

#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

// 180 x 64 (Boot)
const unsigned char gImage_IMG_0002[682] PROGMEM= {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x10, 0x00, 0x03, 0xc0, 0x00, 0x08, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7c, 0x00, 0x03, 0xe0, 0x00, 0x1e, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7e, 0x00, 0x01, 0x80, 0x00, 0x3e, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x01, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7e, 0x83, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xe7, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x1f, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3f, 0xff, 0xff, 0xe0, 0x03, 0xf8, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xff, 0xff, 0x80, 0x01, 0xfc, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x80, 0xff, 0x80, 0x00, 0xfc, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0xfe, 0x00, 0x1f, 0xe0, 0x00, 0x7c, 0x00, 0x00, 0x00, 
    0x00, 0x03, 0xf8, 0x00, 0x0f, 0xe0, 0x00, 0x3e, 0x00, 0x00, 0x00, 
    0x00, 0x03, 0xf0, 0x00, 0x03, 0xf0, 0x00, 0x3e, 0x00, 0x00, 0x00, 
    0x00, 0x07, 0xe0, 0x00, 0x03, 0xf0, 0x00, 0x3e, 0x00, 0x00, 0x00, 
    0x00, 0x07, 0xc0, 0x00, 0x01, 0xf8, 0x00, 0x1f, 0x03, 0xfc, 0x00, 
    0x00, 0x0f, 0xc0, 0x00, 0x00, 0xf8, 0x00, 0x3e, 0x07, 0xff, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0xfc, 0x00, 0x1f, 0x07, 0xff, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0x7c, 0x80, 0x1f, 0x07, 0xfe, 0x00, 
    0x00, 0x3f, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x3e, 0x01, 0x54, 0x00, 
    0x01, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xfc, 0x3f, 0x00, 0x00, 0x00, 
    0x03, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x3e, 0x00, 0x00, 0x00, 
    0x07, 0xff, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x0f, 0xfc, 0x00, 0x00, 0x00, 0x12, 0xff, 0xfc, 0x00, 0x00, 0x00, 
    0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 
    0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x00, 
    0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 
    0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 
    0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x78, 0x00, 0x00, 
    0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7c, 0x00, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0x00, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x7e, 0x00, 0x00, 
    0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x3e, 0x00, 0x00, 
    0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x1e, 0x00, 0x00, 
    0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 
    0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0x00, 
    0x1f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 0x00, 
    0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
    0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
    0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x0b, 0xbb, 0x6d, 0xb6, 0xdb, 0x80, 0x00, 0x00, 0x00, 0x00
};
#endif

