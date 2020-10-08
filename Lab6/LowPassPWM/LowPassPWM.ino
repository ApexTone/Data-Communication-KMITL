const int zetaLength = 4;
float zeta[] = {0, 90, 180, 270};
float s[zetaLength];
uint16_t pwmDuty[zetaLength];
int pwmPin = 3;//PWM choices:3, 5, 6, 9, 10, 11
void setup()
{
  pinMode(pwmPin, OUTPUT); 
  Serial.begin(115200);
  for (int i = 0; i < zetaLength; i++)
  {
    s[i] = sin(zeta[i]);
    pwmDuty[i] = map(s[i],-1,1,0,255);
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
    analogWrite(pwmPin, pwmDuty[i]);
    delayMicroseconds(4000);
   }
}
