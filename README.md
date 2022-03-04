# i2cCom

i2cCom is a simple helper library for Arduino environment to make i2c communication implementation easier.
It provides some functions to read and write bytes to periferals more directly but without Wire manual manipulation.

## Installation

Using Platformio, just download this repository into the `lib` folder.
```bash
git clone https://github.com/ShinJaca/i2cCom /[your_project_diretory]/lib/i2cCom.git
```
_TODO:_ instalation via arduino IDE.

## Usage

```c++
#include <i2cCom.h>

// Instanciates an object with the device address set to 0x68
i2cCom myi2c(0x68);
// or without any address, the device address will be specified in the functions
i2cCom myi2c();

void setup()
{
    // Wire must be iniciated
    Wire.begin();
}
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.