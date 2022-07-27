#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

#define arm 15
#define disarm 20

bool armed =  false;

int ccwMotor1 = 6;
int ccwMotor2 = 9;
int cwMotor3 = 10;
int cwMotor4 = 11; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo1.attach(ccwMotor1); //PWM Pin Connection
  myservo2.attach(ccwMotor2);
  myservo3.attach(cwMotor3);
  myservo4.attach(cwMotor4);
  delay(1);
  myservo1.write(arm); //Required to activate ESC
  myservo2.write(arm);
  myservo3.write(arm);  
  myservo4.write(arm);
  
 // delay(4000); //Mandatory Wait Time
}

void loop() {
  // put your main code here, to run repeatedly:
//  int val = Serial.parseInt(); //read integer values sent through serial monitor
//  if(val > 0){
//    armed = true;
//  }
  delay(2500); //Wait time before main program starts (Safety feature)
  armed = true;
  int val = 0;
  while(armed){
    val = 49;
    Serial.println(val);    //Displays read int value
    myservo1.write(val);    // Writes read int value to ESC
    myservo2.write(val);
    myservo3.write(val); 
    myservo4.write(val);
    delay(2000);
    armed = false;
    myservo1.write(disarm);
    myservo2.write(disarm);
    myservo3.write(disarm); 
    myservo4.write(disarm);
  }
}
