//Receiver (Ground Station) should send commands to Sender (cansat) then
//display onto the groundstation serial terminal. 

void receiveTelemetry()
{
  while (XBeeSerial.available() > 0) {
    String incomingData = XBeeSerial.readStringUntil('\n');
    
      if (incomingData.indexOf("COUNT") >= 0) {


        // Display counter value received from cansat
        //grab counter from serial and assign to a variable
        //substring allows you to grab a specific section of the char array from the end of count 
        int counter = incomingData.substring(incomingData.indexOf("COUNT") + 5).toInt();
        
        //count up number of packets received
        packetsReceived++;
        
        //display
        Serial.print("<- Received counter: ");
        Serial.print(counter);
        Serial.println(" (Total received: " + packetsReceived + ")");

      }
      incomingData = "";
  }
}

void checkForCommands()
{
  
}


//function that displays all commands available. 
//how to avoid sending message over xbee serial?
void helpFunction() {

}