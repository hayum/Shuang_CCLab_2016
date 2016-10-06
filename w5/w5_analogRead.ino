int ledPin=9;
int brightness=0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
 
  // print out the value you read:
  Serial.println(sensorValue);
  brightness=map(sensorValue,520,550,0,255);
  analogWrite(ledPin,brightness);
  delay(1);        // delay in between reads for stability
}
