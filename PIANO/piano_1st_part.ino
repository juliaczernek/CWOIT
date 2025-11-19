#include <Adafruit_NeoPixel.h>
#include <multiBuzzer.h>

int ledStrip = 3;

int lightPin1 = 11;
int lightPin2 = 10;
int lightPin3 = 12;

int buzzerPin1 = 9;
int buzzerPin2 = 5;
int buzzerPin3 = 6;

int lightValue1 = 0;
int lightValue2 = 0;
int lightValue3 = 0;



#define LED_COUNT 33
#define BRIGHTNESS 20

Adafruit_NeoPixel strip(LED_COUNT, ledStrip, NEO_GRB + NEO_KHZ800);
MultiBuzzer buzzerManager;

const uint8_t buzzerPins[3] = {9, 5, 6};

const uint16_t buzzerFreqs[3] = {
  262, // for buzzer 1
  440,  // for buzzer 2
  330

};

uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);

void setup() {
  Serial.begin(9600);
  pinMode(lightPin1, INPUT);
  pinMode(lightPin2, INPUT);
  pinMode(lightPin3, INPUT);
  
  buzzerManager.begin(buzzerPins, 3, 20000UL);
  
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS); 
}

void loop() {

  lightValue1 = digitalRead(lightPin1);
  lightValue2 = digitalRead(lightPin2);
  lightValue3 = digitalRead(lightPin3);
  
  Serial.print("lightValue1: ");
  Serial.print(lightValue1);
  Serial.print(" lightValue2: ");
  Serial.println(lightValue2);
  Serial.print(" lightValue3: ");
  Serial.println(lightValue3);
  
  strip.clear();
  
  if (lightValue1 == 1) {
    buzzerManager.setFrequency(0, buzzerFreqs[0]);
    strip.fill(red, 0, 10);   
  } else {
    buzzerManager.stop(0);
  }
  

  if (lightValue2 == 1) {
    buzzerManager.setFrequency(1, buzzerFreqs[1]);
    strip.fill(blue, 11, 10);
  } else {
    buzzerManager.stop(1);
  }

  if (lightValue3 == 1) {
    buzzerManager.setFrequency(2, buzzerFreqs[2]);
    strip.fill(green, 22, 10);
  } else {
    buzzerManager.stop(2);
  }
  
  strip.show();
  delay(50);
}