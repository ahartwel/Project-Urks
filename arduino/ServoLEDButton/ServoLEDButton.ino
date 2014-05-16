#include <Servo.h>
Servo myservo;
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int button = 2;
int buttonOn  =0;
int pos = 0;
boolean movingUp=true;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
pinMode(button, INPUT);  
myservo.attach(9);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonOn = digitalRead(button);
  
  if (buttonOn == HIGH) {
     digitalWrite(led, HIGH);
  } else {
     digitalWrite(led, LOW);
     if (movingUp) {
       pos+=10;
     } else {
      pos-=10; 
     }
     if (pos>=180) {
      movingUp=false;
     } else if(pos<=0) {
       movingUp=true;
     }
     myservo.write(pos);
     delay(35);
    }

}
