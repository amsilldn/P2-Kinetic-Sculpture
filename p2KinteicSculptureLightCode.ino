#include <Adafruit_NeoPixel.h>
 
#define PIN      6
#define N_LEDS 7
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_RGB + NEO_KHZ800);
 
void setup() {
  strip.begin();
}

void loop() {
  colorWipe(strip.Color(0, 255, 0)); // Red
  colorWipe(strip.Color(255, 100, 0)); // Green
  colorWipe(strip.Color(80, 255, 0)); // Orange
  colorWipe(strip.Color(0, 213, 255)); // Purple 0 102 102
}

void colorWipe(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.show();
  }
  delay(3600);
}
