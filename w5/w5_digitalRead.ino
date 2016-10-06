int ledPin=9;
int ledPin2=10;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  if(sensorValue>970 && sensorValue<980){
    digitalWrite(ledPin,HIGH);
    digitalWrite(ledPin2,LOW);
  }
  else{
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin,LOW);
  }
  delay(1);        // delay in between reads for stability
}
