## Resistive sensor Kit
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/ResistiveSensor.jpg) 
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

## Capacitive Sensor Kit
### Single
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/CapacitiveSensor_01.jpg) 
```
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
```
### Chain
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/CapacitiveSensor_02.jpg) 

## Led Display Kit
![alt tag](https://github.com/hssnadr/MotionLab_KIT/blob/master/LedDisplay.jpg) 
```
#include <Adafruit_NeoPixel.h>

//led strip
#define DIN 8          // pin controling the led strip behavior
#define NPIX   15      // number of pixels used in the strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NPIX, DIN, NEO_RGB + NEO_KHZ800);  // replace NEO_RGB by NEO_GRBW if colors are not right

void setup() {
  //led strip setup
  strip.begin(); // This initializes the NeoPixel library.
  strip.show();  // Initialize all pixels to 'off'
}

void loop() {
  // compute current led index
  unsigned long ipix = millis()/80;
  ipix %= NPIX;

  // set new led colors
  if(ipix==0){
    stripOff(); // reset led display at each cycle
  }
  for(int i=0; i<ipix+1; i++){
    // colors are set based on the Red-Green-Blue code with values constrained between 0 and 255
    strip.setPixelColor(i, strip.Color(255*ipix/NPIX,255-255*ipix/NPIX,0));  // set a shade of color from green to red
  }

  // display new led colors
  strip.show();
  delay(5);
}

void stripOff(){
  for(int i=0; i<NPIX; i++){
    strip.setPixelColor(i, strip.Color(0,0,0)); // set color to black
  }
}
```
