#include<Wire.h>
#include<Adafruit_MCP4725.h>

#define defaultFreq 1700
#define freq0 500

//edit these values
const float A[4] = {500,1000,500,0};//0-1023
#define a0min 0 
#define a0max 1000
#define a1min 0
#define a1max 2000
#define a2min 0 
#define a2max 3000
#define a3min 0 
#define a3max 4000
#define r_slope 500

int sum=0,maxA=0,prev=0,check=false,output=-1,count=0;

void setup() 
{
  dac.begin(0x64);
  Serial.begin(115200);
  Serial.flush();
}

void loop() 
{
  int tmp = analogRead(A0);
  if(tmp-prev > r_slope && check == false)//check rising edge
  {
    maxA = 0;
    check = true;  
  }

  if(tmp > maxA)//find max amplitude
  {
    maxA = tmp;
  }

  if(maxA-tmp > r_slope)//falling signal
  {
    if(check == true)//decode data
    {
      if(a0min < maxA && maxA < a0max)
      {
        Serial.print("0 0 ");
        count++;  
      }  
      else if(a0=1min < maxA && maxA < a1max)
      {
        Serial.print("0 1 ");
        count++;  
      }
      else if(a2min < maxA && maxA < a2max)
      {
        Serial.print("1 0 ");
        count++;  
      }  
      else if(a3min < maxA && maxA < a3max)
      {
        Serial.print("1 1 ");
        count++;  
      }   

      if(count == 5)//5 cycles/baud
      {
        count = 0;  
      }
    }
    check = false;
  }
  prev = tmp;
}
