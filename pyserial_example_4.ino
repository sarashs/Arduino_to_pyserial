String str;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); // set the baud rate
Serial.println("Ready"); // print "Ready" once
delay(100);
Serial.println("Turn your LED ON or OFF with: ON/OFF commands");
}

//We will use serial event
void serialEvent() {
if(Serial.available()){ // only send data back if data has been sent
str = Serial.readString(); // read the incoming data
Serial.println(str); // send the data back in a new line so that it is not all one long line
}
delay(100); // delay for 1/10 of a second
if (str.indexOf("ON") > -1){
  str.replace("ON", ""); //take the letters out of the string
  str.trim(); //remove tailing or leading white spaces
  analogWrite(LED_BUILTIN, str.toInt()); //Use the integer part of the string as intensity
}else if (str.indexOf("OFF") > -1){
  digitalWrite(LED_BUILTIN, LOW);
  }
}

void loop() { //we freed the loop
}
