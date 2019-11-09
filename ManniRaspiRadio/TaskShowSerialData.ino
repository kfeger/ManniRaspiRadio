defineTask(TaskShowSerialData, 100)
void TaskShowSerialData::setup() {
  trace("ShowSerialData_setup");
}

void TaskShowSerialData::loop()  {
  /*if (NewFreqData) {
    Serial.print(F("Freqenz AM = "));
    Serial.print(FreqCurrAM);
    Serial.print(F("kHz, Freqenz FM = "));
    Serial.print(FreqCurrFM);
    Serial.println(F("kHz"));
    Serial.print(F("StateAM = "));
    Serial.print(StateAM);
    Serial.print(F(", StateFM = "));
    Serial.println(StateFM);
    if(RadioOn)
      Serial.println(F("Radio an"));
    else
      Serial.println(F("Radio aus"));
    Serial.print(F("Tasten = "));  //vollständige Darstellung aller Tasten
    for(byte i = 8; i < 200; i--) {
      if((KeyboardState >> i) & 0x1)
        Serial.print("1");
      else
        Serial.print("0");
        }
    Serial.println("");*/
    /*Serial.print(F("freies RAM in TaskLEDStrip "));
    Serial.println(TaskLEDStrip.stackLeft());
    Serial.print(F("freies RAM in TaskRadio "));
    Serial.println(TaskRadio.stackLeft());
    //Serial.print(F("freies RAM in TaskVU_Keyboard "));
    //Serial.println(TaskVU_Keyboard.stackLeft());
    //Serial.print(F("freies RAM in TaskShowSerialData "));
    //Serial.println(TaskShowSerialData.stackLeft());
    Serial.println("******************************");*/
    /*NewFreqData = 0;
    if(VUReady) {
      for(byte i = 0; i < 7; i++) {
        Serial.print(Spectrum[i], HEX);
        Serial.print(" ");
        }
        Serial.print(" ");
        Serial.print(Farbe, HEX);
      Serial.println("");
      }*/
  //}
  sleep(200);
}

