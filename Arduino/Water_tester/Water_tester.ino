int waterValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {

  waterValue = analogRead(A0);

  delay(500);

  Serial.println(waterValue);
// It dry the dirt
  if (waterValue <= 300) {

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

  }
// it no soo dry and no soo humid
  else if (waterValue >= 301 && waterValue <= 630) {

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

  }
// humid
  else if (waterValue >= 631) {

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);

  }
}