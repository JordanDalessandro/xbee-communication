//Ground station will receive telemetry data from cansat
//Ground station will send commands to cansat remotely


//initialize xbee over serial1 on Teensy 4.1 RX pin 0, TX pin 1


void setup() {
  //setup serial communication

  //set up xbee communication

}

void loop() {
  //receive telemetry data using xbee coneected to teensy RX Pin 0, TX Pin 1
  //receiveData();

  //check to see if user typed anything into Serial
  //sendCommand();


}

//RECEIVE DATA FUNCTION
  //while the xbee serial1 is available
  //String telemetry = xbee serial1 readStringUntil \n 
  //if telemetry starts with ACK
    //print to serial
  //else 
    //parseTelemetry();
  

//PARSE TELEMETRY FUNCTION
//void parseTelemetry()
  //Expected: ID, ALT, TEMP, VOLT
  //idx0 = index of first comma
  //idx1 = index of second comma after idx0 + 1
  //idx2 = index of third comma after idx1 + 1
  //if any indexes are -1 we should throw an error
  //else 
    //first data point id = substring of data from 0 and idx0 to int
    //second data point alt = substring data from idx0 + 1 and idx1 to float
    //third data pint temp = substring data from idx1 + 1 and idx2 to float
    //fourth data point volt = substring data after idx2 + 1 to float  //I wonder if it takes the \n character at the end of the string and if I should correct it.
//Serial.print("[PKT #"); Serial.print(id);
//Serial.print("] Alt: "); Serial.print(alt);
//Serial.print("m | Temp: "); Serial.print(temp);
//Serial.print("C | Volt: "); Serial.print(volt);
//Serial.println("V");


//SEND COMMAND FUNCTION
  //while serial is available
  //if no input exit function
  //Read serial input from user
  //check if it matches a known command
  //if it does, send to cansat over xbee serial1
  //else display error message and available commands. Do not send