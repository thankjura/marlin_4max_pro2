#ifndef MyI2C_H
#define MyI2C_H

#include "macros.h"
#include "twibus.h"

class MyI2C
{
    private:
    uint8_t temp=0;
    
    public:
    uint8_t I2C_SRBUF[TWIBUS_BUFFER_SIZE];
    uint8_t addr = 0x01;
    
    bool MyReceiveI2C_(TWIBus ii2c,uint8_t add,uint8_t num);
    bool MySendI2C_(TWIBus ii2c,uint8_t add);
    void TestMyI2C_(TWIBus ii2c,uint8_t add,uint8_t num,bool SVflag=true);
    void resetbuf();
    MyI2C();
    
};

#endif
