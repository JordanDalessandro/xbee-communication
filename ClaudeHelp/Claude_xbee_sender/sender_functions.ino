// No additional functions needed for simple counter sender

//sender should listen out for commands while delivering telemetry data to ground station
//Serial is on board microcontroller
//xbeeSerial is sending message back to groundstation


String incomingData = "";
unsigned long now = millis();

void readIncomingCommands() {

  while (XBeeSerial.available() > 0) {
    incomingData = XBeeSerial.readStringUntil('\n');  //read until newline
    Serial.print("Ground Station has sent: ");        //remove after testing
    Serial.println(incomingData);
    incomingData.trim();  //remove any whitespaces

    processCommand(incomingData);

    //reset variable for next command
    incomingData = "";
  }
}

//receive command and acknowledge it.
void processCommand(String cmd) {
  Serial.print("Command recieved: ");
  Serial.println(cmd);

  if (cmd == "ping") {
    Serial.println("Ping command was received");
    XBeeSerial.println("ACK: ping");
  } else if (cmd == "status") {

    XBeeSerial.println("ACK: status");
    Serial.println("ACK: status");
  } else if (cmd == "resetid") {
    Serial.println("Packet ID was: " + packetID);
    packetID = 0;
    Serial.println("Package value is now: " + packetID);
    XBeeSerial.println("ACK:resetid");

  } else {
    Serial.println("Command unknown, List of commands:");
    Serial.println("ping");
    Serial.println("status");
    Serial.println("resetid");

    XBeeSerial.println("Command unknown, List of commands:");
    XBeeSerial.println("ping");
    XBeeSerial.println("status");
    XBeeSerial.println("resetid");
  }
}

void sendTelemetry() {

  unsigned long now = millis();
  // Send counter at interval
  //This will count up by 1 every 1000 miliseconds
  if (now - lastSendTime >= SEND_INTERVAL) {
    lastSendTime = now;
    counter++;

    // Send counter
    XBeeSerial.print("COUNT");
    XBeeSerial.println(counter);

    Serial.print("-> Sent counter: ");
    Serial.println(counter);
  }
}