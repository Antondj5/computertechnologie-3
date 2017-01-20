#include <Wire.h>
#define TMP102_I2C_ADDRESS 72
int tHigh = 26;
int tLow = 27;
void setConf(){
  
  Wire.beginTransmission(TMP102_I2C_ADDRESS);//addres ic
  Wire.write((byte)0x01);
  Wire.write(B01100100);
  Wire.endTransmission();
  
  Wire.beginTransmission(TMP102_I2C_ADDRESS);//addres ic
  Wire.write((byte)0x02);//26
  if(tLow%2==0){
    tLow>>1;
  Wire.write(tLow);
  Wire.write(B00000000);
  }else{
    tLow>>1;
  Wire.write(tLow);
  Wire.write(B10000000);
  }
  Wire.endTransmission();

  Wire.beginTransmission(TMP102_I2C_ADDRESS);
  Wire.write((byte)0x03);
  if(tHigh%2==0){
    tHigh>>1;
  Wire.write(tHigh);
  Wire.write(B00000000);
  }else{
    tHigh>>1;
  Wire.write(tHigh);
  Wire.write(B10000000);
  }
  Wire.endTransmission();
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
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  setConf();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(getTempEM());
  delay(2000);
}
