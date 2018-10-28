
/*******************************************************************************
* image
* filename: unsaved
* name: wi-rain
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



static const uint8_t image_data_wirain[630] = {
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x50, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xfe, 0x9f, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xf8, 0x03, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xe0, 0x00, 0xf8, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xc0, 0x00, 0x78, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x80, 0x00, 0x7c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x80, 0x00, 0x3c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 
    0x00, 0x01, 0xfe, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 
    0x00, 0x03, 0xfe, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 
    0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 
    0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 
    0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x0e, 0x0c, 0x1c, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x1e, 0x1e, 0x1e, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x1e, 0x1e, 0x1c, 0x01, 0xe0, 0x00, 
    0x00, 0x0f, 0x00, 0x1e, 0x3e, 0x3c, 0x03, 0xc0, 0x00, 
    0x00, 0x0f, 0x80, 0x3c, 0x3c, 0x3c, 0x07, 0xc0, 0x00, 
    0x00, 0x07, 0x80, 0x3c, 0x3c, 0x3c, 0x0f, 0x80, 0x00, 
    0x00, 0x07, 0xe0, 0x3c, 0x3c, 0x78, 0x3f, 0x80, 0x00, 
    0x00, 0x03, 0xfc, 0x78, 0x78, 0x78, 0xff, 0x00, 0x00, 
    0x00, 0x01, 0xfc, 0x78, 0x78, 0x79, 0xfc, 0x00, 0x00, 
    0x00, 0x00, 0x7e, 0x78, 0x78, 0x70, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x1c, 0x78, 0xf0, 0xf1, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xf0, 0xf1, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xe1, 0xe1, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xe1, 0xe1, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xe1, 0xe0, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage wirain = { image_data_wirain, 70, 70,
    8 };

