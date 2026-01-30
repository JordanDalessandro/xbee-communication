// all functions here are callable from other scripts in the tabl structure

// blink a light a certain number of times. assumes <pin> is init output in setup
void blinky(int numTimes, int pin, int delayTime) {
  for (int i = 0; i < numTimes; i++) {
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
}
