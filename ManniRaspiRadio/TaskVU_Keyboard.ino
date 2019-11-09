defineTask(TaskVU_Keyboard, 50)

void TaskVU_Keyboard::setup() {
  //Init Keyboard
  pinMode(Load, OUTPUT);
  pinMode(Clock, OUTPUT);
  pinMode(Data, INPUT);

  //Init MSGEQ7
  pinMode(strobePin, OUTPUT);
  pinMode(resetPin, OUTPUT);
  analogReference(DEFAULT);

  digitalWrite(resetPin, LOW);
  digitalWrite(strobePin, HIGH);
}
void TaskVU_Keyboard::loop() {
  static byte SerialIsStopped = 0, SystemGoesDown = 0;
  /************** Shutdown. Speaker aus bei Power Off, Pi runterfahren */
  if (!digitalRead(SystemOnPin)) {
    SystemGoesDown = 1;
    digitalWrite(SpeakerPin, LOW);
    digitalWrite(PiDownPin, LOW);  //Pi runterfahren mit "shutdown"
    while (digitalRead(PiIsUpPin)) { //warten bis er soweit ist
      sleep(100);
    }
    //sleep(100);
    Serial.println(F("Bobby Brown Goes Down"));
    digitalWrite(RelayOnPin, LOW);  //Netz aus
    while (1);
  }
  /************** Ende Shutdown **************/
  
  /************** VU-Meter **************/
  digitalWrite(resetPin, HIGH);
  delayMicroseconds(30);
  digitalWrite(resetPin, LOW);
  for (  byte band = 0; band < 7; band++ )
  {
    digitalWrite(strobePin, LOW); // strobe pin on the shield - kicks the IC up to the next band
    delayMicroseconds(50);
    Spectrum[band] = analogRead(analogPin) >> 7;
    digitalWrite(strobePin, HIGH);
  }
  VUReady = 1;
  /*********** VU-Meter Ende **********/

  /************** Keyboard **************/
  byte SerCount = 0;
  digitalWrite(Load, LOW);
  digitalWrite(Load, HIGH);  //Daten laden
  KeyboardState = 0;
  for (SerCount = 0; SerCount < 16; SerCount++) {
    KeyboardState = KeyboardState << 1;
    if (digitalRead(Data))
      KeyboardState |= 0x1;
    digitalWrite(Clock, HIGH);
    digitalWrite(Clock, LOW);  //einmal schieben
  }
  /************** Keyboard Ende **************/

  /**************  Radio-Zeug **************/
  if (KeyboardState >> 8) {  //AM-FM-Umschaltung
    RadioOn = 1;
    digitalWrite(audioSwitchPin, HIGH);
  }
  else {
    RadioOn = 0;
    digitalWrite(audioSwitchPin, LOW);
  }
  if ((KeyboardState >> 2) & 0x1)  {  //Bass Boost An/Aus
    radio.setBassBoost(HIGH);
    BassOn = 1;
  }
  else  {
    radio.setBassBoost(LOW);
    BassOn = 0;
  }
  /************** Ende Radio-Zeug **************/
  sleep(20);
}

