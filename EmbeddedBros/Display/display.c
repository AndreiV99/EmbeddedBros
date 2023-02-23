#include "display.h"


Graphics_Context g_sContext;
Graphics_Context dev;

void _graphicsInit()
{
    /* Initializes display */
    Crystalfontz128x128_Init();
    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
    /* Initializes graphics contexts (g_sContext and dev) */
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    Graphics_initContext(&dev, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    /* Initializes foreground color (g_sContext and dev) */
    Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_RED);
    Graphics_setForegroundColor(&dev, GRAPHICS_COLOR_RED);
    /* Initializes graphics background color */
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_BLACK);
    /* Initializes graphics fonts (g_sContext and dev) */
    GrContextFontSet(&g_sContext, &g_sFontCmss16b );
    GrContextFontSet(&dev, &g_sFontCmss12 );
}

void _setDisplay(){
    Graphics_clearDisplay(&g_sContext);
    Graphics_clearDisplay(&dev);
    Graphics_drawStringCentered(&g_sContext, (int8_t *)"EmbeddedBros", AUTO_STRING_LENGTH, 64, 30, OPAQUE_TEXT);
    Graphics_drawStringCentered(&dev, (int8_t *)"Devs: Andrei - Hafsa", AUTO_STRING_LENGTH, 64, 120, OPAQUE_TEXT);
}
