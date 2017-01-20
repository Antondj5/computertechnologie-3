#include <Wire.h>
#define TMP102_I2C_ADDRESS 72
float getTemp(){
  Wire.beginTransmission(TMP102_I2C_ADDRESS);//addres ic
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(TMP102_I2C_ADDRESS,2);
  Wire.endTransmission();
  
  byte MSB = Wire.read();
  byte LSB = Wire.read();
  int waarde = ((MSB)<<4);
  waarde |= (LSB>>4); 
  float temperatuur = waarde * 0.0625;
  return temperatuur;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getTemp());
  delay(2000);
}
