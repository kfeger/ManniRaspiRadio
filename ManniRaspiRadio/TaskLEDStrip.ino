defineTask(TaskLEDStrip, 150)
//Adafruit_WS2801 LEDStrip = Adafruit_WS2801(9);
#define SHIFT 7
#define LOW_LIMIT 4
#define HIGH_LIMIT 7
int i, j;
void TaskLEDStrip::setup() {
  //LEDStrip.begin();
  // alle LEDs aus
  //LEDStrip.show();
}

void TaskLEDStrip::loop() {
  if (!RadioOn) {
    PreStateFM = 255;
    if (PreStateAM != StateAM) {  //Beachte hier den Befehl PreStateAM = 255 an einigen Stellen unten!
      PreStateAM = StateAM;
      switch (StateAM) {
        case 0:    //Lichtorgel, ganze Breite
          if (VUReady)  {
            colorWipe((Color(Spectrum[1] << random(LOW_LIMIT, HIGH_LIMIT), Spectrum[0] << random(LOW_LIMIT, HIGH_LIMIT), Spectrum[2] << random(LOW_LIMIT, HIGH_LIMIT))), WAIT_WIPE);
            VUReady = 0;
          }
          if (StateAM == PreStateAM)
            PreStateAM = 255;  //Achtung Trick! Mit dem Reset von PreStateAM geht das ganze in eine Loop.
          break;
        case 1:    //helles Weiß
          if KW_2
          colorWipe(Color(255, 255, 255), WAIT_WIPE);
          else if KW_1
          colorWipe(Color(128, 128, 128), WAIT_WIPE);
          else if MW
          colorWipe(Color(64, 64, 64), WAIT_WIPE);
          else if LW
          colorWipe(Color(32, 32, 32), WAIT_WIPE);
          else
            colorWipe(Color(16, 16, 16), WAIT_WIPE);

          PreStateAM = 255;
          break;
        case 2:      //.T..- Farbe
          if KW_2
          colorWipe(Color(226, 0, 106), WAIT_WIPE);
          else if KW_1
          colorWipe(Color(113, 0, 53), WAIT_WIPE);
          else if MW
          colorWipe(Color(56, 0, 26), WAIT_WIPE);
          else if LW
          colorWipe(Color(28, 0, 13), WAIT_WIPE);
          else
            colorWipe(Color(17, 0, 6), WAIT_WIPE);

          PreStateAM = 255;
          break;
        case 3:
          colorWipe(Color(255, 255, 0), WAIT_WIPE);
          break;
        case 4:    //bewegter Regenbogen
          for (j = 0; j < 256 * 1; j++) {   // 5 cycles of all 25 colors in the wheel
            for (i = 0; i < LEDStrip.numPixels(); i++) {
              LEDStrip.setPixelColor(i, Wheel( ((i * 256 / LEDStrip.numPixels()) + j) % 256) );
              if (StateAM != PreStateAM)  //prüfen, ob wir in der Schleife bleiben
                goto EndeRainbow;  //nein, rausspringen
            }
            LEDStrip.show();   // write all the pixels out
            sleep(3 * WAIT_WIPE);
          }
          PreStateAM = 255;
EndeRainbow:
          break;
        case 5:
          if KW_2 {
          Bright = 255;
          randomFillRGB();
          }
          else if KW_1 {
          Bright = 128;
          randomFillRGB();
          }
          else if MW {
          Bright = 64;
          randomFillRGB();
          }
          else if LW {
          Bright = 32;
          randomFillRGB();
          }
          else {
            Bright = 16;
            randomFillRGB();
          }
          PreStateAM = 255;
          sleep(255);
          break;
        case 6:
          colorWipe(Color(0, 255, 255), WAIT_WIPE);
          break;
        case 7:    //stehender Regenbogen
          for (byte i = 0; i < LEDStrip.numPixels(); i++) {
            LEDStrip.setPixelColor(i, Wheel( ((i * 256 / LEDStrip.numPixels()) + j) % 256) );
          }
          LEDStrip.show();
          sleep(WAIT_WIPE);
          break;
        case 8:    //VU-Meter 4.1 Kanäle
          if (VUReady) {
            byte MixBass = (byte)Spectrum[0] << 6;
            byte MixRest1 = (byte)Spectrum[1] << 5;
            byte MixRest2 = (byte)Spectrum[2] << 5;
            byte MixRest3 = (byte)Spectrum[3] << 5;
            LEDStrip.setPixelColor(8, Color(MixBass, MixBass, MixBass));  //optischer Bass Boost
            LEDStrip.setPixelColor(7, Color(MixRest1, MixRest1, 0));
            LEDStrip.setPixelColor(6, Color(MixRest2, 0, MixRest2));
            LEDStrip.setPixelColor(5, Color(0, MixRest3, MixRest3));
            Farbe = 0;
            for (i = 0; i < 7; i++)
              Farbe = Farbe + ((byte)(Spectrum[i] << 6));
            Farbe &= 0xffffff;
            LEDStrip.setPixelColor(4, Farbe);
            LEDStrip.setPixelColor(3, Color(0, MixRest3, MixRest3));
            LEDStrip.setPixelColor(2, Color(MixRest2, 0, MixRest2));
            LEDStrip.setPixelColor(1, Color(MixRest1, MixRest1, 0));
            LEDStrip.setPixelColor(0, Color(MixBass, MixBass, MixBass));
            LEDStrip.show();
            VUReady = 0;
          }
          sleep(5);
          if (StateAM == PreStateAM)
            PreStateAM = 255;
          break;
        default:
          break;
      }
    }
  }
  else  {
    PreStateAM = 255;
    for (byte i = 0; i < LEDStrip.numPixels(); i++) {
      if (i == StateFM)  {
        if B_KEY
        LEDStrip.setPixelColor(i, BASS_AN);
        else
          LEDStrip.setPixelColor(i, BASS_AUS);
      }
      else {
        if BASS
        LEDStrip.setPixelColor(i, Color(64, 64, 64));
        else if SPRACHE
        LEDStrip.setPixelColor(i, Color(64, 64, 0));
        else
          LEDStrip.setPixelColor(i, 0);
      }
    }
    if (PreStateFM != StateFM) {
      PreStateFM = StateFM;
      radio.setFrequency(pgm_read_word_near(&StationPreset[StateFM])); // Senderwahl
    }
    LEDStrip.show();
    sleep(20);
  }
}


