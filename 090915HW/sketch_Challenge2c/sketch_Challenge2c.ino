
const unsigned int PAUSE = 500;
const unsigned int BAUD_RATE =9600;

void setup() {
  Serial.begin(BAUD_RATE);
     pinMode(7,INPUT_PULLUP);
     pinMode(8,INPUT_PULLUP);
     Serial.println("Hello!");
     pinMode(3,OUTPUT);
     pinMode(5,OUTPUT);
}

void loop() {
  
  Serial.println( '7',digitalRead(7) );
  Serial.println( '8',digitalRead(8) );

if( digitalRead(7) == 0){
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);    
    delay(50);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    delay(50); 
} 

if( digitalRead(8) == 0){
    digitalWrite(3,HIGH);
    digitalWrite(5,HIGH);    
    delay(500);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    delay(500); 
}

}
