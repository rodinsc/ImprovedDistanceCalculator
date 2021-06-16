#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht11.h>
#include <math.h>

#define DHT11PIN 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
dht11 DHT11;

int triggerpin = 2;
int echopin = 3;

void setup() {
  
 pinMode(triggerpin, OUTPUT);
 pinMode(echopin, INPUT);
 
 lcd.init();
 lcd.backlight();
 
 DHT11.read(DHT11PIN);
 
 Serial.begin(9600);
 
 Serial.print("Temperature calculated on startup: ");
 Serial.println((float)DHT11.temperature);
}

void loop() {
  
  trigger();
  
  int distance = echo();
  
  printDistance(distance);
  
  delay(500);
}

void trigger(){
  digitalWrite(triggerpin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerpin, LOW);
}

int echo(){
  float duration = pulseIn(echopin, HIGH);
  int distance = (duration/2) / getSoundSpeed();
  return distance;
}

void printDistance(int distance){
  lcd.clear();
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("cm");
}

float getSoundSpeed(){
  float meterPerSecond = sqrt((((float)DHT11.temperature)/273) + 1) * 331;
  float centimeterPerSecond = meterPerSecond * 100;
  float centimeterPerMicrosecond = centimeterPerSecond/1000000;
  float returnValue = 1/centimeterPerMicrosecond;
  return returnValue;
}
