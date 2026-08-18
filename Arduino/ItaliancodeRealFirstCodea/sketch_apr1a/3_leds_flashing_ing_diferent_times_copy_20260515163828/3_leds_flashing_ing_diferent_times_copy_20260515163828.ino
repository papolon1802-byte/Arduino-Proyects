int boton = 0;
int state = 0;
int lastButton = 0;
unsigned long lasTime = 0;
int ledState = LOW;
int interval = 300;
int blinkcount = 0;
int currentLED = 0;

void setup() {
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT_PULLUP);
}

void loop() {

  // 1. Read button
  boton = digitalRead(10);

  // 2. Detect press (LOW → HIGH)
  if (boton == LOW && lastButton == HIGH) {
    state = !state;
    currentLED = 1; 
  }

  // 4. Use state
  if (state == 1) {
    

    if (currentLED == 1){
      if (blinkcount < 20) {
        if(millis() - lasTime >= interval) {
          ledState = !ledState;
          digitalWrite(8, ledState);
          lasTime = millis();
          blinkcount++;
          if(blinkcount >= 20){
            currentLED++;
            blinkcount = 0;
            digitalWrite(8,LOW);
        }  
        }
      }
    }
    else if(currentLED == 2){
      if (blinkcount < 20) {
        if(millis() - lasTime >= interval) {
          ledState = !ledState;
          digitalWrite(7, ledState);
          lasTime = millis();
          blinkcount++;
          if(blinkcount >= 20){
            currentLED++;
            blinkcount = 0;
            digitalWrite(7,LOW);
            ledState = LOW;
        }}
      }
    }
    else if (currentLED == 3) {
     if (blinkcount < 20) {
      if(millis() - lasTime >= interval) {
        ledState = !ledState;
        digitalWrite(9, ledState);
        lasTime = millis();
        blinkcount++;
        if (blinkcount >= 20){
          currentLED = 1;
          blinkcount = 0;  
          digitalWrite(9,LOW);  
      }}
     }
   }
  }
  else if(state == 0) {
    currentLED = 0;
    blinkcount = 0;
    ledState = LOW;
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
  }

  // 5. Save last button state
  lastButton = boton;
}