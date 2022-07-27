#include <Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(6); //PWM Pin Connection
  delay(1);
  myservo.write(15); //Required to activate ESC
 // delay(5000); //Mandatory Wait Time
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    int val = Serial.parseInt(); 
    Serial.println(val);
    myservo.write(val);
    delay(10000);
  }
}
