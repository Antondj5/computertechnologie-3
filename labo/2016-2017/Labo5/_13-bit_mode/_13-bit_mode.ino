#include <Wire.h>
#define TMP102_I2C_ADDRESS 72

void setConf(){
  Wire.beginTransmission(TMP102_I2C_ADDRESS);//addres ic
  Wire.write((byte)0x02);
  Wire.write((byte)28);
  Wire.endTransmission();

  Wire.beginTransmission(TMP102_I2C_ADDRESS);
  Wire.write((byte)0x03);
  Wire.write((byte)29);
  Wire.endTransmission();

  //conversion rate instellen
  Wire.beginTransmission(TMP102_I2C_ADDRESS);
  Wire.write((byte)0x01);
  Wire.write(B01100000);
  Wire.write(B01100000);
  Wire.endTransmission();
}
float getTempEM(){
  //instellen extenden mode
  Wire.beginTransmission(TMP102_I2C_ADDRESS);
  Wire.write((byte)0x01);
  Wire.write(B01100000);
  Wire.write(B01110000);
  Wire.endTransmission();
  
  Wire.beginTransmission(TMP102_I2C_ADDRESS);//addres ic
  Wire.write((byte)0x00);
  Wire.endTransmission();
  Wire.requestFrom(TMP102_I2C_ADDRESS,2);
  Wire.endTransmission();
  
  byte MSB = Wire.read();
  byte LSB = Wire.read();
  int waarde = ((MSB)<<5);
  waarde |= (LSB>>3); 
  float temperatuur = waarde * 0.0625;
  return temperatuur;
}
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
  setConf();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getTempEM());
  delay(250);
}
