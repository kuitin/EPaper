
/*******************************************************************************
* image
* filename: unsaved
* name: wi-lightning
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



static const uint8_t image_data_wilightning[630] = {
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x2a, 0xa0, 0x3f, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xe0, 0x7f, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xe0, 0x7e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xc0, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xc0, 0xfc, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0x80, 0xff, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0x01, 0xff, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0x01, 0xff, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xfe, 0x01, 0x5f, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xfe, 0x00, 0x0f, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xfc, 0x00, 0x1f, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xfc, 0x00, 0x1e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xf8, 0x00, 0x3c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xf8, 0x00, 0x3c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xf0, 0x38, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xe0, 0x70, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xff, 0xc0, 0x70, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0xff, 0xc0, 0x60, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1d, 0xff, 0x80, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0x00, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7e, 0x01, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7e, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7c, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage wilightning = { image_data_wilightning, 70, 70,
    8 };

