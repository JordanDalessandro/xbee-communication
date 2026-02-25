/*
 * XBee Pro S3B Receiver - Simple Counter Test
 * For Teensy 4.1
 * 
 * Receives counter and sends back confirmation
 * 
 * WIRING:
 * XBee Pin -> Teensy 4.1 Pin
 * VCC (1)  -> 3.3V
 * TX (2)   -> RX1 (Pin 0)
 * RX (3)   -> TX1 (Pin 1)
 * GND (10) -> GND
 */

// Use Serial1 for XBee communication (pins 0 and 1 on Teensy 4.1)
#define XBeeSerial Serial1

String incomingData = "";
unsigned long packetsReceived = 0;

void setup() {
  // Initialize USB Serial for debugging
  Serial.begin(115200);
  
  // Initialize XBee Serial
  XBeeSerial.begin(9600);
  
  while(!XBeeSerial)
  {
    Serial.println("Waiting for Xbee connection");
  }

  Serial.println("XBee Receiver - Counter Test");
  
  Serial.println("Waiting for counter data...");
}


void loop() {
  receiveTelemetry();
  checkForCommands();

  // Check for incoming data from XBee
  
}


