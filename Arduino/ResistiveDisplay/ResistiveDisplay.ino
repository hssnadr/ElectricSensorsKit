#include <Adafruit_NeoPixel.h>

#define SENS A0

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
  // read and print resistor value
  int sensorValue = analogRead(SENS);
  Serial.println(sensorValue); 
  
  stripOff();
  val = map(val,1015,990, 0, NPIX);
  val = constrain(val,0, NPIX);

  for(int i=0; i<val; i++){
    // colors are set based on the Red-Green-Blue code with values constrained between 0 and 255
    //strip.setPixelColor(i, strip.Color(255*val/NPIX,255-255*val/NPIX,0));  // set a shade of color from green to red
    strip.setPixelColor(i, strip.Color(255,255,255)); 
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
