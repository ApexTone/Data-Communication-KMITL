#include<Wire.h>
#include<Adafruit_MCP4725.h>
#include<Adafruit_ADS1015.h>

#ifndef cbi
#define cbi(sfr, bit)(_SFR_BYTE(sfr)&=~_BV(bit)) 
#endif
#ifndef sbi
#define sbi(sfr, bit)(_SFR_BYTE(sfr)|=_BV(bit))
#endif

//edit this number
#define r_slope 500

void setup() {
  sbi(ADCSRA, ADPS2);
  cbi(ADCSRA,ADPS1);
  cbi(ADCSRA,ADPS0);
  Serial.begin(115200);
  Serial.flush();
}

void loop() {
  /*
   read signal from analogRead()
   check period of input signal -> 2*(maxA time - minA time) ?
   calculate input frequency -> 1/period
   decode data bits from input freq -> if freq==... then ...
   show read data bits
  */
}
