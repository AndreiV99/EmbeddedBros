#include <ti/grlib/grlib.h>
#include <stdint.h>

static const uint8_t pixel_go[] =
{
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00,
 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x0e, 0x0e, 0x0e, 0x0e, 0x00, 0x0e, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x1b, 0xcf, 0xb3, 0x33, 0x33, 0x3b, 0xf5, 0x00, 0x00, 0xea, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0xbb, 0xfb, 0xa0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x0d, 0xb3, 0x33, 0x33, 0x33, 0x45, 0x00, 0xe0, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfb, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0xfe, 0x00, 0x0f, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x2b, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x22, 0x22, 0x22, 0x22, 0xf5, 0x5e, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xc2, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x2b, 0xd0, 0xf2, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x2b, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0x22, 0xca, 0x10, 0x00, 0x00, 0x00,
 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x0d, 0xb2, 0x22, 0x22, 0x22, 0xbf, 0xff, 0x72, 0x22, 0x22, 0x22, 0x2f, 0x56, 0x32, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x2f, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0x2f, 0x5a, 0xd0, 0x00, 0x0e, 0x00,
 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0xab, 0x22, 0x22, 0x22, 0xbb, 0xaa, 0xa4, 0x22, 0x22, 0x22, 0x22, 0x2b, 0xab, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xbb, 0xb2, 0x22, 0x22, 0x22, 0x22, 0x22, 0x40, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x87, 0x22, 0x22, 0x22, 0x24, 0xa1, 0x00, 0x00, 0x00, 0xe0,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0x2f, 0xaa, 0x55, 0x16, 0x22, 0x22, 0x22, 0x22, 0x2b, 0x51, 0x6a, 0x5a, 0xaa, 0x5a, 0xaa, 0x5a, 0xaa, 0x5a, 0xaa, 0x5a, 0xff, 0x22, 0x22, 0x22, 0x22, 0xb1, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb2, 0x22, 0x22, 0x22, 0xfa, 0x5d, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x22, 0xf5, 0xa5, 0x60, 0x00, 0xf2, 0x22, 0x22, 0x22, 0x2b, 0xa1, 0x61, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x55, 0xc2, 0x22, 0x22, 0x22, 0x2a, 0x60, 0x00, 0x00, 0x00, 0x00, 0xc2, 0x22, 0x22, 0x22, 0xaa, 0x10, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x0e, 0x00, 0x04, 0x22, 0x22, 0x22, 0x2f, 0x5a, 0x5d, 0x00, 0x00, 0x8f, 0x22, 0x22, 0x22, 0xba, 0x56, 0x00, 0x00, 0x00, 0x0f, 0xbb, 0xbb, 0xbb, 0xbf, 0x00, 0x00, 0x0e, 0x6b, 0x22, 0x22, 0x22, 0x2f, 0x50, 0x00, 0x00, 0x0e, 0x00, 0xb2, 0x22, 0x22, 0x2f, 0x5a, 0xe0, 0x0e, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xe0, 0x6b, 0x22, 0x22, 0x22, 0xf5, 0xa5, 0xe0, 0xe0, 0x00, 0x06, 0xfb, 0x22, 0xcb, 0xaa, 0x50, 0xe0, 0x00, 0x00, 0xc2, 0x22, 0x22, 0x22, 0xf5, 0x51, 0x00, 0x00, 0x0b, 0x22, 0x22, 0x22, 0x2b, 0xa0, 0x00, 0x00, 0x00, 0xee, 0x32, 0x22, 0x22, 0x3a, 0xa1, 0x00, 0x00, 0xe0, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x27, 0x4a, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x65, 0xaa, 0x5a, 0xa5, 0xe0, 0x00, 0x00, 0x0d, 0xb2, 0x22, 0x22, 0x2b, 0xaa, 0x5d, 0x00, 0x00, 0x01, 0x22, 0x22, 0x22, 0x2f, 0xa8, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0xfa, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x05, 0x22, 0x22, 0x22, 0x2f, 0xa5, 0xd0, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x15, 0x51, 0x60, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0x2f, 0xa5, 0xd0, 0x00, 0x00, 0x0e, 0x22, 0x22, 0x22, 0x2f, 0xa8, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x23, 0xa5, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x0e, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0x2a, 0x51, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x0b, 0x22, 0x22, 0x22, 0xba, 0x56, 0x00, 0x0e, 0x00, 0x0e, 0x22, 0x22, 0x22, 0x2f, 0x56, 0x0e, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x2f, 0x55, 0xee, 0x00, 0x00, 0x00, 0x0e, 0x00,
 0x00, 0xe0, 0x00, 0x67, 0x22, 0x22, 0x22, 0xca, 0x50, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xc2, 0x22, 0x22, 0x22, 0xca, 0x50, 0x00, 0x00, 0xe0, 0x01, 0x22, 0x22, 0x22, 0x2b, 0xa8, 0x00, 0xe0, 0x00, 0xe2, 0x22, 0x22, 0xb5, 0xa1, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0,
 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x22, 0xfa, 0x10, 0x00, 0x00, 0x00, 0x00, 0xdf, 0xbf, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x2b, 0xaa, 0xe0, 0x00, 0x00, 0x00, 0x04, 0x22, 0x22, 0x22, 0x24, 0x5d, 0x00, 0x00, 0x00, 0xb2, 0x22, 0x22, 0xba, 0x5e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x22, 0xf5, 0x60, 0x00, 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x2f, 0x68, 0x00, 0x00, 0x00, 0xb2, 0x22, 0x22, 0x2f, 0xa5, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0xca, 0x50, 0x00, 0x00, 0x00, 0xf2, 0x22, 0x2b, 0xaa, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x0e, 0xb2, 0x22, 0x22, 0x22, 0xba, 0xe0, 0x00, 0x0e, 0x00, 0x00, 0xb2, 0x22, 0x22, 0x2c, 0x51, 0x0e, 0x00, 0x06, 0x22, 0x22, 0x22, 0x2f, 0x51, 0x0e, 0x00, 0x00, 0x00, 0x0b, 0x22, 0x22, 0x22, 0xfa, 0x10, 0x00, 0x00, 0x0e, 0xb2, 0x22, 0x2f, 0x55, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xc2, 0x22, 0x22, 0x22, 0xc5, 0xe0, 0x00, 0x00, 0xe0, 0x01, 0x22, 0x22, 0x22, 0x35, 0xad, 0x00, 0xe0, 0x01, 0x22, 0x22, 0x22, 0x24, 0xae, 0x00, 0xe0, 0x00, 0x00, 0xc2, 0x22, 0x22, 0x23, 0xa5, 0x60, 0x00, 0x00, 0x0e, 0x22, 0x22, 0xba, 0xa6, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x22, 0xfa, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0xfa, 0x5e, 0x00, 0x00, 0x01, 0x22, 0x22, 0x22, 0x24, 0x50, 0x00, 0x00, 0x00, 0x00, 0xb2, 0x22, 0x22, 0x2f, 0x55, 0xe0, 0x00, 0x00, 0x04, 0x23, 0x27, 0xfa, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x22, 0xf5, 0xd0, 0x00, 0x00, 0x00, 0x0b, 0x22, 0x22, 0x22, 0xca, 0x10, 0x00, 0x00, 0x00, 0x22, 0x22, 0x22, 0x24, 0x50, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x22, 0xca, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x6a, 0xaa, 0xaa, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x0e, 0x00, 0x00, 0x83, 0x22, 0x22, 0x22, 0x2f, 0x6e, 0x00, 0x00, 0x00, 0x52, 0x22, 0x22, 0x2b, 0x5a, 0xe0, 0x00, 0x00, 0x0e, 0xb2, 0x22, 0x22, 0x2c, 0x50, 0x00, 0x00, 0x0e, 0x13, 0x22, 0x22, 0x23, 0x4a, 0x5e, 0x00, 0x0e, 0x00, 0x00, 0xd5, 0x55, 0x51, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00,
 0x00, 0xe0, 0x00, 0x0f, 0x22, 0x22, 0x22, 0x2b, 0xa0, 0xe0, 0x00, 0x00, 0xf2, 0x22, 0x22, 0x2f, 0xa5, 0xe0, 0x00, 0x00, 0x00, 0xc2, 0x22, 0x22, 0x2b, 0xa0, 0x00, 0x00, 0x00, 0xc2, 0x22, 0x22, 0x2b, 0xa5, 0x80, 0x00, 0x00, 0xe0, 0xab, 0xcb, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0,
 0x00, 0x00, 0x00, 0x0d, 0xb2, 0x22, 0x22, 0x22, 0xbf, 0x00, 0x00, 0x00, 0x32, 0x22, 0x22, 0x2c, 0x51, 0x00, 0x00, 0x00, 0x00, 0x12, 0x22, 0x22, 0x22, 0xb6, 0x00, 0x00, 0xef, 0x22, 0x22, 0x23, 0xba, 0xa1, 0x00, 0x00, 0x00, 0x04, 0x22, 0x22, 0x2f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x1b, 0x22, 0x22, 0x22, 0x22, 0xcb, 0x5e, 0x0b, 0x22, 0x22, 0x22, 0xb5, 0xae, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x22, 0x22, 0x22, 0xbb, 0xe0, 0x8f, 0x42, 0x22, 0x22, 0xb4, 0xaa, 0x10, 0x00, 0x00, 0x00, 0x0b, 0x22, 0x22, 0x22, 0x4d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x0e, 0x00, 0x01, 0xb2, 0x22, 0x22, 0x22, 0x22, 0x23, 0x3b, 0x22, 0x22, 0x22, 0xba, 0x5e, 0x00, 0x0e, 0x00, 0x00, 0x0e, 0xf2, 0x22, 0x22, 0x22, 0x3b, 0x22, 0x22, 0x22, 0x2f, 0xaa, 0x51, 0x00, 0x0e, 0x00, 0x00, 0x03, 0x22, 0x22, 0x22, 0xb5, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xe0, 0x00, 0x6a, 0xfb, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x4a, 0x60, 0x00, 0x00, 0xe0, 0x00, 0x00, 0xdb, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x2b, 0xf5, 0xa5, 0x60, 0x00, 0x00, 0xe0, 0x00, 0x0b, 0x22, 0x22, 0x22, 0xc5, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x1a, 0xbf, 0xfb, 0x22, 0x22, 0x22, 0x22, 0x22, 0x2f, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xbf, 0x72, 0x22, 0x22, 0x22, 0x3f, 0xba, 0x5a, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x22, 0x22, 0x2f, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x15, 0xaa, 0xaa, 0x44, 0xf2, 0x22, 0x22, 0x2f, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd1, 0xa4, 0xff, 0xcf, 0xc4, 0xaa, 0xa5, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaf, 0xbf, 0xca, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0xe6, 0x15, 0x5a, 0x22, 0x22, 0x22, 0x3a, 0x56, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x81, 0x5a, 0x5a, 0x5a, 0x55, 0x18, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x01, 0x5a, 0x5a, 0x5e, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00,
 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x0b, 0x22, 0x22, 0x22, 0xf5, 0x50, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0xde, 0x8e, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x61, 0x18, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x22, 0x22, 0x3f, 0x5a, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xab, 0xbb, 0xcf, 0xa5, 0xa1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x5a, 0x5a, 0x55, 0x6e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x11, 0x16, 0x80, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0e, 0x00,
 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xe0,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

static const uint32_t palette_go[]=
{
     0x000000,  0x566b7e,   0xff3f3f,   0xff5151,
     0xe2edf7,   0x95badb,   0x2d3843,   0xff4b4b,
     0x222a32,   0x171c21,   0x9bc1e3,   0xffeeee,
     0xeaf2fa,   0x171c22,   0x161616,   0xffffff
};

const Graphics_Image  go=
{
    IMAGE_FMT_4BPP_UNCOMP,
    100,
    44,
    16,
    palette_go,
    pixel_go,
};
