# i2cCom

i2cCom is a simple helper library for Arduino environment to make i2c communication implementation easier.
It provides some functions to read and write bytes to periferals more directly but without Wire manual manipulation.

## Installation

Using Platformio, just download this repository into the `lib` folder.
```bash
git clone https://github.com/ShinJaca/i2cCom.git /[your_project_diretory]/lib/i2cCom
```
_TODO:_ instalation via arduino IDE.

## Usage

```c++
#include <i2cCom.h>

// Instanciates an object with the device address set to 0x68
i2cCom myi2c1(0x68);
// or without any address, the device address will be specified in the functions
i2cCom myi2c2();

void setup()
{
    // Wire must be iniciated
    Wire.begin();
}

void loop()
{
    // Writes one byte (0b00001010) to the register (0x1B)
    myi2c1.writeOneByte(0x1B, 0b00001010);
    
    // Reads one byte from the register (0x1B) into the constant
    const byte b = myi2c1.readByte(0x1B);
    // Reads two bytes from the register (0x1D) and concatenates into the constant
    const word c = myi2c1.readTwoBytes(0x1D);

    // Reads n bytes ( 2 ), and stores each byte into the array ( arr )
    byte arr[2];
    myi2c1.readNBytes(0x1D, 2, arr);
}
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.