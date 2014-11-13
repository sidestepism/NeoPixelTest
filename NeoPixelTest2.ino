#include <Adafruit_NeoPixel.h>

#define PIN            4
#define NUMPIXELS      30

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(9600); // send and receive at 9600 baud
}

int brightness = 0;

void loop() {
  if(analogRead(5) < 100){
    brightness = 50;
  }else{
    if(brightness > 0){
      brightness = brightness / 1.1;
    }
  }
  
  // put your main code here, to run repeatedly:
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(brightness,brightness,brightness)); // Moderately bright green color.
  }
  pixels.show(); // This sends the updated pixel color to the hardware.
  delay(20);
}
