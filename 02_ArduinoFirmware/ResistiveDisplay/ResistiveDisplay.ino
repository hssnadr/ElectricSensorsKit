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
  // Read and print tension value
  int vSens_ = analogRead(SENS);
  Serial.println(vSens_); 

  // Map Vsens value to led strip
  vSens_ = map(vSens_,1015,990, 0, NPIX);
  vSens_ = constrain(vSens_,0, NPIX);

  // Set strip display
  stripOff();                                           // turn off all leds
  for(int i=0; i<vSens_; i++){
    strip.setPixelColor(i, strip.Color(255,255,255));   // turn on wanted leds
  }

  // Display
  strip.show();
  delay(5);
}

void stripOff(){
  for(int i=0; i<NPIX; i++){
    strip.setPixelColor(i, strip.Color(0,0,0)); // set color to black
  }
}
