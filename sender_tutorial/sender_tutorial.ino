//REMOVE BLINKY AT RUNTIME

/*
 * XBee 900MHz Pro S3B - Sender Code
 * Teensy 4.1
 * 
 * Connections:
 * XBee Pin 2 (DOUT) -> Teensy RX1 (Pin 0)
 * XBee Pin 3 (DIN)  -> Teensy TX1 (Pin 1)
 * XBee Pin 10 (GND) -> Teensy GND
 * XBee Pin 1 (VCC)  -> Teensy 3.3V
 */

#define XBEE_SERIAL Serial1  // Using Serial1 on Teensy 4.1

static unsigned long counter = 0;

void setup() {
  // Initialize USB Serial for debugging
  Serial.begin(9600);
  //pinMode(LED_BUILTIN, OUTPUT);
  // while (!Serial && millis() < 3000); // Wait up to 3 seconds for Serial Monitor

  // Initialize XBee Serial (default 9600 baud for XBee)
  XBEE_SERIAL.begin(9600);

  Serial.println("XBee Sender Ready");
  Serial.println("Sending data every 1 seconds...");
  //blinky(1, LED_BUILTIN, 1000);  // (numtimes, pin, delaytime)
}

void loop() {

  //blinky(2, LED_BUILTIN, 100);

  // Send data to XBee
  String message = "Hello from Sender! Count: " + String(counter);

  // XBEE_SERIAL.print('<');
  XBEE_SERIAL.println('<' + message + '>');
  //XBEE_SERIAL.println('>');


  // Debug output to USB Serial
  Serial.print("Sent: ");
  Serial.println(message);

  counter++;

  // Check if there's any response from receiver
  if (XBEE_SERIAL.available()) {
    Serial.print("Received: ");
    

    while (XBEE_SERIAL.available()) {
      char c = XBEE_SERIAL.read();
      Serial.write(c);
    }
    Serial.println();
  }

  delay(1000);                 // Send every 1 seconds
}