#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    97
//#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

String receive_buffer;

int tempR = 0;
int tempG = 0;
int tempB = 255;
int8_t counter;
String tempPrejeto;

int onOff = 1;
int BRIGHTNESS = 100;

//https://randomnerdtutorials.com/guide-for-ws2812b-addressable-rgb-led-strip-with-arduino/


void setRGB() {
  char tempChar[3];
  tempChar[0] = tempPrejeto.charAt(1);
  tempChar[1] = tempPrejeto.charAt(2);
  tempChar[2] = tempPrejeto.charAt(3);
  //tempChar[3] = tempPrejeto.charAt(3);

  tempR = atoi(tempChar);
  Serial.println(tempR);

  tempChar[0] = tempPrejeto.charAt(4);
  tempChar[1] = tempPrejeto.charAt(5);
  tempChar[2] = tempPrejeto.charAt(6);
  //tempChar[3] = tempPrejeto.charAt(7);

  tempG = atoi(tempChar);
  Serial.println(tempG);

  tempChar[0] = tempPrejeto.charAt(7);
  tempChar[1] = tempPrejeto.charAt(8);
  tempChar[2] = tempPrejeto.charAt(9);
  //tempChar[3] = tempPrejeto.charAt(11);

  tempB = atoi(tempChar);
  Serial.println(tempB);
}

void setBright() {
  char tempChar[3];
  tempChar[0] = tempPrejeto.charAt(1);
  tempChar[1] = tempPrejeto.charAt(2);
  tempChar[2] = tempPrejeto.charAt(3);
  //tempChar[3] = tempPrejeto.charAt(3);
      
  BRIGHTNESS = atoi(tempChar);
  FastLED.setBrightness(  BRIGHTNESS );
  Serial.println(BRIGHTNESS);
}

void setOnOff() {
  if(onOff == 1){
    onOff = 0;
    Serial.println("0");
  }
  else if(onOff == 0){
    onOff = 1;
    Serial.println("1");
  }
}

void setup() {
    delay( 3000 ); // power-up safety delay
    Serial.begin(9600);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    //FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  if(Serial.available()>0) {
    tempPrejeto = Serial.readString();

    //Serial.println(Serial.available());

    if(tempPrejeto.charAt(0) == 'R'){
      setRGB();
    }

    else if(tempPrejeto.charAt(0) == 'B'){
      setBright();
    }

    else if(tempPrejeto.charAt(0) == 'O'){
      setOnOff();
    }
  }
    
  if(onOff == 1){
    CRGB tempFarba = CRGB(tempR, tempG, tempB);

    for( int i = 0; i < NUM_LEDS; i++) {
      leds[i] = tempFarba;
    }
    
    FastLED.show();
  }
  else if(onOff == 0){
    FastLED.clear();
    FastLED.show();
  }
}