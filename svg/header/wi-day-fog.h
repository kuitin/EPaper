
/*******************************************************************************
* image
* filename: unsaved
* name: wi-day-fog
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Diffuse Dither 128
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



static const uint8_t image_data_widayfog[630] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1c, 0x00, 0x3c, 0x00, 0x1c, 0x00, 
    0x00, 0x00, 0x00, 0x3c, 0x00, 0x08, 0x00, 0x3c, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x7e, 0x00, 
    0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0xfc, 0x00, 
    0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x01, 0xf0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xc0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x2f, 0x07, 0xff, 0xf0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xef, 0xff, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xff, 0x80, 0xfc, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x7e, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0xe1, 0xfe, 0x00, 0x1e, 0x00, 0x00, 
    0x00, 0x00, 0x3f, 0x00, 0x3f, 0x00, 0x1f, 0x00, 0x00, 
    0x00, 0x00, 0x3e, 0x00, 0x0f, 0x80, 0x0f, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x00, 0x0f, 0x80, 0x0f, 0x00, 0x00, 
    0x00, 0x00, 0xf8, 0x00, 0x07, 0xc0, 0x07, 0x07, 0xf0, 
    0x00, 0x00, 0xf0, 0x00, 0x03, 0xc0, 0x07, 0x87, 0xf8, 
    0x00, 0x00, 0xf0, 0x00, 0x01, 0xc0, 0x0f, 0x07, 0xf8, 
    0x00, 0x01, 0xe0, 0x00, 0x01, 0xfe, 0x07, 0x07, 0xf0, 
    0x00, 0x0f, 0xf0, 0x00, 0x01, 0xff, 0x8f, 0x00, 0x00, 
    0x00, 0x1f, 0xe0, 0x00, 0x01, 0xff, 0xef, 0x00, 0x00, 
    0x00, 0x3f, 0xe0, 0x00, 0x01, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x7e, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 
    0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 
    0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 
    0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 
    0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x38, 0x00, 
    0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7c, 0x00, 
    0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x7c, 0x00, 
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3c, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x3f, 0xff, 0xfe, 0xed, 0xb6, 0xda, 0x00, 0x00, 0x00, 
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x05, 0x25, 0x55, 0x5a, 0xd5, 0x55, 0x00, 0x00, 
    0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 
    0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
    0x00, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
    0x00, 0x00, 0x48, 0x11, 0x22, 0x12, 0x44, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage widayfog = { image_data_widayfog, 70, 70,
    8 };

