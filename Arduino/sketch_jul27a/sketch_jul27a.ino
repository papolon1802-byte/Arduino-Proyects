//Le indicamos al programa que recursos estamos usando
#include <ESP32Servo.h>
//Indicando la variable
Servo servo1;
int targetAngle = 90;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(13);
  servo1.write(targetAngle);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(170);
  targetAngle = 170;
  delay(2000);
  servo1.write(90);
  targetAngle = 90;
  delay(2000);
  servo1.write(10);
  targetAngle = 10;
  delay(2000);
}
