#include<Wire.h>
#include<Adafruit_MCP4725.h>
#include<Adafruit_ADS1015.h>

#define defaultFreq 1700
#define f0 500
#define f1 750
#define f2 1000
#define f3 1250
int delay0, delay1, delay2, delay3;

const uint16_t S_DAC[4] = {2000, 4000, 2000, 0};  // DAC voltage ranged from 0-4095
Adafruit_MCP4725 dac;

void setup() {
  dac.begin(0x64);//A2
  delay0 = (1000000 / f0 - 1000000 / defaultFreq) / 4;
  delay1 = (1000000 / f1 - 1000000 / defaultFreq) / 4;
  delay2 = (1000000 / f2 - 1000000 / defaultFreq) / 4;
  delay3 = (1000000 / f3 - 1000000 / defaultFreq) / 4;
  Serial.begin(115200);
  Serial.flush();
}

void loop() {
  if (Serial.available() > 0)
  {
    int in = Serial.parseInt();
    int input[4];
    for(int i=3;i>=0;i--)
    {
      input[i] = in & 3;
      in >>= 2; 
    }
    for (int k = 3;k >= 0;k--)
    {
      int useDelay;
      if(input[k] == 0)
      {
        Serial.println("00")
        useDelay = delay0; 
      }
      else if(input[k] == 1)
      {
        Serial.println("01")
        useDelay = delay1; 
      }
      else if(input[k] == 2)
      {
        Serial.println("10")
        useDelay = delay2; 
      }
      else if(input[k] == 3)
      {
        Serial.println("11")
        useDelay = delay3; 
      }

      for (int sl=0;sl<5;sl++) {//5 cycles/baud
          for (int s=0;s<4;s++) {//4 sample/cycle
            dac.setVoltage(S_DAC[s], false);
            delayMicroseconds(useDelay);//modify frequency
          }
        }
    }
    dac.setVoltage(0, false);
  }
}
