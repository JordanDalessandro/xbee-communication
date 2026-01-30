

//blink a light a number of times. "pin" should be pin 13 on teensy by default
void bliny(int numTimes, int pin, int delayTime)
{
  for(int i = 0; i < numTimes; i++)
  {
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
}