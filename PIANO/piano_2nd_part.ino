#include <Adafruit_NeoPixel.h>
#include <multiBuzzer.h>

int ledStrip =11;

int lightPin1 = 4;
int lightPin2 = 5;
int lightPin3 = 3;

int buzzerPin1 = 10;
int buzzerPin2 = 9;
int buzzerPin3 = 8;

int lightValue1 = 0;
int lightValue2 = 0;
int lightValue3 = 0;



#define LED_COUNT 19
#define BRIGHTNESS 20

Adafruit_NeoPixel strip(LED_COUNT, ledStrip, NEO_GRB + NEO_KHZ800);
MultiBuzzer buzzerManager;

const uint8_t buzzerPins[3] = {10, 9, 8};

const uint16_t buzzerFreqs[3] = {
  350, // for buzzer 1
  392,  // for buzzer 2
  440

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
    strip.fill(red, 0, 5);   
  } else {
    buzzerManager.stop(0);
  }
  

  if (lightValue2 == 1) {
    buzzerManager.setFrequency(1, buzzerFreqs[1]);
    strip.fill(blue, 5, 5);
  } else {
    buzzerManager.stop(1);
  }

  if (lightValue3 == 1) {
    buzzerManager.setFrequency(2, buzzerFreqs[2]);
    strip.fill(green, 10, 5);
  } else {
    buzzerManager.stop(2);
  }
  
  strip.show();
  delay(50);
}