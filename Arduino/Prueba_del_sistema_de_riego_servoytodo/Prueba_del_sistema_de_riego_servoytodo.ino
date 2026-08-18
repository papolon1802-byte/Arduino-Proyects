//Le indicamos al programa que recursos estamos usando
#include <ESP32Servo.h>
//Indicando la variable
Servo servo1;
int targetAngle = 90;
int waterPeque = 0;
int waterGrande = 0;
int waterGrande2 = 0;

void setup() {
  Serial.begin(115200);
  servo1.attach(13);
  servo1.write(targetAngle);
  // pines del sensor de agua
  pinMode(32, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
 // pin del relle/valvula
  pinMode(26, OUTPUT);
}

void loop() {
  analogRead(34);
  delay(50);
  waterPeque = analogRead(34);
  if (waterPeque >= 1040 ) {
    servo1.write(170);
    targetAngle = 170;
    delay(1500);
    digitalWrite(26, HIGH);
    while (waterPeque > 325 && waterPeque > 1){
      Serial.print("P:"); 
      Serial.println(waterPeque);
      Serial.flush();
      esp_sleep_enable_timer_wakeup(5000000ULL);
      esp_light_sleep_start();
      servo1.attach(13);
      waterPeque = analogRead(34);
    }
    digitalWrite(26, LOW);
    Serial.print("After P1 - G:"); Serial.print(waterGrande);
    Serial.print(" G2:"); Serial.println(waterGrande2);
  }
  analogRead(35);
  delay(50);
  waterGrande = analogRead(35); 
  if (waterGrande >= 1040 ) {
    servo1.write(90);
    targetAngle = 90;
    delay(1500);
    digitalWrite(26, HIGH);
    while (waterGrande > 325 && waterGrande > 1){
      Serial.print("G:"); 
      Serial.println(waterGrande);
      Serial.flush();
      esp_sleep_enable_timer_wakeup(5000000ULL);
      esp_light_sleep_start();
      servo1.attach(13); 
      waterGrande = analogRead(35);
    }
    digitalWrite(26, LOW);
    Serial.print("After G - G2:"); Serial.print(waterGrande2);
    Serial.print(" P:"); Serial.println(waterPeque);
  }
  analogRead(32);
  delay(50);
  waterGrande2 = analogRead(32);
  if (waterGrande2 >= 1040 ) {
    servo1.write(10);
    targetAngle = 10;
    delay(1500);
    digitalWrite(26, HIGH);
    while (waterGrande2 > 340 && waterGrande2 > 1){
      Serial.print("G2:"); 
      Serial.println(waterGrande2);
      Serial.flush();  
      esp_sleep_enable_timer_wakeup(5000000ULL);
      esp_light_sleep_start();
      servo1.attach(13); 
      waterGrande2 = analogRead(32);
    }
    digitalWrite(26, LOW);
    Serial.print("After G2 - P:"); Serial.print(waterPeque);
    Serial.print(" G:"); Serial.println(waterGrande);
  }
  if (waterPeque <= 325 && waterGrande <= 325 && waterGrande2 <= 340 && waterPeque > 1 && waterGrande > 1 && waterGrande2 > 1){
    servo1.write(90);
    targetAngle = 90;
    delay(2000);
    esp_sleep_enable_timer_wakeup(432000000000ULL); 
    esp_deep_sleep_start(); 
  }
}
