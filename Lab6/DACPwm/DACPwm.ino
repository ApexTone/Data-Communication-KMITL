#include<Wire.h>
#include<Adafruit_MCP4725.h>
#define defaultFreq 1700 //DAC speed
#define freq0 500  // sine wave frequency

Adafruit_MCP4725 dac;
int delay0;

const int zetaLength = 4;
float zeta[] = {0, 90, 180, 270};
float s[zetaLength];
uint16_t pwmDuty[zetaLength];

void setup() 
{
  Serial.begin(115200);
  dac.begin(0x62);//default: A1
  //dac.begin(0x64);//A2
  //dac.begin(0x60);//A0
  delay0 = (1000000/freq0 - 1000000/defaultFreq)/4;//calculating delay with respect to computing+propagation delay
  Serial.print("delay0 is ");
  Serial.println(delay0);

  for (int i = 0; i < zetaLength; i++)
  {
    s[i] = sin(zeta[i]);
    pwmDuty[i] = map(s[i],-1,1,0,4095);
    Serial.print(i);
    Serial.print(": ");
    Serial.print(s[i]);
    Serial.print(" ");
    Serial.println(pwmDuty[i]);
  }
}

void loop() 
{
  for(int i=0;i<zetaLength;i++)
  {
     dac.setVoltage(pwmDuty[i],false);
     delayMicroseconds(delay0);
    }

}
