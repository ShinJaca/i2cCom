#include <Arduino.h>
#include <i2cCom.h>

#define MPUADDR 0x68
#define REG_TEMP 0x41
#define DELAY_TIME 50

i2cCom dev(MPUADDR);
int Temp;
void setup()
{
    Serial.begin(9600);
    Serial.println("MPU6000 Temperature log");
}

void loop()
{
    Temp = dev.readTwoBytes(REG_TEMP);
    Serial.println(Temp);
    delay(DELAY_TIME);
}