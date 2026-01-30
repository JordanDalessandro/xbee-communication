/*
 * XBee 900MHz Pro S3B - Receiver Code
 * Teensy 4.1
 * 
 * Connections:
 * XBee Pin 2 (DOUT) -> Teensy RX1 (Pin 0)
 * XBee Pin 3 (DIN)  -> Teensy TX1 (Pin 1)
 * XBee Pin 10 (GND) -> Teensy GND
 * XBee Pin 1 (VCC)  -> Teensy 3.3V
 */

#define XBEE_SERIAL Serial1  // Using Serial1 on Teensy 4.1

void setup() {
  // Initialize USB Serial for debugging
  Serial.begin(115200);
  while (!Serial && millis() < 3000); // Wait up to 3 seconds for Serial Monitor
  
  // Initialize XBee Serial (default 9600 baud for XBee)
  XBEE_SERIAL.begin(9600);
  
  Serial.println("XBee Receiver Ready");
  Serial.println("Waiting for data...");
}

void loop() {
  // Check if data is available from XBee
  if (XBEE_SERIAL.available()) {
    String receivedData = "";
    
    // Read the incoming data
    while (XBEE_SERIAL.available()) {
      char c = XBEE_SERIAL.read();
      receivedData += c;
      delay(2); // Small delay to allow buffer to fill
    }
    
    // Display received data on USB Serial
    Serial.print("Received: ");
    Serial.println(receivedData);
    
    // Optional: Send acknowledgment back to sender
    XBEE_SERIAL.print("ACK: ");
    XBEE_SERIAL.println(receivedData);
    
    Serial.println("Acknowledgment sent");
  }
}