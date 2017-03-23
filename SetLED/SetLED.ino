byte port[] = {2, 3, 4, 5, 6, 7};
byte pocet = 6;
boolean flip = true;

//sets LED on desired level
//@place is counted from 1; maximum is supposed len(ports[])=pocet; no validation
void lightLED(byte place, byte level) {
  digitalWrite(port[place - 1], level);
}

void lightONLED(byte place) {
  lightLED(place, HIGH);
}

void lightOFFLED(byte place) {
  lightLED(place, LOW);
}

void lightONSETLED() {
  for (int place = 1; place <= pocet; place++) {
    lightONLED(place);
  }
}

void lightOFFSETLED() {
  for (int place = 1; place <= pocet; place++) {
    lightOFFLED(place);
  }
}

void lightONBUILTINLED() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void lightOFFBUILTINLED() {
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off (LOW is the voltage level)
}

void blinkALL(byte count, int period) {
  for (int i = 0; i < count; i++) {
    lightONBUILTINLED();
    lightONSETLED();
    delay(period/2);
    lightOFFBUILTINLED();
    lightOFFSETLED();
    delay(period/2);
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  randomSeed(analogRead(A0));
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < pocet; i++) {
    pinMode(port[i], OUTPUT);
  }
  blinkALL(5, 500);
}

// the loop function runs over and over again forever
void loop() {
  blinkALL(1, 500);
  flip = true;
  for (int place = 1; place <= pocet; place++) {
    lightONLED(place);
    if (flip)
      lightONBUILTINLED();
    else
        lightOFFBUILTINLED();
    flip = !flip;
    delay(500);
  }
  flip = true;
  for (int place = pocet; place > 0; place--) {
    lightOFFLED(place);
    if (flip)
      lightONBUILTINLED();
    else
        lightOFFBUILTINLED();
    flip = !flip;
    delay(500);
  }
  int buddy;
  for(int i = 0; i < 100; i++){
    buddy = random(1,pocet + 1);
    lightONLED(buddy);
    delay(100);
    lightOFFLED(buddy);
    delay(100);
  }
}
