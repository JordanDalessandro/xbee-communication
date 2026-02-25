/*
 * XBee Pro S3B Sender - Simple Counter Test
 * For Teensy 4.1
 * 
 * Sends a counter and waits for confirmation from receiver
 * 
 * WIRING:
 * XBee Pin -> Teensy 4.1 Pin
 * 5V (20)  -> Vin 
 * TX (2)   -> RX1 (Pin 0)
 * RX (3)   -> TX1 (Pin 1)
 * GND (10) -> GND
 */

// Use Serial1 for XBee communication (pins 0 and 1 on Teensy 4.1)
#define XBeeSerial Serial1

unsigned long counter = 0; /*stores whole numbers, no negative values, Uses more bits than regular int
                             has a larger positive range
                             Signed means the variable can store negative and positive values
                             Long means it stores 8 bytes
                           */

//Telemetry data to send
float altitude = 0.0;
float temperature = 25.0;
float voltage = 3.7;
int packetID = 0;


//create a frequency at which data will be sent.
unsigned long lastSendTime = 0;
const unsigned long SEND_INTERVAL = 1000;  // Send every 1 second

String buffer = "";

void setup() {
  // Initialize USB Serial for debugging
  Serial.begin(115200);

  // Initialize XBee Serial
  XBeeSerial.begin(9600);


  while (!XBeeSerial) {
    Serial.println("Waiting to connect");
  }
  Serial.println("XBee Sender - Counter Test");
}

void loop() {
  readIncomingCommands();  //check for commands first
  sendTelemetry();         //send data every 1 Hz (1 second)

}
