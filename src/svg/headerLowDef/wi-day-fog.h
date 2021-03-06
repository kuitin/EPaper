
/*******************************************************************************
* image
* filename: unsaved
* name: wi-day-fog
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Edge 128
* bits per pixel: 1
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: forward
*  inverse: yes
*******************************************************************************/

/*
 typedef struct {
     const uint8_t *data;
     uint16_t width;
     uint16_t height;
     uint8_t dataSize;
     } tImage;
*/
#include <stdint.h>



static const uint8_t image_data_widayfog_Low[120] = {
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x30, 0x00, 
    0x00, 0x00, 0x30, 0x00, 
    0x00, 0x00, 0x30, 0x00, 
    0x00, 0x18, 0x00, 0x60, 
    0x00, 0x08, 0x00, 0xc0, 
    0x00, 0x00, 0x30, 0x80, 
    0x00, 0x08, 0xfc, 0x00, 
    0x00, 0x7f, 0x86, 0x00, 
    0x00, 0xe3, 0x83, 0x00, 
    0x01, 0x80, 0xc3, 0x00, 
    0x01, 0x80, 0xc1, 0x3c, 
    0x03, 0x00, 0x7b, 0x00, 
    0x0f, 0x00, 0x7f, 0x00, 
    0x0c, 0x00, 0x06, 0x00, 
    0x18, 0x00, 0x02, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x1f, 0xff, 0xfe, 0x40, 
    0x1f, 0xff, 0xfe, 0x60, 
    0x00, 0x00, 0x00, 0x00, 
    0x7f, 0xff, 0xf0, 0x00, 
    0x7f, 0xff, 0xf0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x07, 0xff, 0xff, 0x80, 
    0x07, 0xff, 0xff, 0x80, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00
};
const tImage widayfog_Low = { image_data_widayfog_Low, 30, 30,
    8 };

