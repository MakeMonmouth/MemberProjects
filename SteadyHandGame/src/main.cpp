#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#include "Button2.h"


// Setup the Button that will be used for the wire loop

#define BUTTON_PIN D3

Button2 wire_loop;

// Setup the neopixels
#define NEOPIN D2
#define NUMPIXELS 8
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIN, NEO_GRB + NEO_KHZ800);
// Here is where you can put in your favorite colors that will appear!
// just add new {nnn, nnn, nnn}, lines. They will be picked out randomly
//                          R   G   B
uint8_t myColors[][3] = {{232, 100, 255},   // purple
                        {200, 200, 20},   // yellow
                        {30, 200, 200},   // blue
                        {237,159,176},    // pink
                        {255, 0, 0},      // red
                        {108, 87,229},     // Dark blue
                        {162,211,172},     // Lt Green
                          };

#define FAVCOLORS sizeof(myColors) / 3

int lives_left = 8;
int game_in_progress = 1;

void handleTap(Button2& b){
    // Check if the wire has been tapped against the loop and update
    // the score/lives remaining as appropriate
    Serial.println("Not steady enough! You lose a life!");
    lives_left = lives_left - 1;
    pixels.setPixelColor(lives_left, pixels.Color(128,0,0));
    pixels.show();
}

void flashRandom(int wait, uint8_t howmany) {
 
  for(uint16_t i=0; i<howmany; i++) {
    // pick a random favorite color!
    int c = random(FAVCOLORS);
    int red = myColors[c][0];
    int green = myColors[c][1];
    int blue = myColors[c][2]; 
 
    // get a random pixel from the list
    int j = random(pixels.numPixels());
    
    // now we will 'fade' it in 5 steps
    for (int x=0; x < 5; x++) {
      int r = red * (x+1); r /= 5;
      int g = green * (x+1); g /= 5;
      int b = blue * (x+1); b /= 5;
      
      pixels.setPixelColor(j, pixels.Color(r, g, b));
      pixels.show();
      delay(wait);
    }
    // & fade out in 5 steps
    for (int x=5; x >= 0; x--) {
      int r = red * x; r /= 5;
      int g = green * x; g /= 5;
      int b = blue * x; b /= 5;
      
      pixels.setPixelColor(j, pixels.Color(r, g, b));
      pixels.show();
      delay(wait);
    }
  }
  // LEDs will be off when done (they are faded to 0)
}

void setup() {
    Serial.begin(115200);
    delay(50);
    Serial.println("=== Setting up the wire game");

    wire_loop.begin(BUTTON_PIN);
    wire_loop.setTapHandler(handleTap);

    pixels.begin();
    pixels.setBrightness(30);
    for (int i = 0;i<NUMPIXELS;i++){
        pixels.setPixelColor(i, pixels.Color(0,128,0));
    }
    pixels.show();

}

void loop() {

    if (lives_left < 1){
        if (game_in_progress == 1){
            Serial.println("=== YOU LOSE!!!!! ===");
            game_in_progress = 0;
            flashRandom(15, 8);
            flashRandom(5, 8);
            flashRandom(15, 8);
            delay(5000);
            ESP.restart();
        }
    } else {
        wire_loop.loop();
    }

}
