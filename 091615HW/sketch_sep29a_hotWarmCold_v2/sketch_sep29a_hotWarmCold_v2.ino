int redState = LOW;
int greenState = LOW;
int blueState = LOW;
int redLedPin = 11;
int greenLedPin = 10;
int blueLedPin = 9;
int sensorValue = 0;
int sensorPin = 0;

//int coldValue = 35;
//int hotValue = 140;

void setup() {
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
if (sensorValue > 1000){
  
  digitalWrite(redLedPin, LOW); 
  digitalWrite(greenLedPin, LOW); 
  digitalWrite(blueLedPin, HIGH);
 
} else if (sensorValue < 990) {
  digitalWrite(redLedPin, HIGH); 
  digitalWrite(greenLedPin, LOW); 
  digitalWrite(blueLedPin, LOW);  
} else {
  digitalWrite(redLedPin, LOW); 
  digitalWrite(greenLedPin, HIGH); 
  digitalWrite(blueLedPin, LOW);
}


Serial.println(sensorValue);
delay(2000);

}
