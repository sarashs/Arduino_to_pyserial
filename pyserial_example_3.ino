void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); // set the baud rate
Serial.println("Ready"); // print "Ready" once
delay(100);
Serial.println("Turn your LED ON or OFF with: ON/OFF commands");
}
void loop() {
String str;
if(Serial.available()){ // only send data back if data has been sent
str = Serial.readString(); // read the incoming data
Serial.println(str); // send the data back in a new line so that it is not all one long line
}
delay(100); // delay for 1/10 of a second
if (str.indexOf("ON") > -1){
  digitalWrite(LED_BUILTIN, HIGH);
}else if (str.indexOf("OFF") > -1){
  digitalWrite(LED_BUILTIN, LOW);
  }
}
