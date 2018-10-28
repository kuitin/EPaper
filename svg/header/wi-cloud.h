
/*******************************************************************************
* image
* filename: unsaved
* name: wi-cloud
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



static const uint8_t image_data_wicloud[630] = {
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
    0x00, 0x00, 0x00, 0x02, 0xe8, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xfe, 0x0f, 0xe0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0xf0, 0x03, 0xf0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x03, 0xe0, 0x00, 0xf8, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0xc0, 0x00, 0x7c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x80, 0x00, 0x3c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x80, 0x00, 0x3c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3f, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 
    0x00, 0x01, 0xfe, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 
    0x00, 0x03, 0xfe, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 
    0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 
    0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 
    0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 
    0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 
    0x00, 0x0f, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 
    0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x1f, 0x80, 0x00, 
    0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
    0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 
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
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage wicloud = { image_data_wicloud, 70, 70,
    8 };

