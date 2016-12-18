#include <CapacitiveSensor.h>


const int sampleWindow = 100; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;
int house1=A0;
int blowTime;
double peakAll,averagePeak;

const int scarePin = 11;
int scareState;

int heelPin = A2; // Use Pin 10 as our Input
int heelVal; // This is where we record our shock measurement
boolean kAlarm = false;
unsigned long lastKnockTime; // Record the time that we measured a shock
int knockAlarmTime = 500;
int knockT=0;

int buttonPin=7;
int buttonState=1;
int debounceDelay=15;

int witch3=3;

int ledPin=13;

int judge=0;


void setup() {
  
  Serial.begin(9600);
  //pinMode(buttonPin,INPUT_PULLUP);
 // pinMode (soundDetectedPin, INPUT) ;
  pinMode(scarePin, INPUT_PULLUP);
   pinMode(witch3, INPUT_PULLUP);
  pinMode (heelPin, INPUT) ; // input from the KY-031
  pinMode(ledPin,OUTPUT);
}


void loop() {
//  int oldButtonVal = digitalRead(buttonPin); 
//  delay(debounceDelay);
//  int newButtonVal = digitalRead(buttonPin);
  //Serial.println(newButtonVal);
// if (oldButtonVal != newButtonVal) {
//   
//     if (newButtonVal == LOW) {
//     // Serial.println(newButtonVal);
//        buttonState++;     
//         if (buttonState >4) {
//            buttonState = 0;
//            judge=0;
//        }
//     }
// }
 if(buttonState==1){
      
      unsigned long startMillis= millis();  // Start of sample window
      unsigned int peakToPeak = 0;   // peak-to-peak level

      unsigned int signalMax = 0;
      unsigned int signalMin = 1024;

      // collect data for 50 mS
      while (millis() - startMillis < sampleWindow)
      {
            sample = analogRead(house1);
            if (sample < 1024)  // toss out spurious readings
            {
                if (sample > signalMax)
               {
                    signalMax = sample;  // save just the max levels
                }
                else if (sample < signalMin)
               {
                    signalMin = sample;  // save just the min levels
                }
           }
       }
      peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
      peakAll=peakAll+peakToPeak;
      blowTime++;
      
      if(blowTime==6){
        averagePeak=peakAll/blowTime;
        peakAll=0;
        blowTime=0;
      }
      double volts = (averagePeak * 5.0) / 1024;  // convert to volts
    // Serial.print("volt: ");
    //Serial.println(volts);
      if (volts>4)
      {
         
         judge=1;
         digitalWrite(ledPin,HIGH);
         buttonState=2;
         Serial.println(1); 
       }
      else{
         digitalWrite(ledPin,LOW);
           Serial.println(0); 
      }
      
  }
  else if(buttonState==2){
         scareState = digitalRead(scarePin);
         //Serial.println(scareState);
         if (scareState == HIGH) {
             digitalWrite(ledPin, HIGH);
             judge=2; 
             buttonState=3; 
             Serial.println(2);  
         }
         else {
              digitalWrite(ledPin, LOW);
             //Serial.println(0);
        }
 }

 else if(buttonState==3){
       if(digitalRead(witch3)==HIGH)
       {
          judge=3;
          digitalWrite(ledPin,HIGH);
        // Serial.println("H"); 
         buttonState=4;   
         Serial.println(3);               
       }
       else
       {
        digitalWrite(ledPin,LOW);
        //Serial.println("L");
        }
  }
  
  else if(buttonState==4){ 
         heelVal = analogRead(heelPin);
       //  Serial.println(heelVal);
         if (heelVal > 400){
             digitalWrite(ledPin, HIGH);
              knockT++;
              delay(200);
              Serial.println(5); 
         }
       else{
          digitalWrite(ledPin, LOW);
        }
        if(knockT>=3){
               //Serial.println(4);
               delay(1000);
               knockT=0;
               judge=4;
               buttonState=5;
               Serial.println(4); 
       } 
         
       delay(100);
       //Serial.println("k");        
  }
//Serial.println(judge); 
}


        
      

