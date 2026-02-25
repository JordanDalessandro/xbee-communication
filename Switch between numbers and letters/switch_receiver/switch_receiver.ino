//++++++++++++++++XBEE RECEIVER++++++++++++++++++++//

//I want to learn about sending commands to my remote xbee
//To start I want to get my sender to switch from sending numbers to sending letters

//we must first hold on to the command in case it isn't read right away.

#define xbee Serial1

char incomingByte;
String incomingData = "";

void setup() {
  // put your setup code here, to run once:
  //initialize the serial monitors
  Serial.begin(115200);
  xbee.begin(9600);

  Serial.println("Serial ready.");
  Serial.println("Type SWITCH to change between numbers and letters.");


}

void loop() {

  //display what the cansat sends us
  while(xbee.available())
  {
    //read incoming byte of data
    incomingData = xbee.readStringUntil('\n');

    //if the byte is \n this indicates the end of a unit of data. then we should display

      //display the full unit of data
      Serial.print("Received: ");
      Serial.println(incomingData);
      //reset buffer for next packet of data 

  }
  // I type a command into the Serial Monitor terminal
  //It sends the command to the cansat



}
