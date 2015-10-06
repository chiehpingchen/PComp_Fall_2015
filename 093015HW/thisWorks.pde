import processing.serial.*;
Serial port;
float val;
float xpos=1;
float easing=0.05;
float easedVal;
void setup(){
size(440,440);
frameRate(60);
smooth();

String arduinoPort=Serial.list()[0];
port=new Serial(this,arduinoPort,9600);

background(0);
}

void draw(){
  
if(port.available()>0){
val=port.read();
println(val);
val=map(val,0,1023,0,440);
}
float targetVal=val;
easedVal+=(targetVal-easedVal)*easing;

stroke(0);
line(xpos,0,xpos,height);
stroke(255);
//line(xpos+1,0,xpos+1,height);
//line(xpos,220,xpos,val);
line(xpos,440,xpos,440-easedVal);


xpos=xpos+0.5;
if (xpos>width){
xpos=0;}
}