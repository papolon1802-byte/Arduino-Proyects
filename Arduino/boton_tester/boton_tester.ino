void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  int valor = digitalRead(4);
  Serial.println(valor);
  delay(200);
}