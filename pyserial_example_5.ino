String str;
int sensorValue = 0;        // value read from the pot

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); // set the baud rate
//Serial.println("Ready"); // print "Ready" once
//delay(100);
}



void loop() {
  sensorValue = analogRead(A1); //We read pin A1
  Serial.println(sensorValue);
  delay(1000);
}
