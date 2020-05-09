int arduinoPin = D0;    // LED connected to digital pin 9
int pot = A5;
int potval = 0;
int anaval= 0;

void setup() {
    Serial.begin(9600);
    pinMode(pot, INPUT);
    pinMode(arduinoPin, OUTPUT);
}

void loop() {
  // fade in from min to max in increments of 5 points:
  // for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
  //   // sets the value (range from 0 to 255):
  //
  //   // wait for 30 milliseconds to see the dimming effect
  //   //delay(30);
  // }
  //
  // // fade out from max to min in increments of 5 points:
  // for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    //analogWrite(ledPin, anaval);
    analogWrite(arduinoPin, anaval);
    potval = analogRead(pot);
    anaval = map(potval, 1, 4100, 0, 255);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);


    Serial.print("pot value");
    Serial.println(potval);
    Serial.print("mapped value");
    Serial.println(anaval);
  }
//}
