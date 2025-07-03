int leds[] = {2, 3, 4};
int buttons[] = {5, 6, 7};

int sequence[100];
int level = 1;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(buttons[i], INPUT);
  }

  randomSeed(analogRead(A0));

  Serial.begin(9600);
  Serial.println("READY?");
}

void loop() {
  for (int i = 0; i < level; i++) {
    sequence[i] = random(0, 3);
  }

  showSequence(level);

  if (getPlayerInput(level)) {
    Serial.print("NEXT LEVEL! ");
    Serial.println(level);
    level++;
    delay(1000);
  } else {
    gameOver();
  }
}

void showSequence(int len) {
  for (int i = 0; i < len; i++) {
    int led = sequence[i];
    digitalWrite(leds[led], HIGH);
    delay(500);
    digitalWrite(leds[led], LOW);
    delay(250);
  }
}

bool getPlayerInput(int len) {
  for (int i = 0; i < len; i++) {
    int pressed = waitForButton();
    if (pressed != sequence[i]) {
      return false;
    }
  }
  return true;
}

int waitForButton() {
  while (true) {
    for (int i = 0; i < 3; i++) {
      if (digitalRead(buttons[i]) == HIGH) {
        while (digitalRead(buttons[i]) == HIGH);
        delay(100);
        return i;
      }
    }
  }
}

void gameOver() {
  Serial.println("GAME OVER");
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
  level = 1;
  delay(1000);
}