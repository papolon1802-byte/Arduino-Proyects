int waterPeque = 0;
int waterGrande = 0;
int waterGrande2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(32, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(26, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  waterPeque = analogRead(34);
  waterGrande = analogRead(35); 
  waterGrande2 = analogRead(32);

  Serial.print("P:"); Serial.print(waterPeque);
  Serial.print(" G:"); Serial.print(waterGrande);
  Serial.print(" G2:"); Serial.println(waterGrande2);
  
  delay(1000);
  analogRead(32);
  analogRead(35);
  analogRead(34);
  delay(1000);
  if (waterPeque >= 1040 && waterGrande >= 1040 && waterGrande2 >= 1040){
  delay(2000);
  digitalWrite(26, HIGH);
    while (waterPeque > 325 && waterGrande > 325 && waterGrande2 > 340 && waterPeque > 1 && waterGrande > 1 && waterGrande2 > 1){
        Serial.print("P:"); Serial.print(waterPeque);
      Serial.print(" G:"); Serial.print(waterGrande);
      Serial.print(" G2:"); Serial.println(waterGrande2);
      Serial.flush();  
      esp_sleep_enable_timer_wakeup(5000000ULL);
      esp_light_sleep_start();
      waterPeque = analogRead(34);
      waterGrande = analogRead(35); 
      waterGrande2 = analogRead(32);
    }
    digitalWrite(26, LOW);
    esp_sleep_enable_timer_wakeup(432000000000ULL); 
    esp_deep_sleep_start(); 
  }
}
