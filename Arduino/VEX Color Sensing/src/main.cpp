#include <Arduino.h>
#include "Adafruit_TCS34725.h"


// ------- COLOR SENSOR STUFF --------

int redPort = D2;
int bluePort = D3;

int colorDiff = 0;

float ambientColor[3];
float r, g, b;

#define COLOR_MARGIN 30

void initializeColorSensor(int redPort, int bluePort);
int calibrateColorSensor();
void readColor();
void printColorSensorTelemetry();
void flashSeenColor();
bool colorSeesRed();
bool colorSeesBlue();

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// ------- END COLOR SENSOR STUFF --------

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  
  initializeColorSensor(redPort, bluePort);
}


void loop() {
  // put your main code here, to run repeatedly:

  readColor();
  printColorSensorTelemetry();
  flashSeenColor();

  delay(10);

}


/*
* Initializes the FLORA TCS34725 color sensor. A4 and A5 MUST be used for the color sensor I/O
*/
void initializeColorSensor(int redOutputPort, int blueOutputPort) {
  
  pinMode(redOutputPort, OUTPUT);
  pinMode(blueOutputPort, OUTPUT);
  
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");

    pinMode(13, OUTPUT);
    while (1) {
      // panic
      digitalWrite(LED_BUILTIN, HIGH);
      delay(60);
      digitalWrite(LED_BUILTIN, LOW);
      delay(60);
    }
  }

  Serial.print("R:\t"); Serial.print(int(r)); 
  Serial.print("\tG:\t"); Serial.print(int(g)); 
  Serial.print("\tB:\t"); Serial.print(int(b));

  colorDiff = calibrateColorSensor();
}

void printColorSensorTelemetry() {
  Serial.print("R:\t"); Serial.print(int(r)); 
  Serial.print("\tG:\t"); Serial.print(int(g)); 
  Serial.print("\tB:\t"); Serial.print(int(b));
  Serial.print("\t Sees Red?\t"); Serial.print(colorSeesRed());
  Serial.print("\t Sees Blue?\t"); Serial.println(colorSeesBlue());
}

void flashSeenColor() {
  if (colorSeesRed()) {
    digitalWrite(redPort, HIGH);
    digitalWrite(bluePort, LOW);
  }
  else if (colorSeesBlue()) {
    digitalWrite(bluePort, HIGH);
    digitalWrite(redPort, LOW);
  }
  else {
    digitalWrite(redPort, LOW);
    digitalWrite(bluePort, LOW);
  }
}

int calibrateColorSensor() {
  tcs.getRGB(&ambientColor[0], &ambientColor[1], &ambientColor[2]);

  return ambientColor[0] - ambientColor[2];
}

void readColor() {

  tcs.setInterrupt(false);  // turn on LED

  delay(50);  // takes 50ms to read

  tcs.getRGB(&r, &g, &b);

  //tcs.setInterrupt(true);  // turn off LED
}

bool colorSeesRed() {
  return ((r - colorDiff) > (b + COLOR_MARGIN));
}

bool colorSeesBlue() {
  return (b > ((r - colorDiff) + COLOR_MARGIN));
}
