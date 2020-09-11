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
  /*Serial.println(ownerName);
    while (!Serial.available())
    {
    }
    Serial.println("Sender Send : " + Serial.readString());

    while (!Serial.available())
    {
    }
    Serial.println("Save as : " + Serial.readString());
  */
}

void flushRx()
{
  while (mySerial.available())
  {
    String tmp = mySerial.readString();
  }
}

char ackNo = '0';
String allReceiving = "";
void loop()
{
  //can't handle buffer overflowing
  //find way to reset ackNo
  while (mySerial.available()) {
    String incomingText = mySerial.readString();
    Serial.print("Receiving incoming frame : ");
    Serial.println(incomingText);
    char receiver = incomingText[1], sender = incomingText[2], frame_number = incomingText[3], check = incomingText[8];//extract data

    if (receiver == ownerName)//this frame is for me
    {
      Serial.print("Receive frame\nHeader : ");
      Serial.print(sender);
      Serial.println(receiver);
      Serial.print("Frame No. : ");
      Serial.println(frame_number);
      String data = "";
      for (int i = 4; i <= 7; i++)
      {
        if (char(incomingText[i]) != '~')
          data += char(incomingText[i]);
      }
      Serial.println("Data : " + data);
      Serial.print("Checking : ");
      Serial.println(check);

      //Do error detection (parity check) here: if error, do something else
      int bitChecker = 0;
      for (int i = 1; i <= 7; i++)
      {
        for (int j = 0; j < 8; j++)
        {
          bitChecker += bitRead(incomingText[i], j);
        }
      }
      if ((bitChecker % 2 == 0 && check == '1') || (bitChecker % 2 == 1 && check == '0'))
      {
        Serial.println("Received");
        Serial.print("All data : ");
        allReceiving += data;
        Serial.println(allReceiving);

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

        //send ack
        for (int i = 0; i < responseAck.length(); i++)
        {
          mySerial.write(responseAck[i]);
        }
        ackNo == '0' ? ackNo = '1' : ackNo = '0';
        responseAck += "`";
      }
      else
      {
        Serial.println("Corrupted frame");
      }


    }
    else
    {
      Serial.println("Not for me!");
      Serial.println(incomingText);
      String out = "`";
      out += ownerName;
      out += sender;
      out += ackNo;
      char resCheck = '0';
      int sum = 0;
      for (int i = 0; i < out.length(); i++)
      {
        for (int j = 0; j < 8; j++)
        {
          int x = bitRead(out[i], j);
          if (x == 1)
          {
            sum++;
          }
        }
      }
      if (sum % 2 == 0) {
        resCheck = '1';
      }
      out += resCheck;
      out += "`";
      Serial.println(out);
    }

    flushRx();
  }
}
