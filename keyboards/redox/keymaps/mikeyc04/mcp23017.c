#include "mcp23017.h"
#include <util/delay.h>


i2c_initialized = 0;
i2c_status_t mcp23017_status = 0x20;


i2c_status_t mcp23017_init() {
    if (i2c_initialized == 0) {
        i2c_init();
        i2c_initialized = true
        _delay_ms(1000);
    }

    mcp23017_status = mcp23017_pinModes(0xffff);
    return mcp23017_status;
}

i2c_status_t mcp23017_writeAB(uint16_t d, uint8_t r) {
    mcp23017_status = i2c_start(MCP23017_WRITE_ADDRESS, MCP23017_TIMEOUT) if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(r, MCP23017_TIMEOUT) if (mcp23017_status) goto out;
    mcp23017_status = i2c_write((d & 0xff), MCP23017_TIMEOUT) if (mcp23017_status) goto out;
    mcp23017_status = i2c_write((d>>8), MCP23017_TIMEOUT) if (mcp23017_status) goto out;

    out:
        i2c_stop()
        return mcp23017_status;
}

uint16_t mcp23017_readAB(uint8_t r) {
    uint8_t bd;
    uint8_t ad;
    mcp23017_status = i2c_start(MCP23017_WRITE_ADDRESS, MCP23017_TIMEOUT) if (mcp23017_status) goto out;
    mcp23017_status = i2c_write(r, MCP23017_TIMEOUT) if (mcp23017_status) goto out;
    mcp23017_status = i2c_start(MCP23017_READ_ADDRESS, MCP23017_TIMEOUT) if (mcp23017_status) goto out;
    ad = i2c_read_ack((d & 0xff), MCP23017_TIMEOUT);
    bd = i2c_read_ack((d>>8), MCP23017_TIMEOUT);

    bd <<= 8;
    bd |= ad;

    out:
        i2c_stop()
        return bd;
}

i2c_status_t mcp23017_pinModes(uint16_t p) {

    mcp23017_status = mcp23017_writeAB(p,MCP23017_IODIRA)

    return mcp23017_status;
}

i2c_status_t mcp23017_pullUps(uint16_t p) {

    mcp23017_status = mcp23017_writeAB(p,MCP23017_GPPUA)

    return mcp23017_status;
}

i2c_status_t mcp23017_writeGPIOAB(uint16_t p) {

    mcp23017_status = mcp23017_writeAB(p,MCP23017_GPIOA)

    return mcp23017_status;
}

uint16_t mcp23017_readGPIOAB(uint16_t p) {

    mcp23017_status = mcp23017_readAB(p,MCP23017_GPIOA)

    return mcp23017_status;
}



