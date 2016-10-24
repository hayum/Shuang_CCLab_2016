import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
PImage[] images = new PImage[19];
PImage image;
int imageIndex=0;
float theta= radians(-85);
int ms=0;
int count=0;
int showState=0;
int px=200;
int py=200;

void setup(){
  size(800,600);
  println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  
  smooth();
  ////set sun
  //for(int j=0;j<9;j++){
  //ypos[j] = random(25,height/2); 
  //ypos2[j]=ypos[j];
  //}
  //vel=4;
  //sun=(int)random(9);
  
  ////load chang'e
  for (int i = 0; i< 9; i++){
    images[i]= loadImage("fly"+i+".png");
  }
  
  
  //load houyi
  image=loadImage("pan.png");
  
  
  //frameRate(54);
  //noLoop();
}





void draw(){

   
  fill(51,64,134);
  rect(0,0,width,height);
  
 
  
  ///////////////////////////////////////////////////////////
  //Moon
  fill(251,252,212);
  noStroke();
  ellipse(width/2,height/2,width/2+10,width/2+10);
  filter(BLUR, 9);
  ellipse(width/2,height/2,width/2,width/2);
  
  
  
  
  /////////////////////////////////////////////////////////////
  //Starts
   for(int i=0;i<80;i++){
    rect(random(width),random(height),random(5),random(5));
  }
  

 if(count==1){
  //////////////////////////////////////////////////
  //Chang'e
  //filter(BLUR, 0);
  image(images[imageIndex],width*0.3,height*0.5,224,212);
   imageIndex=(imageIndex+1)%9;
  //tint(255,0);
 
 
  ////////////////////////////////////////////////////////////
  //Tree
   fill(200);
   stroke(100);
   strokeWeight(15);
   pushMatrix();
   translate(width*0.63,height*0.78);
   branch(15);   
   popMatrix();
  }
  
  else if(count==2){
    px+=15;
    py-=15;
    image(image,px,py,300,300);
  }
  else if(count==3){
    px=200;
    py=200;
  }
}

void branch(float h){ 
 // Each branch will be 2/3rds the size of the previous one
   line(0,0,0,-height/6);{
   translate(0,-height/6);
   rotate(random(-0.1,0.1));}
 
   h *= 0.66;
  if (h > 0.2) {
    pushMatrix();    
    rotate(0.3);   
    line(0, 0, 0, -0.9*h);  
    scale(0.7);
    translate(0, -0.9*h); 
    branch(h);      
    popMatrix();   
    
   
    pushMatrix();
    rotate(-0.6);
    line(0, 0, 0, -1.1*h);
    scale(0.7);
    translate(0, -1.1*h);
    branch(h);
    popMatrix();
  }    
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
 
}    