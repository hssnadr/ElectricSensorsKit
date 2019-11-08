#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>

// Sensor
#define SENSIN 2
#define SENSOUT 4
CapacitiveSensor   capsens = CapacitiveSensor(SENSIN,SENSOUT);
int rangeMin = 700 ;  // rangeMin and rangeMax must be adapt in function of the wanted behavior (more or less sensitivity)
int rangeMax = 2000 ;

// Led strip
#define DIN 8          // pin controling the led strip behavior
#define NPIX   15      // number of pixels used in the strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NPIX, DIN, NEO_RGB + NEO_KHZ800);  // replace NEO_RGB by NEO_GRBW if colors are not right

void setup() {
  //led strip setup
  strip.begin(); // This initializes the NeoPixel library.
  strip.show();  // Initialize all pixels to 'off'

  capsens.set_CS_AutocaL_Millis(0xFFFFFFFF);
  Serial.begin(9600);
}

void loop() {
  // Sens values
  long val_ =  capsens.capacitiveSensor(30);
  Serial.println(val_); 
  delay(10);

  // Map values
  val_ = map(val_,rangeMin, rangeMax, 0, NPIX);
  val_ = constrain(val_, 0, NPIX);

  // Set strip display
  stripOff();                                           // turn off all leds
  for(int i=0; i<val_; i++){
    // colors are set based on the Red-Green-Blue code with values constrained between 0 and 255
    strip.setPixelColor(i, strip.Color(200,200,200));
  }

  // Display leds
  strip.show();
  delay(5);
}

void stripOff(){
  for(int i=0; i<NPIX; i++){
    strip.setPixelColor(i, strip.Color(0,0,0)); // set color to black
  }
}
