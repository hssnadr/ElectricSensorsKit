#define SENS A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read and print resistor value
  int sensorValue = analogRead(SENS);
  Serial.println(sensorValue);
  delay(1);
}
