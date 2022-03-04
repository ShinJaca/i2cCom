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
    byte readByte(int regAddr, byte devAddr);
    byte readByte(int regAddr);
    void readNBytes(byte regAddr, byte devAddr, int n, byte[]);
    void readNBytes(byte regAddr, int n, byte[]);
    void writeOneByte(int regAddr, byte data);
    void writeOneByte(int regAddr, byte devAddr, byte data);
    uint8_t testAddress();
    uint8_t testAddress(byte devAddr);
    i2cCom(void);
    i2cCom(int devAddr);
    void setDevAddress(int devAddr);
};
#endif
