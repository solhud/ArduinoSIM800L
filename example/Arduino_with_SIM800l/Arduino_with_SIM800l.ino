#include <SoftwareSerial.h>
SoftwareSerial SIM800L(2,3); //rx | tx
//connect txd for arduino pin 2
//connect rxd for arduino pin 3
char c =' ';

void setup() {
  Serial.begin(9600); //use communication serial on 9600
  While(!Serial);
  Serial.println("Arduino with modul gsm is ready");

//  begin communication with
  SIM800L.begin(9600);
  Serial.println("Module gsm started at 9600");
  delay(1000); //value delay is 1 second
}

void loop() {
//  confirm reading from sim800 and send data to arduino
  if(SIM800L.available()){
    c=SIM800L.read();
    Serial.write(c);
  }

//  confirm reading from SIM800L and send data to arduino
  if(Serial.available()){
    c =Serial.read();
    SIM800L.write(c);
  }
}
