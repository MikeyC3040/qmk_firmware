#include "i2c_lcd.h"
#include <util/delay.h>


void lcd_init(){
    /* Initialize i2c and MCP23017 */
    mcp23017_init();

    /* run through LCD setup */
    /* Pseduo Code:
    Set LCD inputs, outputs, and pullups
    call backlight function to set it on */
    mcp23017_pinModes(0x001f);
    mcp23017_pullUps(0x001f);

}


void lcd_setBacklight(uint8_t) {

}
