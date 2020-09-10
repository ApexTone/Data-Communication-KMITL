#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

char ownerName;

void setup()
{
  mySerial.begin(57600);
  Serial.begin(115200);
  delay(50);
  while (!Serial.available())
  {
  }
  ownerName = Serial.read();
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
  char myString[] = "Computer Engineering";
  for (int i = 0; myString[i] != '\0'; i++)
  {
    mySerial.write(myString[i]);
    Serial.write(myString[i]);
    delay(10);
    flushRx();
  }
  delay(500);
  mySerial.write('\n');
}
