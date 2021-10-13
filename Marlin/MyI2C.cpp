#include "Marlin.h"
#include "MyI2C.h"





#ifdef EXPERIMENTAL_I2CBUS

MyI2C::MyI2C()
{
    this->resetbuf();
}


bool MyI2C::MySendI2C_(TWIBus ii2c,uint8_t add)
{
    ii2c.reset();
    ii2c.addstring(I2C_SRBUF);
    ii2c.addr = add;
    if(ii2c.send()!=0)
    {
        SERIAL_ECHOLN("SendI2c Fail");
        return false;
    }
    return true;
}

bool MyI2C::MyReceiveI2C_(TWIBus ii2c,uint8_t add,uint8_t num)
{
    MySendI2C_(ii2c,add);
    ii2c.addr = add;
    if(ii2c.request(num))
    {
        //chu li jie shou de shuju 
        resetbuf();
        ii2c.capture(I2C_SRBUF,num);
    }
    else
    {
        SERIAL_ECHOLN("ReceiveI2c Fail");
        return false;
    }
    return true;
}

void MyI2C::TestMyI2C_(TWIBus ii2c,uint8_t add,uint8_t num,bool SVflag=true)
{
    if(SVflag)
    {
        MySendI2C_(ii2c,add);
    }
    else
    {
        MySendI2C_(ii2c,add);
        ii2c.relay(num);
    }
}

void MyI2C::resetbuf()
{
    memset(I2C_SRBUF,0,TWIBUS_BUFFER_SIZE);
}


#endif 




