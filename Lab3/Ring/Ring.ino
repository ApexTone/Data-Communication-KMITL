#include<SoftwareSerial.h>

SoftwareSerial softSerial(10,11);
char sender;

void setup() {
  softSerial.begin(57600);
  Serial.begin(9600);

  Serial.println("Enter ID:");  
  while (!(Serial.available() > 0)){
  }

  sender = char(Serial.read());
  Serial.print("Your ID: ");
  Serial.println(sender);
  delay(200);
}

void loop() {
  delay(100);
  if (softSerial.available()){
    String buff = softSerial.readString();
    if(sender == buff[0]){
        Serial.print(buff[1]);
        for (int i = 2; i < buff.length(); i++){
            Serial.print(buff[i]);
        }
        Serial.println();
   }
   else{
     for(int i = 0; i < buff.length(); i++){
        softSerial.write(buff[i]);
      }
    }
  }

  if(Serial.available()){
    String toSend="",buff="";
    
    while (Serial.available()){ // consider change to this: String buff = softSerial.readString();
       buff += char(Serial.read());
    }
    //Serial.println(buff);
    toSend += char(buff[0]);
    toSend += char(sender);
    for(int i=1;i<buff.length();i++){
        toSend += char(buff[i]);
      }
    Serial.print("Me: ");
    for (int i = 2; i < buff.length(); i++){
     Serial.print(buff[i]); 
    }
    Serial.println();
     for(int i = 0; i < toSend.length(); i++){
        softSerial.write(toSend[i]);
      }
    }
    
}
