#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

char ownerName;

void setup()
{
  mySerial.begin(57600);
  Serial.begin(115200);
  delay(200);
  Serial.println("Enter ID :");
  while (!Serial.available())
  {
  }
  ownerName = Serial.read();
  /*for(int i=7;i>=0;i--){
    Serial.println(bitRead(ownerName,i));  // bit reading each character
    delay(100);
    }*/
  Serial.print("My ID is : ");
  Serial.println(ownerName);
  //Serial.println(ownerName);
  while (!Serial.available())
  {
  }
  Serial.println("Send file : "+Serial.readString());
}

void flushRx()
{
  while (mySerial.available())
  {
    uint8_t tmp = mySerial.read();
  }
}

void loop()
{
  /*
  char myString[] = "Computer Engineering";
  for (int i = 0; myString[i] != '\0'; i++)
  {
    mySerial.write(myString[i]);
    Serial.write(myString[i]);
    Serial.println();
    delay(10);
    flushRx();
  }
  delay(500);
  mySerial.write('\n');
  */
}
