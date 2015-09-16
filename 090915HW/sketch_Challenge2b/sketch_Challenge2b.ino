void setup() {
  Serial.begin(9600);
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
  } else if ( digitalRead(7) == 1){
              digitalWrite(3,LOW);
} 

if( digitalRead(8) ==0){
    digitalWrite(5,HIGH);
  } else if ( digitalRead(8) == 1){
              digitalWrite(5,LOW);
}

}
