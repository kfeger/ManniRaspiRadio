/*
Version 150530
ManniRaspiRadio
Der Steuerungsrechner für das Radio.
Geplante Funktionen:
- LED-Lichtorgel auf Basis WS2801/MSGEQ7
- Auswahl von Effekten mit Drehko AM es Radios
- UKW-radio mit Senderwahl durch UKW-Drehko
- kontrollierter Shutdown des RasPi
- Plopp-Schutz der Lautsprecher
*/

#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <SCoop.h>
#include <Wire.h>
#include "Adafruit_WS2801.h"
#include "SPI.h"
#include <FreqCount.h>
#include <RADIO.h>
#include <RDA5807M.h>

//#include <RDSParser.h>

//Vars für LED-Strip
#define BASS_AUS 0xff0000  //Blau für Bass aus
#define BASS_AN 0x0000ff   //Rot für Bass an
#define WAIT_WIPE 5

//Vars für DrehKos
#define FREQREADTIME 100
int AMFM = 4, AMFM_In = 5, InByte = 0;  //Pin für die Umschaltung
byte AMFM_Flag = 0;  //Flag für die Umschaltung
volatile byte NewFreqData = 0;
volatile byte StateAM = 0;
volatile byte StateFM = 0;
volatile byte PreStateFM = 255, PreStateAM = 255;
volatile unsigned long FreqCurrAM = 0, FreqCurrFM = 0;
#define LENGTH_FM 9
const PROGMEM int LowFM[LENGTH_FM] = {
  100,
  196,
  207,
  220,
  235,
  250,
  270,
  290,
  310
};

const PROGMEM int HighFM[LENGTH_FM] = {
  193,
  205,
  218,
  230,
  245,
  265,
  282,
  302,
  450
};

#define LENGTH_AM 9
const PROGMEM int LowAM[LENGTH_AM] = {
  30,
  48,
  61,
  85,
  120,
  174,
  273,
  403,
  695
};

const PROGMEM int HighAM[LENGTH_AM] = {
  46,
  58,
  76,
  108,
  158,
  250,
  360,
  605,
  800
};

//Vars für Startup
volatile unsigned long StartColor = 0;
volatile byte Started = 5;
#define PiIsUpPin A0    //Input, Low = Pi ist down
#define PiDownPin A1    //Output, fährt Pi runter
#define SpeakerPin A2    //Output, schaltet die Lautsprecher an und aus
#define SystemOnPin A3  //Input, am netzschalter
// A4 & A5 sind I2C
//A6 frei
// A7 ist MSGEQ7
int RelayOnPin = 10;   //Output, überbrückt den Netzschalter für shutdown
int OnBoardLED = 13;

//Vars für WS2801
#define STRIPLEN 9
volatile byte Red = 0, Green = 0, Blue = 0, Bright = 255;
volatile unsigned long Farbe = 0;

//Vars für Keyboard
int Load = 7, Clock = 6, Data = 3;
volatile unsigned int KeyboardState = 0xffff;
volatile byte BassBoostChanged = 0;
#define UKW ((KeyboardState >> 8) & 0x1)
#define KW_2 ((KeyboardState >> 7) & 0x1)
#define KW_1 ((KeyboardState >> 6) & 0x1)
#define MW ((KeyboardState >> 5) & 0x1)
#define LW ((KeyboardState >> 4) & 0x1)
#define TA ((KeyboardState >> 3) & 0x1)
#define B_KEY ((KeyboardState >> 2) & 0x1)
#define SPRACHE ((KeyboardState >> 1) & 0x1)
#define BASS (KeyboardState & 0x1)

//Vars für Audio-Schalter
int audioSwitchPin = 2;

//Vars für MSGEQ7
int analogPin = 7;
int strobePin = 9;
int resetPin = 8;
int Spectrum[7];
volatile byte VUReady = 0;

//UKW-Radio
volatile byte RadioOn = 0;
/* Bremerhaven */
const PROGMEM RADIO_FREQ StationPreset[] = {    //das ist ein uint16_t bzw 'unsigned int'
  8930,  //Bremen Eins
  9540,  //Nordwestradio
  9850,  //NDR Info, Radio Bremen 5
  9890,  //NDR 4
  10080,  //Bremen 4
  10340,  //DLF
  10430,  //Energy Bremen
  10620,  //Deutschlandradio Kultur
  10790    //Hitradio, Antenne Bremen
};
#define NO_OF_STATIONS 9


/* Dresden */
/*const PROGMEM RADIO_FREQ StationPreset[] = {    //das ist ein uint16_t bzw 'unsigned int'
  8920,  //R.SA
  9010,  //MDR Jump
  9110,  //Radio Dresden
  9220,  //MDR 1 Sachsen
  9320,  //Deutchlandradio Kultur
  9730,  //DLF
  10240,  //PSR
  10520,  //RTL Hitradio
  10610  //MDR Info
};*/
#define NO_OF_STATIONS 9

RDA5807M radio;    ///< Create an instance of a RDA5807 chip radio
volatile byte BassOn = 0;
volatile byte PreBassOn = 0;
Adafruit_WS2801 LEDStrip = Adafruit_WS2801(STRIPLEN);


void setup() {
  Serial.begin(9600);
  pinMode(OnBoardLED, OUTPUT);
  pinMode(SpeakerPin, OUTPUT);  //Speaker On/Off
  pinMode(PiDownPin, OUTPUT);  //Pi Shutdown mit LOW
  digitalWrite(PiDownPin, HIGH);
  pinMode(RelayOnPin, OUTPUT);
  digitalWrite(RelayOnPin, HIGH);  //Relais ein für kontrollierten Shutdown
  pinMode(PiIsUpPin, INPUT);  //Low wenn Pi ist down
  pinMode(SystemOnPin, INPUT_PULLUP);  //Schalter an Netzschalter
  //Init DrehKos
  pinMode(AMFM, OUTPUT);
  digitalWrite(AMFM, LOW);
  AMFM_Flag = 0;
  LEDStrip.begin();
  // alle LEDs aus
  LEDStrip.show();

  /************** Einschaltverzögerung, noch ohne Scheduler **************/
  digitalWrite(SpeakerPin, LOW);
  colorWipeNoScoop(Color(48, 0, 0), 1, 75);
  colorWipeNoScoop(Color(0, 96, 0), 0, 100);
  colorWipeNoScoop(Color(0, 0, 142), 1, 125);
  colorWipeNoScoop(Color(226, 0, 106), 0, 150);
  colorWipeNoScoop(Color(255, 255, 255), 1, 175);
  digitalWrite(SpeakerPin, HIGH);
  /************** Ende Einschaltverzögerung **************/

  /**************  Radio vorbereiten **************/
  //Init Audio-Switch
  pinMode(audioSwitchPin, OUTPUT);
  //Init Radio
  radio.init();  //Radio sitzt auf den Adressen 0x10/0x11
  //radio.debugEnable();
  radio.setMono(false);
  radio.setMute(false);
  // radio.debugRegisters();
  radio.setVolume(15);
  radio.setBandFrequency(RADIO_BAND_FM, pgm_read_word_near(&StationPreset[0])); // Bremen Eins
  /**************  Ende Radio vorbereiten **************/

  FreqCount.begin(10);
  randomSeed(analogRead(6));
  mySCoop.start();

  //wdt_enable(WDTO_500MS);
  delay(100);
}

void loop() {
  static byte AMFMSwitch = 0;
  //wdt_reset();

  if (FreqCount.available()) {  //Zeitkritisch, daher in loop(), liest abwechselnd die Frequenz der C/f-Wandler
    NewFreqData = 1;
    if (!AMFMSwitch) {
      FreqCurrAM = FreqCount.read() / 10;
      for (byte i = 0; i < LENGTH_AM; i++) {
        if ((FreqCurrAM >= pgm_read_word(&LowAM[i])) && (FreqCurrAM <= pgm_read_word(&HighAM[i]))) {
          StateAM = i;
          break;
        }
      }
      digitalWrite(AMFM, LOW);
      AMFMSwitch = 1;
    }
    else {
      FreqCurrFM = FreqCount.read() / 10;
      for ( byte i = 0; i < LENGTH_FM; i++) {
        if ((FreqCurrFM >= pgm_read_word(&LowFM[i])) && (FreqCurrFM <= pgm_read_word(&HighFM[i]))) {
          StateFM = i;
          break;
        }
      }
      digitalWrite(AMFM, HIGH);
      AMFMSwitch = 0;
    }
    sleep(2 * FREQREADTIME);  //nach Umschaltung zwei Messperioden warten. Gibt sonst falsche Frequenzen
  }
  sleep(10);
}
