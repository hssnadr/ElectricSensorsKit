#include <Adafruit_NeoPixel.h>

//led strip
#define DIN 8          // pin controling the led strip behavior
#define NPIX   15      // number of pixels used in the strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NPIX, DIN, NEO_RGB + NEO_KHZ800);  // replace NEO_RGB by NEO_GRBW if colors are not right

#include <CapacitiveSensor.h>

#define SENSIN 2
#define SENSOUT 4

CapacitiveSensor   capsens = CapacitiveSensor(SENSIN,SENSOUT);

void setup() {
  //led strip setup
  strip.begin(); // This initializes the NeoPixel library.
  strip.show();  // Initialize all pixels to 'off'

  capsens.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  long val_ =  capsens.capacitiveSensor(30);
  Serial.println(val_); 
  delay(10);

  stripOff();
  val_ = map(val_,700,2000, 0, NPIX);
  val_ = constrain(val_, 0, NPIX);

  for(int i=0; i<val_; i++){
    // colors are set based on the Red-Green-Blue code with values constrained between 0 and 255
    //strip.setPixelColor(i, strip.Color(255*val/NPIX,255-255*val/NPIX,0));  // set a shade of color from green to red
    strip.setPixelColor(i, strip.Color(200,200,200));  // set a shade of color from green to red
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
