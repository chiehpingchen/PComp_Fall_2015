int sensorPin = 0;
int val=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
val=analogRead(sensorPin);
Serial.println(val);
delay(20);
}
