//sending sms with ATcommand

#include <SoftwareSerial.h>
SoftwareSerial SIM800L(2,3); //rx and tx
//connect the tx to arduino pin 2 rx
//connect the rx to arduino pin 3 tx

void setup() {
//  use baut rate communication 9600 on serial monitor
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Arduino with module gsm is ready");

//  use baut communication 9600 among module gsm with arduino 
  SIM800L.begin(9600);
  Serial.println("Module started on serial communication 9600");
  delay(1000); // time delay 1 second
  Serial.println("SIM800L ready for used");

  Serial.println("Set format sms to ascii"); //menset format sms
  SIM800L.write("AT+CMGF=1\r\n"); // procedure writing by module SIM800L
  delay(1000); //time delay 1 second
  Serial.println("SIM800L ready TO use");

  Serial.println("Set format SMS to ASCII"); // menset format sms
  SIM800L.write("AT+CMG=1\r\n"); // procedure writing by module sim800l

  Serial.println("SIM800 set sms to purpose number");
  SIM800L.write("AT+CMGS=\"nomermu\"\r\n");
  delay(1000);

  Serial.println("Module sending sms to purpose number");
  //  value sms
  SIM800L.write("value sms word in thingking");
  delay(1000);

  Serial.println("sms done sending");
   
}

void loop() {
  

}
