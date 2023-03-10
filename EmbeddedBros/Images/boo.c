#include <ti/grlib/grlib.h>
#include <stdint.h>

static const uint8_t pixel_boo[] =
{
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xad, 0xdd, 0xa1, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x4d, 0xff, 0xff, 0xff, 0xfd, 0xdd, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x0d, 0xdf, 0xff, 0xff, 0xff, 0xfd, 0xdd, 0xda, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0xaa, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x0d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdd, 0xdd, 0xda, 0xa0, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xdd, 0xdd, 0xab, 0x00, 0x00, 0x40, 0x00,
 0x00, 0x00, 0x01, 0xdf, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfd, 0xdd, 0xdd, 0xaa, 0x10, 0x0d, 0xd1, 0x00,
 0x00, 0x00, 0x0f, 0xff, 0xf3, 0xff, 0xfd, 0xdf, 0xff, 0xff, 0xff, 0xdd, 0xdd, 0xaa, 0xa3, 0xdf, 0xdb, 0x00,
 0x00, 0x00, 0xaf, 0xff, 0x3f, 0xb0, 0x3f, 0xff, 0xff, 0xfd, 0xdd, 0xdd, 0xda, 0xaa, 0xad, 0xfd, 0xa1, 0x00,
 0x00, 0x00, 0xd7, 0xf0, 0xff, 0xf3, 0x3f, 0xff, 0xff, 0xff, 0xdd, 0xdd, 0xdd, 0xaa, 0xdd, 0xda, 0xbb, 0x00,
 0x00, 0x03, 0xff, 0x33, 0xff, 0xf0, 0x0f, 0xff, 0xfd, 0xdd, 0xdd, 0xdd, 0xda, 0xaa, 0xdd, 0xdb, 0xbb, 0x00,
 0x00, 0x0a, 0xff, 0x33, 0xff, 0xff, 0xff, 0xff, 0xdd, 0xdd, 0xdd, 0xdd, 0xaa, 0xaa, 0xdd, 0xab, 0x13, 0x00,
 0x00, 0x0d, 0xdf, 0xaf, 0xff, 0xff, 0xdd, 0xdd, 0xda, 0xdd, 0xdd, 0xda, 0xaa, 0xaa, 0xaa, 0xb1, 0xb0, 0x00,
 0x00, 0x0d, 0xdf, 0xff, 0xff, 0xff, 0xfd, 0xab, 0x1b, 0xad, 0xdd, 0xaa, 0xaa, 0xab, 0xab, 0x1b, 0xb0, 0x00,
 0x3d, 0xfd, 0xdd, 0xdd, 0xdd, 0xdd, 0xa1, 0xb3, 0x31, 0xaa, 0xdd, 0xda, 0xaa, 0xbb, 0xb1, 0xbb, 0x73, 0x00,
 0x7f, 0xfd, 0xaa, 0xdd, 0xdd, 0xa1, 0x73, 0x1b, 0x61, 0xad, 0xdd, 0xaa, 0xab, 0xab, 0x11, 0x1a, 0x1d, 0xa0,
 0x0d, 0xfa, 0xb7, 0x77, 0x77, 0x77, 0x77, 0xda, 0x37, 0xaa, 0xda, 0xaa, 0xab, 0xb1, 0xb1, 0xbb, 0xba, 0xb0,
 0x03, 0xda, 0xab, 0x0b, 0x61, 0x13, 0xd3, 0x4a, 0x47, 0xaa, 0xaa, 0xaa, 0xab, 0x1b, 0x1b, 0xbb, 0xbb, 0x60,
 0x00, 0x7b, 0xaa, 0x3d, 0x14, 0xd4, 0x44, 0x47, 0x46, 0xda, 0xaa, 0xab, 0xb1, 0xb1, 0x11, 0xbb, 0xba, 0x00,
 0x00, 0x07, 0xaa, 0xa0, 0xa4, 0x44, 0x44, 0x44, 0x43, 0xaa, 0xaa, 0xab, 0x1b, 0x1b, 0x1b, 0xaa, 0xab, 0x00,
 0x00, 0x00, 0xba, 0xd3, 0x34, 0x44, 0x44, 0x44, 0x03, 0xaa, 0xab, 0xb1, 0xb1, 0x11, 0xbb, 0xba, 0xd0, 0x00,
 0x00, 0x00, 0x7a, 0xad, 0x44, 0x44, 0x64, 0x55, 0x47, 0xaa, 0xab, 0x1b, 0x1b, 0x1b, 0xba, 0xad, 0xa0, 0x00,
 0x00, 0x00, 0x0b, 0xad, 0xb4, 0x06, 0x55, 0x55, 0x61, 0xab, 0xb1, 0xb1, 0x11, 0xbb, 0xaa, 0xdd, 0x00, 0x00,
 0x00, 0x00, 0x07, 0xad, 0xd3, 0x4e, 0x59, 0x95, 0x6a, 0xab, 0x1b, 0x1b, 0x1b, 0xaa, 0xad, 0xa3, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x1b, 0xaa, 0x55, 0xe9, 0x95, 0x3a, 0xb1, 0xb1, 0x11, 0xbb, 0xaa, 0xda, 0x30, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x41, 0xba, 0x99, 0x99, 0x95, 0x4b, 0x11, 0x11, 0x1b, 0xba, 0xad, 0xa7, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x03, 0xbe, 0xe9, 0xc9, 0xe5, 0x37, 0x17, 0x11, 0xbb, 0xba, 0xda, 0x30, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x3e, 0xcc, 0x9e, 0x55, 0x71, 0x1b, 0x1b, 0xba, 0xad, 0xa0, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x05, 0xcc, 0xc9, 0x56, 0x11, 0xb1, 0xbb, 0xba, 0xd3, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x0e, 0xcc, 0x9e, 0x56, 0xbb, 0xbb, 0xba, 0xa3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x09, 0xcc, 0xe5, 0x56, 0x71, 0xb1, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x05, 0xee, 0x95, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x04, 0xe9, 0xe5, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x55, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x56, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const uint32_t palette_boo[]=
{
     0x000000,  0x9c9e99,   0xfefefe,   0x31333f,
     0x4c0201,   0xba3d67,   0x772040,   0x707883,
     0xdcebf0,   0xff5294,   0xb1b5c0,   0xa4aeb8,
     0xfe62a1,   0xdcebf2,   0xec6391,   0xffffff
};

const Graphics_Image  boo=
{
    IMAGE_FMT_4BPP_UNCOMP,
    36,
    36,
    16,
    palette_boo,
    pixel_boo,
};

