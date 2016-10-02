int ledPin = 9;
int buttonPin=5;

int waitTime1 = 100;
int waitTime2 = 1000;
//init
int wait=1000;
 
int debounceTime = 10;
bool ledState = true;
unsigned long lastBlinkTime = 0;   

void setup() {

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}



void loop() {

  unsigned long currentTime = millis();

  int oldButtonState = 0;
  int newButtonState = 0;

  //button state judge to alter pattern
  oldButtonState = digitalRead(buttonPin);
  delay(debounceTime);
  newButtonState = digitalRead(buttonPin); 
    
  if (oldButtonState != newButtonState) {
      if (newButtonState==LOW){
        if(wait==waitTime2){
          wait=waitTime1;
        }
        else wait=waitTime2;
        Serial.println(wait);
      }
  }
 
  
  //---------------------------------------
  //led pattern
  if (currentTime - lastBlinkTime > wait) {
    ledState = !ledState;
    lastBlinkTime = millis();

  }
  //Serial.println(digitalRead(buttonPin));


  if (ledState) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

}
