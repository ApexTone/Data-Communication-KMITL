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
    Serial.println(bitRead(ownerName,i));  //test bit reading each character
    delay(100);
    }*/
  Serial.print("My ID is : ");
  Serial.println(ownerName);
  //Serial.println(ownerName);
  while (!Serial.available())
  {
  }
  Serial.println("Sender Send : " + Serial.readString());

  while (!Serial.available())
  {
  }
  Serial.println("Save as : " + Serial.readString());
}

void flushRx()
{
  while (mySerial.available())
  {
    String tmp = mySerial.readString();
  }
}
char ackNo = '0';
void loop()
{
  //can't handle buffer overflowing
  //find way to reset ackNo
  while (mySerial.available()) {
    String incoming_text = mySerial.readString();
    Serial.println(incoming_text);
    char receiver = incoming_text[1], sender = incoming_text[2], frame_number = incoming_text[3], check = incoming_text[8];
    Serial.print("Receive frame\nHeader : ");
    Serial.print(sender);
    Serial.println(receiver);
    Serial.print("Frame No. : ");
    Serial.println(frame_number);
    String data = "";
    for (int i = 4; i <= 7; i++)
    {
      data += char(incoming_text[i]);
    }
    Serial.println("Data : " + data);
    Serial.print("Checking : ");
    Serial.println(check);

    if (receiver == ownerName)
    {
      //Do error detection (parity check) here: if error, do something else
      Serial.println("Received");
      Serial.print("\nSend ACK");
      Serial.println(ackNo);

      String responseAck = "`";
      responseAck += receiver;
      responseAck += sender;
      responseAck += ackNo;

      char resCheck = '0';
      int sum = 0;
      for (int i = 0; i < responseAck.length(); i++)
      {
        for (int j = 0; j < 8; j++)
        {
          int x = bitRead(responseAck[i], j);
          if (x == 1)
          {
            sum++;
          }
        }
      }
      if (sum % 2 == 0) {
        resCheck = '1';
      }

      responseAck += resCheck;

      //send res
      for (int i = 0; i < responseAck.length(); i++)
      {
        mySerial.write(responseAck[i]);
      }
      ackNo == '0' ? ackNo = '1' : ackNo = '0';
      responseAck += "`";
    }
    else
    {
      Serial.println("Not for me!");
    }
    flushRx();
  }
}
