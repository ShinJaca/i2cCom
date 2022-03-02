#include "Arduino.h"
#include "i2cCom.h"

#include <Wire.h>

/**
 * @brief Requests 2 (two) bytes from a register address (regAddr) from
 * a device (devAddr); returns the bytes concatenated in a word, ou 0, in
 * case of failure
 *
 * @param regAddr register address
 * @param devAddr device address
 * @return word returned bytes forming a word
 */
word i2cCom::readTwoBytes(int regAddr, byte devAddr)
{
    Wire.beginTransmission(devAddr);
    Wire.write(regAddr);
    Wire.endTransmission(false);
    if (Wire.requestFrom(devAddr, 2, true))
    {
        int high = Wire.read();
        int low = Wire.read();
        return (high << 8) | low;
    }
    return 0;
};

/**
 * @brief Requests 2 (two) bytes from a register address (regAddr) from
 * the objcect's device; returns the bytes concatenated in a word, ou 0, in
 * case of failure
 *
 * @param regAddr register address
 * @return word returned bytes forming a word
 */
word i2cCom::readTwoBytes(int regAddr)
{
    return readTwoBytes(regAddr, _address);
};

byte i2cCom::readByte(int regAddr, byte devAddr)
{
    Wire.beginTransmission(devAddr);
    Wire.write(regAddr);
    Wire.endTransmission(false);

    if (Wire.requestFrom(devAddr, 1, true))
    {
        return Wire.read();
    }
    return 0;
}

void i2cCom::readNBytes(byte regAddr, byte devAddr, int n, byte output[])
{
    Wire.beginTransmission(devAddr);
    Wire.write(regAddr);
    Wire.endTransmission(false);

    Wire.requestFrom(devAddr, n, true);

    for (int i = 0; i < n; i++)
    {
        output[i]=Wire.read();
    }  
}

/**
 * @brief Writes one byte to the register (regAddr) in the device (devAddr)
 *
 * @param regAddr register address
 * @param devAddr device address
 * @param data byte to be writen
 */
void i2cCom::writeOneByte(int regAddr, byte devAddr, byte data)
{
    Wire.beginTransmission(devAddr);
    Wire.write(regAddr);
    Wire.write(data);
    Wire.endTransmission();
};

/**
 * @brief Writes one byte to the register (regAddr) in the configured device
 *
 * @param regAddr register address
 * @param data byte to be writen
 */
void i2cCom::writeOneByte(int regAddr, byte data)
{
    writeOneByte(regAddr, _address, data);
};

i2cCom::i2cCom(void){

};

uint8_t i2cCom::testAddress()
{
    testAddress(_address);
}

/**
 * @brief Tries a conection at the specified address and returns its status
 *
 * @param devAddr device addres
 * @return uint8_t test result
 */
uint8_t i2cCom::testAddress(byte devAddr)
{
    Wire.beginTransmission(devAddr);
    return Wire.endTransmission();
}

/**
 * @brief Construct a new i2c Com::i2c Com object with the devAddr address
 *
 * @param devAddr device address
 */
i2cCom::i2cCom(int devAddr)
{
    _address = devAddr;
};
