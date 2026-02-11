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
  while (!Serial && millis() < 3000);
  
  // Initialize XBee Serial
  XBeeSerial.begin(9600);
  
  Serial.println("=================================");
  Serial.println("XBee Receiver - Counter Test");
  Serial.println("=================================");
  Serial.println("Waiting for counter data...");
  Serial.println();
  
  delay(1000);
}

void loop() {
  // Check for incoming data from XBee
  while (XBeeSerial.available() > 0) {
    char c = XBeeSerial.read();
    
    if (c == '\n') {
      // Process received data
      if (incomingData.indexOf("COUNT") >= 0) {
        // Extract counter value
        int counter = incomingData.substring(incomingData.indexOf("COUNT") + 5).toInt();
        
        packetsReceived++;
        
        Serial.print("← Received counter: ");
        Serial.print(counter);
        Serial.print(" (Total received: ");
        Serial.print(packetsReceived);
        Serial.println(")");
        
        // Send acknowledgment back to sender
        XBeeSerial.print("ACK");
        XBeeSerial.println(counter);
        
        Serial.print("→ Sent confirmation for: ");
        Serial.println(counter);
        Serial.println();
      }
      incomingData = "";
    } else {
      incomingData += c;
    }
  }
}


