
// fill the dots one after the other with said color
// good for testing purposes
void colorWipeNoScoop(uint32_t c, uint8_t Dir, uint8_t wait) {
  int i;
  if (Dir) {
    for (i = 0; i < LEDStrip.numPixels(); i++) {
      LEDStrip.setPixelColor(i, c);
      LEDStrip.show();
      delay(wait);
    }
  }
  else {
    for (i = (LEDStrip.numPixels() - 1); i ; i--) {
      LEDStrip.setPixelColor(i, c);
      LEDStrip.show();
      delay(wait);
    }
  }
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;

  for (i = 0; i < LEDStrip.numPixels(); i++) {
    LEDStrip.setPixelColor(i, c);
    LEDStrip.show();
    //sleep(wait);
  }
  sleep(wait);
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
    return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 170;
    return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void PickRandomBase(void) {
  uint8_t ColorPick = (unsigned char)random(1, 7);
  switch (ColorPick) {
    case 1:
      Red = Bright;
      Green = 0;
      Blue = 0;
      break;
    case 2:
      Red = 0;
      Green = Bright;
      Blue = 0;
      break;
    case 3:
      Red = Bright;
      Green = Bright;
      Blue = 0;
      break;
    case 4:
      Red = 0;
      Green = 0;
      Blue = Bright;
      break;
    case 5:
      Red = Bright;
      Green = 0;
      Blue = Bright;
      break;
    case 6:
      Red = 0;
      Green = Bright;
      Blue = Bright;
      break;
    case 7:
      Red = Bright;
      Green = Bright;
      Blue = Bright;
      break;
    default:
      Red = 128;
      Green = 128;
      Blue = 128;
      break;
  }
}

void randomFillRGB(void) {
  for (uint8_t i = 0; i < STRIPLEN; i++) {
    PickRandomBase();
    LEDStrip.setPixelColor(i, Color(Red, Green, Blue));
  }
  LEDStrip.show();
}

