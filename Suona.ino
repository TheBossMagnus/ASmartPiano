void suona() {
  delay(300);

  while (true)
  {
    if (digitalRead(BUTTON_PIN_RESET) == HIGH){
            lcd.clear();
            return;
  }
      uint8_t  buttonStateDo = digitalRead(BUTTON_PIN_DO);
  uint8_t  buttonStateRe = digitalRead(BUTTON_PIN_RE);
  uint8_t  buttonStateMi = digitalRead(BUTTON_PIN_MI);
  uint8_t  buttonStateFa = digitalRead(BUTTON_PIN_FA);
  uint8_t  buttonStateSol = digitalRead(BUTTON_PIN_SOL);
  uint8_t  buttonStateLa = digitalRead(BUTTON_PIN_LA);
  uint8_t  buttonStateSi = digitalRead(BUTTON_PIN_SI);
  uint8_t buttonStateDoa = digitalRead(BUTTON_PIN_DOA);
  if (buttonStateDo == HIGH)
  {
    lcd.clear();
    lcd.print("DO");
    tone(BUZZER_PIN, 262, 100);    
    } else if (buttonStateRe == HIGH) {
      lcd.clear();
      lcd.print("RE");
      tone(BUZZER_PIN, 294, 100);    
    } else if (buttonStateMi == HIGH) {
      lcd.clear();
      lcd.print("MI");
      tone(BUZZER_PIN, 330, 100);    
    } else if (buttonStateFa == HIGH) {
      lcd.clear();
      lcd.print("FA");
      tone(BUZZER_PIN, 349, 100);    
    } else if (buttonStateSol == HIGH) {
      lcd.clear();
      lcd.print("SOL");
      tone(BUZZER_PIN, 392, 100);    
    } else if (buttonStateLa == HIGH) {
      lcd.clear();
      lcd.print("LA");
      tone(BUZZER_PIN, 440, 100);    
    } else if (buttonStateSi == HIGH) {
      lcd.clear();
      lcd.print("SI");
      tone(BUZZER_PIN, 494, 100); 
    } else if (buttonStateDoa == HIGH) {
      lcd.clear();
      lcd.print("DO+");
      tone(BUZZER_PIN, 523, 100);
    }else {
      noTone(BUZZER_PIN);
    }
  }
}
