//Cansat Will send telemetry data to Ground station (GS) over xbee serial1

//cansat will check xbee serial for commands coming from GS and execute the command
  //while sending back a confirmation to GS

//cansat will send telemetry data at 1 Hz rate


//define xbee as serial1 Teensy RX pin 0, TX pin 1


void setup() {
  //setup serial communication

  //set up xbee communication

}

void loop() {

  //Check for messages coming over Xbee Serial1 first
  //checkForCommand();

  //Send telemetry data to GS (Simulate this with random numbers for now.)
  //sendTelemetry();



}

//CHECK FOR COMMANDS
//while xbee serial1 is availabe read string until \n
//assign to string variable commandBuffer
//send commandBuffer to processing command function


//PROCESS COMMAND FUNCTION
  //acknowledge the command was received by sending message "ACK: 'Message' "
  //if commandBuffer == "p"
  //send ACK:Ping
  //if commandBuffer == "s"
  //send ACK:Status:TEST
  //if commandBuffer == "r"
  //send ACK:RESET_ID
  //If message received is unknown 
  //send MSG: Unknown


//SEND TELEMETRY FUNCTION
//create int packetID = 0
//create 3 random floats
//altitude
//temperature
//voltage

//String packet = packetID + , + altitude + , + pressure + , + voltage 
//send telemetry over xbee serial1
//packetID++;

