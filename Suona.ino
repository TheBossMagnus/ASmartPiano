void suona() {
  while (digitalRead(BUTTON_PIN_MI)==HIGH){ //il mi per selezionare suona non deve essere una nota
  }
  
  while (true) {
    if (digitalRead(BUTTON_PIN_RESET) == HIGH) {
      lcd.clear();
      return;
    }

    int frequency = 0;
    String note = "";

    if (digitalRead(BUTTON_PIN_DO) == HIGH) {
      note = "DO";
      frequency = 262;
    } else if (digitalRead(BUTTON_PIN_RE) == HIGH) {
      note = "RE";
      frequency = 294;
    } else if (digitalRead(BUTTON_PIN_MI) == HIGH) {
      note = "MI";
      frequency = 330;
    } else if (digitalRead(BUTTON_PIN_FA) == HIGH) {
      note = "FA";
      frequency = 349;
    } else if (digitalRead(BUTTON_PIN_SOL) == HIGH) {
      note = "SOL";
      frequency = 392;
    } else if (digitalRead(BUTTON_PIN_LA) == HIGH) {
      note = "LA";
      frequency = 440;
    } else if (digitalRead(BUTTON_PIN_SI) == HIGH) {
      note = "SI";
      frequency = 494;
    } else if (digitalRead(BUTTON_PIN_DOA) == HIGH) {
      note = "DO+";
      frequency = 523;
    }

    if (frequency > 0) {
      lcd.clear();
      lcd.print(note);
      tone(BUZZER_PIN, frequency, 100);
    } else {
      noTone(BUZZER_PIN);
    }
  }
}