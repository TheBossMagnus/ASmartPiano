void suona() {
  lcd.clear();
  lcd.print("Suona liberamente!");
  char nota_prec[4];


  while (digitalRead(BUTTON_PIN_MI)==HIGH){ //il mi per selezionare suona non deve essere una nota
  }
  
  while (digitalRead(BUTTON_PIN_RESET) != HIGH) {

    short frequenza = 0;
    char nota[4] = "";

    if (digitalRead(BUTTON_PIN_DO) == HIGH) {
      strcpy(nota, "DO");
      frequenza = 262;
    } else if (digitalRead(BUTTON_PIN_RE) == HIGH) {
      strcpy(nota, "RE");
      frequenza = 294;
    } else if (digitalRead(BUTTON_PIN_MI) == HIGH) {
      strcpy(nota, "MI");
      frequenza = 330;
    } else if (digitalRead(BUTTON_PIN_FA) == HIGH) {
      strcpy(nota, "FA");
      frequenza = 349;
    } else if (digitalRead(BUTTON_PIN_SOL) == HIGH) {
      strcpy(nota, "SOL");
      frequenza = 392;
    } else if (digitalRead(BUTTON_PIN_LA) == HIGH) {
      strcpy(nota, "LA");
      frequenza = 440;
    } else if (digitalRead(BUTTON_PIN_SI) == HIGH) {
      strcpy(nota, "SI");
      frequenza = 494;
    } else if (digitalRead(BUTTON_PIN_DOA) == HIGH) {
      strcpy(nota, "DO+");
      frequenza = 523;
    }

    if (frequenza > 0) {
      tone(BUZZER_PIN, frequenza, 100);
      if (strcmp(nota, nota_prec) != 0){
        lcd.clear();
        lcd.print(nota);
        strcpy(nota_prec, nota);
      }
    } else {
      noTone(BUZZER_PIN);
    }
  }
}