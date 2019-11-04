#include <CapacitiveSensor.h>

#define SENSIN 2
#define SENSOUT 4

CapacitiveSensor   capsens = CapacitiveSensor(SENSIN,SENSOUT);

void setup() {
  capsens.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  long val =  capsens.capacitiveSensor(30);
  Serial.println(val); 
  delay(10);
}
