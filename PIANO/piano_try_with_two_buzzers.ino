 #include <Adafruit_NeoPixel.h>

int ledStrip = 3;
int lightPin1 = 11;
int lightPin2 = 10;
int buzzerPin1 = 9;
int buzzerPin2 = 12;

int lightValue1 = 0;
int lightValue2 = 0;


#define LED_COUNT 33
#define BRIGHTNESS 20
Adafruit_NeoPixel strip(LED_COUNT, ledStrip, NEO_GRB + NEO_KHZ800);


uint32_t red = strip.Color(255, 0, 0);
uint32_t green = strip.Color(0, 255, 0);
uint32_t blue = strip.Color(0, 0, 255);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin1, INPUT);
  pinMode(lightPin2, INPUT);
  pinMode(buzzerPin1, OUTPUT);
  pinMode(buzzerPin2, OUTPUT);
  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS); 
}

void loop() {

  //*
  // put your main code here, to run repeatedly:
  lightValue1 = digitalRead(lightPin1);
  lightValue2 = digitalRead(lightPin2);

  Serial.print("lightValue1: ");
  Serial.print(lightValue1);
  Serial.print(" lightValue2: ");
  Serial.println(lightValue2);


  strip.clear();
  if (lightValue1 == 1) {
    tone(buzzerPin1, 262, 500);
    strip.fill(red,0,10);   
    delay(50);
  }else{
    noTone(buzzerPin1);
  }

  if (lightValue2 == 1){
    tone(buzzerPin2, 440, 500);
    strip.fill(blue, 11, 21);
    delay(50);
  }else{
    noTone(buzzerPin2);
  }

  strip.show();
  delay(50);

    
  }


  //*/


