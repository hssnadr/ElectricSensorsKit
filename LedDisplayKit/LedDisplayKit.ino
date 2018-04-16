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
