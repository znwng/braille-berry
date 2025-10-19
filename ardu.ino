int DELAY_MS =50;

int ledPins[8] = {3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void printBraille(int bits[8]) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], bits[i] ? HIGH : LOW);
  }
}

void zero2255() {
  int bits[8];
  for (int b = 0; b < 256; b++) {
    for (int i = 0; i < 8; i++) {
      bits[i] = (b >> (7 - i)) & 1;
    }
    printBraille(bits);
    delay(DELAY_MS);
  }
}

int loadingSetUp[8][8] = {
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 1, 0, 1, 1},
  {1, 1, 1, 0, 1, 1, 1, 1},
  {1, 0, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 0, 1}
};

int loadingSetDown[8][8] = {
  {1, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 1, 0, 1, 0, 0},
  {0, 1, 0, 1, 0, 0, 0, 0},
  {1, 1, 0, 0, 0, 0, 0, 0}
};

void loading(int durationMs) {
  unsigned long startTime = millis();

  while (millis() - startTime < durationMs) {
    for (int i = 0; i < 8; i++) {
      printBraille(loadingSetDown[i]);
      delay(DELAY_MS);
    }
  }
}

void loop() {
  loading(10000);
}

