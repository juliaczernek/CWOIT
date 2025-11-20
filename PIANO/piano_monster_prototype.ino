#define BUTTON_PIN_1 5
#define BUTTON_PIN_2 6
#define BUTTON_PIN_3 9
#define BUTTON_PIN_4 10
#define BUTTON_PIN_5 11
#define BUTTON_PIN_6 12
#define BUZZER_PIN 3

int buttonState1 = 0;
int lastButtonState1 = 0;

int buttonState2 = 0;
int lastButtonState2 = 0;

int buttonState3 = 0;
int lastButtonState3 = 0;

int buttonState4 = 0;
int lastButtonState4 = 0;

int buttonState5 = 0;
int lastButtonState5 = 0;

int buttonState6 = 0;
int lastButtonState6 = 0;


void setup() {
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(BUTTON_PIN_3, INPUT);
  pinMode(BUTTON_PIN_4, INPUT);
  pinMode(BUTTON_PIN_5, INPUT);
  pinMode(BUTTON_PIN_6, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // C - 262 Hz
  buttonState1 = digitalRead(BUTTON_PIN_1);
  if (buttonState1 == HIGH && lastButtonState1 == LOW) {
    tone(BUZZER_PIN, 262, 500);
    delay(50);
  }
  lastButtonState1 = buttonState1;
  
  // D - 294 Hz
  buttonState2 = digitalRead(BUTTON_PIN_2);
  if (buttonState2 == HIGH && lastButtonState2 == LOW) {
    tone(BUZZER_PIN, 294, 500);
    delay(50);
  }
  lastButtonState2 = buttonState2;
  
  // E - 330 Hz
  buttonState3 = digitalRead(BUTTON_PIN_3);
  if (buttonState3 == HIGH && lastButtonState3 == LOW) {
    tone(BUZZER_PIN, 330, 500);
    delay(50);
  }
  lastButtonState3 = buttonState3;


  // F - 350Hz
  buttonState4 = digitalRead(BUTTON_PIN_4);
  if (buttonState4 == HIGH && lastButtonState4 == LOW) {
    tone(BUZZER_PIN, 350, 500);
    delay(10);
  }
  lastButtonState4 = buttonState4;


  // G - 392Hz
  buttonState5 = digitalRead(BUTTON_PIN_5);
  if (buttonState5 == HIGH && lastButtonState5 == LOW) {
    tone(BUZZER_PIN, 392, 500);
    delay(10);
  }
  lastButtonState5 = buttonState5;


  // B - 494
  buttonState6 = digitalRead(BUTTON_PIN_6);
  if (buttonState6 == HIGH && lastButtonState6 == LOW) {
    tone(BUZZER_PIN, 440, 500);
    delay(10);
  }
  lastButtonState6 = buttonState6;
}