#include <Servo.h>

Servo myservo;
int sensorVal=0;
int sensorPin=A0;

int buttonPin=7;
int buttonState=0;
int debounceDelay=15;


int pos=0;
void setup() {
  
  Serial.begin(9600);
  pinMode(buttonPin,INPUT_PULLUP);
   myservo.attach(9);
}


void loop() {
  int oldButtonVal = digitalRead(buttonPin);
  
  delay(debounceDelay);
  int newButtonVal = digitalRead(buttonPin);
//   Serial.print("This is");
//      Serial.println(newButtonVal);
  //see if the values are different
  if (newButtonVal == LOW){
    Serial.println(0);
  }
  if (oldButtonVal != newButtonVal) {
     if (newButtonVal == HIGH) {
       buttonState++;
       
      if (buttonState >3) {
        buttonState = 1;
      }
     else if(buttonState==3){
        for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
            // in steps of 1 degree
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
        }
        for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
            myservo.write(pos);              // tell servo to go to position in variable 'pos'
            delay(15);                       // waits 15ms for the servo to reach the position
        }
      }
    } else {
    }
      Serial.println(buttonState);
      
      
    }
  }
  

