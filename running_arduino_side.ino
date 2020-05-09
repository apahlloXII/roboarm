 /*
  testBraccio90.ino

 testBraccio90 is a setup sketch to check the alignment of all the servo motors
 This is the first sketch you need to run on Braccio
 When you start this sketch Braccio will be positioned perpendicular to the base
 If you can't see the Braccio in this exact position you need to reallign the servo motors position

 Created on 18 Nov 2015
 by Andrea Martino

 This example is in the public domain.
 */

#include <Braccio.h>
#include <Servo.h>

int ledPin = 11;    // LED connected to digital pin 9
int pot = A1;
int potval = 0;
int anaval= 0;
int moval = 0;
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;



// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {  
  Serial.begin(9600);
  // initialize the LED pin as an output:
    pinMode(pot, INPUT);
    pinMode(ledPin, OUTPUT);

  
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
  Braccio.begin();
}

void loop() {
  /*
   Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   M1=base degrees. Allowed values from 0 to 180 degrees
   M2=shoulder degrees. Allowed values from 15 to 165 degrees
   M3=elbow degrees. Allowed values from 0 to 180 degrees
   M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
   M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
   M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */


for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):

    // wait for 30 milliseconds to see the dimming effect
    //delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, anaval);
    potval = analogRead(pot);
    anaval = map(potval, 0, 700, 0, 255);
    moval = map(anaval, 0, 255, 0, 100);
    // wait for 30 milliseconds to see the dimming effect
    //delay(30);
    analogWrite(ledPin, anaval);
    Serial.println(moval);
  }


  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Braccio.ServoMovement(20,         (moval), 100, 80, 90, 90, 70); 
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Braccio.ServoMovement(20,         90, 100, 20, 90, 90, 70);  
  }

  // print out the state of the button:
  delay(100);        // delay in between reads for stability

  
  // the arm is aligned upwards  and the gripper is closed
                     //(step delay, M1, M2, M3, M4, M5, M6);
   

	 
}
