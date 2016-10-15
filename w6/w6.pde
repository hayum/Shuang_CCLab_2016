import processing.serial.*;
import cc.arduino.*;

Arduino arduino;

void setup() {
  size(470, 280);

  println(Arduino.list());
  
  arduino = new Arduino(this, Arduino.list()[0], 57600);
  arduino.pinMode(0, Arduino.INPUT);
}

void draw() {

 if(frameCount%25==0){
  
  background(255);
  noStroke();
  
  //read temperature
  float c=arduino.analogRead(0);
  c=map(c,90,125,100,255);
  println(arduino.analogRead(0));
  println(c);
  
  
  /////////////////////////////////////////////////////
  //draw a leaf
  fill(c/8,103,93);
  quad(200,155-c/2, 215+c/8, 140-c/2,220+c/8,120-c/2,207,130-c/2);
 
 
  ////////////////////////////////////////////////////
  //draw fruit
  //mature color
  if(c<110){
    fill(c,255,0);
  }
  else{
    fill(220,255-c,0);
  }
  //grow size
  ellipse(200,150,c,c);
  arduino.digitalWrite(8,Arduino.HIGH);
  
  
 }
}