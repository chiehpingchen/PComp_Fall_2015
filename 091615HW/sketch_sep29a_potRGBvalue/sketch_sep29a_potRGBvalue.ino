int rLedPin = 7;
int gLedPin = 6;
int bLedPin = 5;

int rButton = 12;
int gButton = 11;
int bButton = 10;

//int rButtonState = 0;
//int gButtonState = 0;
//int bButtonState = 0;

int rBrightness = 0;
int gBrightness = 0;
int bBrightness = 0;

int sensorPin = 0;
int sensorValue = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(rLedPin, OUTPUT); 
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);

  pinMode(rButton, INPUT);
  pinMode(gButton, INPUT);
  pinMode(bButton, INPUT);

}

void loop() {
  sensorValue = analogRead(sensorPin);

//if (digitalRead(rButtonState) == 1){
if (digitalRead(rButton) == HIGH){
  rBrightness = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(rLedPin, rBrightness);
  
} 

//if (digitalRead(gButtonState) == 1){
if (digitalRead(gButton) == HIGH){
  gBrightness = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(gLedPin, gBrightness);
  
} 

//if (digitalRead(bButtonState) == 1){
if (digitalRead(bButton) == HIGH){
  bBrightness = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(bLedPin, bBrightness);
}

  Serial.println(sensorValue);

//  Serial.println(rButtonState);
//  Serial.println(gButtonState);
//  Serial.println(bButtonState);
  delay(2000);
}
