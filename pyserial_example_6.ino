#include <Servo.h>
Servo servo_1;  // create servo object to control a servo
Servo servo_2;  // create servo object to control a servo
int pos1 = 0;    // variable to store the servo position
int pos2 = 0;    // variable to store the servo position
int dut1 = 0;    // variable to store the pwm duty cycle
int dut2 = 0;    // variable to store the pwm duty cycle
int A1_value = 0; // variable to store analog sensor value
int A2_value = 0; // variable to store analog sensor value
String command_str = "                  ";
void setup() {
pinMode(LED_BUILTIN, OUTPUT);
servo_1.attach(1);
servo_2.attach(2);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
Serial.begin(9600); // set the baud rate
delay(100);
Serial.println("Ready"); // print "Ready" once
}

void clearCommand(){ 
  command_str = "                  ";
  }

void serialEvent() {
if(Serial.available()){ // only send data back if data has been sent
command_str = Serial.readString(); // read the incoming data
Serial.println(command_str); // send the data back in a new line so that it is not all one long line
}
}

void loop() {
if(command_str.indexOf("LED") > -1){
  if(command_str.indexOf("ON") > -1){
    digitalWrite(LED_BUILTIN, HIGH);
  }else if(command_str.indexOf("OFF") > -1){
    digitalWrite(LED_BUILTIN, LOW);
  }
  clearCommand(); //clear the command line after each confirmed command
  }
else if(command_str.indexOf("READ") > -1){
  if(command_str.indexOf("A1") > -1){
    A1_value = analogRead(A1);
    Serial.println(A1_value);
  }else if(command_str.indexOf("A2") > -1){
    A2_value = analogRead(A2);
    Serial.println(A2_value);
  }
  clearCommand();
  delay(100);
}
else if(command_str.indexOf("SERVO") > -1){
  command_str.trim();
  if(command_str[0] == "1"){
    command_str.replace("1","");
    command_str.trim();
    pos1 = command_str.toInt();
    servo_1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }else if(command_str[0] == "2"){
    command_str.replace("2","");
    command_str.trim();
    pos2 = command_str.toInt();
    servo_2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    }
  clearCommand();  
}
else if(command_str.indexOf("PWM") > -1){
  command_str.trim();
  if(command_str[0] == "3"){
    command_str.replace("3","");
    command_str.trim();
    dut1 = command_str.toInt();
    analogWrite(3, dut1);
  }else if(command_str[0] == "4"){
    command_str.replace("4","");
    command_str.trim();
    dut2 = command_str.toInt();
    analogWrite(3, dut2);
    }
  clearCommand();
}
}
