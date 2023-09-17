#include <FastLED.h>

#define NUM_LEDS 12         // Number of LEDs in your strip
#define LED_PIN 4          // Pin connected to the data pin of the LED strip
#define BUTTON_PIN 3       // Pin connected to the button

CRGB leds[NUM_LEDS];       // FastLED object

int currentColor = 0;      // Current color index
int buttonState = 0;       // Current state of the button
int lastButtonState = 0;   // Previous state of the button

void setup() {
  Serial.begin(9600);

  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);  // Initialize the LED strip
  pinMode(BUTTON_PIN, INPUT_PULLUP);                      // Set the button pin as input with internal pull-up resistor
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);  // Read the state of the button
  
  if (buttonState != lastButtonState) {
//    if (buttonState == LOW) {
    if (buttonState == HIGH) {
      // Button was pressed
      currentColor = (currentColor + 1) % 10;  // Increment current color index
      
      switch (currentColor) {
        case 0:  
          fill_solid(leds, NUM_LEDS, CRGB::White); // White
          break;
        case 1:
          fill_solid(leds, NUM_LEDS, CRGB::Red); // Red
          break;
        case 2: 
          fill_solid(leds, NUM_LEDS, CHSV(HUE_ORANGE,255,255)); // Orange
          break;
        case 3:  // Yellow 
          fill_solid(leds, NUM_LEDS, CHSV(HUE_YELLOW,255,255)); // Yellow
          break;
        case 4:  // Blue 
          fill_solid(leds, NUM_LEDS, CHSV(HUE_PURPLE, 255, 255)); // Purple
          break;
        case 5: 
          fill_solid(leds, NUM_LEDS, CHSV( 224, 187, 255)); // Pink
          break;
        case 6: 
          fill_solid(leds, NUM_LEDS, CRGB::Blue); // Blue
          break;
        case 7: 
          fill_solid(leds, NUM_LEDS, CHSV(128, 255, 255)); // Teal
          break;
        case 8:  
          fill_solid(leds, NUM_LEDS, CRGB::Green); // Green
          break;
        case 9:  // Black
          fill_solid(leds, NUM_LEDS, CRGB::Black);
          break;
      }
      
      FastLED.show();  // Update the LED strip with the new color
    }
  }
  
  lastButtonState = buttonState;  // Store the current button state for comparison in the next iteration
}
