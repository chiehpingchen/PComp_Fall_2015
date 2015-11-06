#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20 A1

OneWire ourWire(DS18B20);
DallasTemperature sensors(&ourWire);

int redState = LOW;
int greenState = LOW;
int blueState = LOW;

int redLedPin = 11;
int greenLedPin = 10;
int blueLedPin = 9;

int photoValue = 0;
int photoPin = A0;

const int buzzer = 6;


void setup() {
  Serial.begin(9600);

  delay(1000);
  sensors.begin();

  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  sensors.requestTemperatures();
  photoValue = analogRead(photoPin);

  if (photoValue < 350) {

    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
    digitalWrite(buzzer, 0);
    delay(50);

  } else if (sensors.getTempCByIndex(0) >= 15) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, LOW);

    for ( int ii = 0; ii < 10; ii++ ) {
      tone(buzzer, 1000);
      delay(50);
      tone(buzzer, 500);
      noTone(buzzer);
      delay(50);
    }
  } else if (sensors.getTempCByIndex(0) > 10 && sensors.getTempCByIndex(0) < 15) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(blueLedPin, LOW);
    noTone(buzzer);
    delay(1000);

  } else if (photoValue > 350) {

    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, HIGH);
    noTone(buzzer);
    delay(1000);

  }

  Serial.println("brightness");
  Serial.println(photoValue);
  Serial.println(" ");

  Serial.print(sensors.getTempCByIndex(0));
  Serial.println(" deg C");
  Serial.println(" ");

  delay(3000);

}
