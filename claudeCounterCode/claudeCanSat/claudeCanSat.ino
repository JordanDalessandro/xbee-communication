/*
 * XBee Pro S3B Sender - Simple Counter Test
 * For Teensy 4.1
 * 
 * Sends a counter and waits for confirmation from receiver
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

unsigned long counter = 0;
unsigned long lastSendTime = 0;
const unsigned long SEND_INTERVAL = 1000; // Send every 1 second
String incomingData = "";

void setup() {
  // Initialize USB Serial for debugging
  Serial.begin(115200);
  
  // Initialize XBee Serial
  XBeeSerial.begin(9600);
  
  Serial.println("=================================");
  Serial.println("XBee Sender - Counter Test");
  Serial.println("=================================");
  Serial.println();
  
  delay(1000);
}

void loop() {
  // Check for confirmation from receiver
  while (XBeeSerial.available() > 0) {
    char c = XBeeSerial.read();
    if (c == '\n') {
      if (incomingData.indexOf("ACK") >= 0) {
        // Extract counter from confirmation
        int ackNum = incomingData.substring(incomingData.indexOf("ACK") + 3).toInt();
        Serial.print("✓ Confirmation received for counter: ");
        Serial.println(ackNum);
      }
      incomingData = "";
    } else {
      incomingData += c;
    }
  }
  
  // Send counter at interval
  if (millis() - lastSendTime >= SEND_INTERVAL) {
    lastSendTime = millis();
    counter++;
    
    // Send counter
    XBeeSerial.print("COUNT");
    XBeeSerial.println(counter);
    
    Serial.print("→ Sent counter: ");
    Serial.println(counter);
  }
}


