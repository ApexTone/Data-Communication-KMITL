#include<SoftwareSerial.h>

SoftwareSerial mySerial(10,11);//rx, tx

void setup() {
  Serial.begin(115200);
  mySerial.begin(57600);
}

void loop() {
  if(mySerial.available()){
      Serial.write(mySerial.read());
    }
}
