
/*******************************************************************************
* image
* filename: unsaved
* name: wi-day-haze
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



static const uint8_t image_data_widayhaze_Low[120] = {
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x03, 0x00, 0x00, 
    0x00, 0x03, 0x00, 0x00, 
    0x00, 0x03, 0x00, 0x00, 
    0x01, 0x80, 0x06, 0x00, 
    0x00, 0xc0, 0x0c, 0x00, 
    0x00, 0x40, 0x08, 0x00, 
    0x00, 0x0f, 0xc0, 0x00, 
    0x00, 0x1f, 0xe0, 0x00, 
    0x00, 0x38, 0x70, 0x00, 
    0x00, 0x30, 0x30, 0x00, 
    0x0f, 0x30, 0x33, 0x80, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0xfc, 0xbc, 0x00, 
    0x00, 0xfe, 0xbc, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x5f, 0x70, 0x00, 
    0x00, 0x5f, 0x70, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00
};
const tImage widayhaze_Low = { image_data_widayhaze_Low, 30, 30,
    8 };

