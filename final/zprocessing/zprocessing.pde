import processing.video.*;
import processing.serial.*;
import processing.sound.*;

SoundFile file[];
Serial myPort;
Movie myMovie[];
float t0;
float t;
int index = 0,indicator=0;
int count=0;

PImage[] images1 = new PImage[24];
PImage[] images2 = new PImage[7];
PImage[] images3 = new PImage[9];
PImage[] images4 = new PImage[12];
int imageIndex1,imageIndex2,imageIndex3,imageIndex4;
int w=1536,h=864;
void setup() {
  //size(1536, 864);
  frameRate(24);
 fullScreen();
  println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
 
  myMovie = new Movie[4];
 
  myMovie[0]  = new Movie(this, "house.mp4");
  myMovie[1]  = new Movie(this, "scarecrow.mp4");
  myMovie[2]  = new Movie(this, "witch.mp4");
  myMovie[3]  = new Movie(this, "body.mp4");
  myMovie[0].pause();
  myMovie[1].pause();
  myMovie[2].pause();
  myMovie[3].pause();
  
  file = new SoundFile[4];
  file[0] = new SoundFile(this, "wind.wav");
  file[1] = new SoundFile(this, "wood.wav");
  file[2] = new SoundFile(this, "water.WAV");
  file[3] = new SoundFile(this, "ding.wav");
 
  
  
   for (int i = 0; i< 24; i++){
    images1[i]= loadImage(i+".jpg");
  }
   for (int i = 0; i< 7; i++){
    images2[i]= loadImage("scarecrowcolorsai"+i+".png");
  }
  for (int i = 0; i< 9; i++){
    images3[i]= loadImage("witch"+i+".png");
  }
  for (int i = 0; i< 12; i++){
    images4[i]= loadImage("dorothy"+i+".png");
  }
}
 
 
void draw() {
  background(0);
 
  if (myMovie[index].available() ) {
    myMovie[index].read();
  }
  image(myMovie[index], 0, 0,w,h);
 
  if (t > myMovie[index].duration() + t0) {
    //println("finished! "+index);
   
    if(index==0){
      image(images2[imageIndex2],0,0,w,h);
      imageIndex2=(imageIndex2+1)%7;
    }
    else if(index==1){
      image(images3[imageIndex3],0,0,w,h);
      imageIndex3=(imageIndex3+1)%9;
    }
    else if(index==2){
      image(images4[imageIndex4],0,0,w,h);
      imageIndex4=(imageIndex4+1)%12;
    }
  }
  if(count==0){
      image(images1[imageIndex1],0,0,w,h);
      imageIndex1=(imageIndex1+1)%24;
      
  }
  t  = millis()/1000;
}
 
 

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // convert to an int and map to the screen height:
    count = int(inString);
    println(count);
  }
  //if(indicator==0){
   if (count == 1) {
   
    myMovie[0].play();
    file[0].play();
    file[0].rate(0.25);
    index = 0;
    t0 = millis()/1000;
  }
 
  if (count == 2) {
    myMovie[1].play();
    file[1].play();
      file[1].rate(0.2);
    index = 1;
    t0 = millis()/1000;
  }
  if (count == 3) {
    file[2].play();
    file[2].rate(0.25);
    myMovie[2].play();
    index = 2;
    t0 = millis()/1000;
  }
  if (count == 4) {
    //file.play();
    myMovie[3].play();
    index = 3;
    t0 = millis()/1000;
  }
    if (count == 5) {
    file[3].play();
  }
} 


//void movieEvent(Movie m) {
// // m.read();
// if (count == 1) {
//    myMovie[0].play();
//    index = 0;
//    t0 = millis()/1000;
//  }
 
//  if (count == 2) {
//    myMovie[1].play();
//    index = 1;
//    t0 = millis()/1000;
//  }
//  if (count == 3) {
//    myMovie[2].play();
//    index = 2;
//    t0 = millis()/1000;
//  }
//  if (count == 4) {
//    myMovie[3].play();
//    index = 3;
//    t0 = millis()/1000;
//  }
   
//}