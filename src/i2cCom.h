#ifndef i2cCom_h
#define i2cCom_h

#include <Arduino.h>

class i2cCom
{
private:
    int _address;

public:
    word readTwoBytes(int regAddr);
    word readTwoBytes(int regAddr, byte devAddr);
    void writeOneByte(int regAddr, byte data);
    void writeOneByte(int regAddr, byte devAddr, byte data);
    i2cCom(void);
    i2cCom(int devAddr);
};
#endif
