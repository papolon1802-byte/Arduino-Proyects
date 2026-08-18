//Le indicamos al programa que recursos estamos usando
#include <ESP32Servo.h>
//Indicando la variable
Servo servo1;
int targetAngle = 90;

void setup() {
  // De donde salen la informacion central
  servo1.attach(13);
  servo1.write(targetAngle);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  // Primer boton movimiento 170 grados y asi con los otros botones
  if (digitalRead(18) == LOW) {
    servo1.write(170);
    targetAngle = 170;
  }
  else if (digitalRead(19) == LOW) {
    servo1.write(90);
    targetAngle = 90;
  }
  else if (digitalRead(4) == LOW) {
    servo1.write(10);
    targetAngle = 10;
  }
  servo1.write(targetAngle);
}