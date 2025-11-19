// code prototype for the working piano with only one sensor and buzzer


#include <Adafruit_NeoPixel.h>

int ledRing = 6;
int lightPin = 3;
int ledPin = 5;
int buzzerPin = 9;
int lightValue = 0;

#define LED_COUNT 12
#define BRIGHTNESS 20
Adafruit_NeoPixel ring(LED_COUNT, ledRing, NEO_GRB + NEO_KHZ800);


uint32_t red = ring.Color(255, 0, 0);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  ring.begin();
  ring.show();
  ring.setBrightness(BRIGHTNESS); 
}

void loop() {

  //*
  // put your main code here, to run repeatedly:
  lightValue = digitalRead(lightPin);
  //Serial.println("lightValue");
  ring.clear();
  if (lightValue == 1) {
    tone(buzzerPin, 262, 500);
    digitalWrite(ledPin, 1);
    ring.fill(red,0,LED_COUNT);   
    delay(50);
  }else{
    noTone(buzzerPin);
    digitalWrite(ledPin, 0);
  }
  ring.show();

  //*/

}