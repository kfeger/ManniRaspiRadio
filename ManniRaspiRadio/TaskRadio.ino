/*defineTask(TaskRadio, 75)
void TaskRadio::setup() {
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
}

void TaskRadio::loop() {
  if UKW {  //AM-FM-Umschaltung
    RadioOn = 1;
    digitalWrite(audioSwitchPin, HIGH);
  }
  else {
    RadioOn = 0;
    digitalWrite(audioSwitchPin, LOW);
  }
  //radio.setFrequency(pgm_read_word_near(&StationPreset[StateFM])); // Senderwahl
  if B_KEY  {  //Bass Boost An/Aus
    radio.setBassBoost(HIGH);
    BassOn = 1;
  }
  else  {
    radio.setBassBoost(LOW);
    BassOn = 0;
  }
  sleep(100);
}*/
