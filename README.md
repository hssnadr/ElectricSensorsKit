## Resistive sensor Kit
```
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
```
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/ResistiveSensor.jpg) 

## Capacitive Sensor Kit
### Single
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/CapacitiveSensor_01.jpg) 
### Chain
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/CapacitiveSensor_02.jpg) 

## Led Display Kit
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/LedDisplay.jpg) 
