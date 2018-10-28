
/*******************************************************************************
* image
* filename: unsaved
* name: wi-day-rain-wind
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



static const uint8_t image_data_widayrainwind[630] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
    0x00, 0x00, 0x01, 0xf0, 0x00, 0x40, 0x01, 0xf0, 0x00, 
    0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x03, 0xf0, 0x00, 
    0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x07, 0xe0, 0x00, 
    0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x07, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x07, 0xfc, 0x06, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x68, 0x3f, 0xff, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0x7f, 0xff, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0xff, 0xfc, 0x07, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xff, 0xf0, 0x01, 0xf0, 0x00, 0x00, 
    0x00, 0x00, 0xfe, 0x0f, 0xf0, 0x01, 0xf8, 0x00, 0x00, 
    0x00, 0x01, 0xf8, 0x01, 0xf8, 0x00, 0x78, 0x00, 0x00, 
    0x00, 0x01, 0xf0, 0x00, 0x7c, 0x00, 0x78, 0x00, 0x00, 
    0x00, 0x03, 0xe0, 0x00, 0x7c, 0x00, 0x7c, 0x00, 0x00, 
    0x00, 0x07, 0xc0, 0x00, 0x1e, 0x00, 0x38, 0x1f, 0x80, 
    0x00, 0x07, 0x80, 0x00, 0x1e, 0x00, 0x3c, 0x3f, 0xc0, 
    0x00, 0x07, 0x80, 0x00, 0x1f, 0x00, 0x3c, 0x3f, 0xe0, 
    0x00, 0x1f, 0x00, 0x00, 0x0f, 0xe0, 0x3c, 0x3f, 0xc0, 
    0x00, 0x7f, 0x00, 0x00, 0x0f, 0xfc, 0x78, 0x00, 0x00, 
    0x00, 0xff, 0x00, 0x00, 0x0f, 0xff, 0x78, 0x00, 0x00, 
    0x01, 0xff, 0x00, 0x00, 0x0f, 0xff, 0xf8, 0x00, 0x00, 
    0x03, 0xf0, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 
    0x07, 0xc0, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x00, 
    0x07, 0x80, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 
    0x0f, 0x80, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 
    0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 
    0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0xc0, 0x00, 
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0xe0, 0x00, 
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe1, 0xe0, 0x00, 
    0x0f, 0x80, 0x00, 0x00, 0x00, 0x01, 0xe1, 0xf0, 0x00, 
    0x07, 0x80, 0x01, 0x80, 0xe0, 0x03, 0xe0, 0xe0, 0x00, 
    0x07, 0xe0, 0x03, 0xc0, 0xe0, 0x07, 0xc0, 0x00, 0x00, 
    0x03, 0xf0, 0x07, 0xc1, 0xe0, 0x0f, 0x80, 0x00, 0x00, 
    0x01, 0xfe, 0x0f, 0x83, 0xe0, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0xfc, 0x1f, 0x07, 0xc1, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x78, 0x1f, 0x0f, 0x83, 0xfc, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3e, 0x1f, 0x87, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x1f, 0x0f, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x78, 0x3e, 0x0f, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x70, 0x7c, 0x1f, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xf8, 0x3e, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xf0, 0x3c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x07, 0x01, 0xf0, 0x38, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x07, 0x03, 0xe0, 0x10, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x0f, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x06, 0x03, 0x81, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3c, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage widayrainwind = { image_data_widayrainwind, 70, 70,
    8 };

