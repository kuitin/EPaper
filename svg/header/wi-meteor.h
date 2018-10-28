
/*******************************************************************************
* image
* filename: unsaved
* name: wi-meteor
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



static const uint8_t image_data_wimeteor[630] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x04, 0x7c, 0x10, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x08, 0xfc, 0x70, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x1b, 0xf8, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x3b, 0xf1, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x7f, 0xf7, 0xc0, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xff, 0xf7, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x07, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0x40, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xff, 0xf9, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xff, 0xff, 0xfb, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xff, 0xf7, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0xc5, 0xff, 0xfe, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1e, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1c, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x38, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x78, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x70, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x70, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x60, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf0, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x60, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x70, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x60, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x70, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x78, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x38, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1e, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 
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
const tImage wimeteor = { image_data_wimeteor, 70, 70,
    8 };

