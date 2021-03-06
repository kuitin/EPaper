
/*******************************************************************************
* image
* filename: unsaved
* name: wi-cloud
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



static const uint8_t image_data_wicloud_Low[120] = {
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x06, 0x00, 0x00, 
    0x00, 0x1f, 0xc0, 0x00, 
    0x00, 0x38, 0xe0, 0x00, 
    0x00, 0x60, 0x70, 0x00, 
    0x00, 0x60, 0x30, 0x00, 
    0x01, 0xc0, 0x3e, 0x00, 
    0x03, 0xc0, 0x1f, 0x00, 
    0x06, 0x00, 0x01, 0x80, 
    0x06, 0x00, 0x01, 0x80, 
    0x04, 0x00, 0x00, 0x80, 
    0x04, 0x00, 0x00, 0x80, 
    0x06, 0x00, 0x01, 0x80, 
    0x07, 0x00, 0x03, 0x80, 
    0x03, 0xff, 0xff, 0x00, 
    0x00, 0xff, 0xfc, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00
};
const tImage wicloud_Low = { image_data_wicloud_Low, 30, 30,
    8 };

