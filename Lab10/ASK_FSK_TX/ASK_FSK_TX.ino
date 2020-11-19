#include<Wire.h>
#include<String.h>
#include<Adafruit_MCP4725.h>
#include<Adafruit_ADS1015.h>

Adafruit_MCP4725 dac;

#define defaultFreq 1700
#define f0 500
#define f1 800
#define f2 1100
#define f3 1400
const float A[4] = {1, 2, 3, 4}; //Amplitude for ASK
const uint16_t S_DAC[4] = {500, 1000, 500, 0}; // for ASK

int delay0, delay1, delay2, delay3; // delay for FSK
const uint16_t SF_DAC[4] = {2000, 4090, 2000, 0};  // for FSK

char mode;

char inData[30];
void setup()
{
  dac.begin(0x64);
  delay0 = (1000000 / f0 - 1000000 / defaultFreq) / 4;
  delay1 = (1000000 / f1 - 1000000 / defaultFreq) / 4;
  delay2 = (1000000 / f2 - 1000000 / defaultFreq) / 4;
  delay3 = (1000000 / f3 - 1000000 / defaultFreq) / 4;
  Serial.begin(115200);
  Serial.print("0=ASK, 1=FSK: ");
  while (!Serial.available());
  mode = Serial.read();
  Serial.println(mode);
  Serial.flush();
}


void loop()
{
  if (mode == '0')//ASK
  {
    //Serial.println("ASK");
    if (Serial.available() > 0) {
      int counter = 0;
      String inp = Serial.readString();
      inp += "\n";
      for (int i = 0; i < inp.length(); i++) {
        inData[i] = inp[i];
        counter++;
      }

      for (int s = 0; s < 4; s++) //4 sample/cycle -> DUMMY SIGNAL
      {
        dac.setVoltage(1000, false);//modify amplitude
        delayMicroseconds(delay0);
      }

      for (int i = 0; i < counter - 1; i++) { //send data
        for (int k = 7; k > 0; k -= 2) {//send 8 bits from LSB tp MSB
          int tmp = inData[i] & 3;
          for (int sl = 0; sl < 5; sl++) { //5 cycles/baud
            for (int s = 0; s < 4; s++) { //4 sample/cycle
              dac.setVoltage(A[tmp]*S_DAC[s], false);//modify amplitude
              delayMicroseconds(delay0);
            }
          }
          inData[i] >>= 2;
        }
      }

      for (int s = 0; s < 4; s++) //4 sample/cycle -> DUMMY SIGNAL
      {
        dac.setVoltage(1000, false);//modify amplitude
        delayMicroseconds(delay0);
      }

      dac.setVoltage(0, false);
    }
    Serial.flush();
  }
  else//FSK
  {
    //Serial.println("FSK");
    if (Serial.available() > 0)
    {
      int counter = 0;
      String inp = Serial.readString();
      inp += "\n";
      for (int i = 0; i < inp.length(); i++)
      {
        inData[i] = inp[i];
        counter++;
      }


      for (int s = 0; s < 4; s++) //4 sample/cycle -> DUMMY SIGNAL
      {
        dac.setVoltage(1000, false);//modify amplitude
        delayMicroseconds(delay0);
      }

      for (int i = 0; i < counter - 1; i++) //send data
      {
        for (int k = 7; k > 0; k -= 2) //send 8 bits from LSB tp MSB
        {
          int tmp = inData[i] & 3;
          int useDelay, cyc;
          if (tmp == 0)
          {
            cyc = 5;
            useDelay = delay0;
          }
          else if (tmp == 1)
          {
            cyc = 8;
            useDelay = delay1;
          }
          else if (tmp == 2)
          {
            cyc = 11;
            useDelay = delay2;
          }
          else
          {
            cyc = 14;
            useDelay = delay3;
          }
          for (int sl = 0; sl < cyc; sl++)
          {
            for (int s = 0; s < 4; s++) //4 sample/cycle
            {
              dac.setVoltage(SF_DAC[s], false);//modify amplitude
              delayMicroseconds(useDelay);
            }
          }
          inData[i] >>= 2;
        }
      }
      
      for (int s = 0; s < 4; s++) //4 sample/cycle -> DUMMY SIGNAL
      {
        dac.setVoltage(1000, false);//modify amplitude
        delayMicroseconds(delay0);
      }

      dac.setVoltage(0, false);
    }
    Serial.flush();
  }
}
