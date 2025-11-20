#define BUTTON_PIN_1 3
#define BUTTON_PIN_2 5
#define BUTTON_PIN_3 6
#define BUZZER_PIN 9

// Button states
int buttonState1 = 0;
int lastButtonState1 = 0;

int buttonState2 = 0;
int lastButtonState2 = 0;

int buttonState3 = 0;
int lastButtonState3 = 0;

void setup() {
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(BUTTON_PIN_3, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // C - 262 Hz
  buttonState1 = digitalRead(BUTTON_PIN_1);
  if (buttonState1 == HIGH && lastButtonState1 == LOW) {
    tone(BUZZER_PIN, 262, 500);
    delay(10);
  }
  lastButtonState1 = buttonState1;
  
  // E - 330 Hz
  buttonState2 = digitalRead(BUTTON_PIN_2);
  if (buttonState2 == HIGH && lastButtonState2 == LOW) {
    tone(BUZZER_PIN, 330, 500);
    delay(10);
  }
  lastButtonState2 = buttonState2;
  
  // G - 392 Hz
  buttonState3 = digitalRead(BUTTON_PIN_3);
  if (buttonState3 == HIGH && lastButtonState3 == LOW) {
    tone(BUZZER_PIN, 392, 500);
    delay(10);
  }
  lastButtonState3 = buttonState3;
}