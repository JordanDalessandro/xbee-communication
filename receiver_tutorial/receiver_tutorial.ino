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


bool started = false;  // True when start marker is detected
bool ended = false;    // True when end marker is detected
char incomingByte;     // Storage for each byte read
char msg[4];           // Array to assemble the incoming message
byte index1 = 0;


void setup() {
  // Initialize USB Serial for debugging
  Serial.begin(9600);

  // Initialize XBee Serial (default 9600 baud for XBee)
  XBEE_SERIAL.begin(9600);

  Serial.println("XBee Receiver Ready");
  Serial.println("Waiting for data...");
}

void loop() {
  // Check if data is available from XBee
  while (XBEE_SERIAL.available() > 0) {
    incomingByte = XBEE_SERIAL.read();

    if (incomingByte == '<') {  // Detect start of the message
      started = true;
      index1 = 0;
      msg[index1] = '\0';  // Clear the buffer
    }

    else if (incomingByte == '>') {  // Detect end of the message
      ended = true;
      break;  // Stop reading, process the message
    }

    else {  // Store the byte in msg array if message has started
      msg[index1] = incomingByte;
      index1++;
      msg[index1] = '\0';  // Null terminate the string
    }

    if (started && ended) {
      int value = atoi(msg);
      // Display received data on Comp Serial
      Serial.print("I received: ");
      Serial.println(value);

      started = false;
      ended = false;
    }

    // // Optional: Send acknowledgment back to sender
    // XBEE_SERIAL.print("ACK: ");
    // XBEE_SERIAL.println(receivedData);

    // Serial.println("Acknowledgment sent");
  }
  delay(1000);
}