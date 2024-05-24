void suona() {
  lcd.clear();
  lcd.print("Suona liberamente!");
  String nota_prec = "";


  while (digitalRead(BUTTON_PIN_MI)==HIGH){ //il mi per selezionare suona non deve essere una nota
  }
  
  while (digitalRead(BUTTON_PIN_RESET) != HIGH) {

    int frequenza = 0;
    String nota = "";

    if (digitalRead(BUTTON_PIN_DO) == HIGH) {
      nota = "DO";
      frequenza = 262;
    } else if (digitalRead(BUTTON_PIN_RE) == HIGH) {
      nota = "RE";
      frequenza = 294;
    } else if (digitalRead(BUTTON_PIN_MI) == HIGH) {
      nota = "MI";
      frequenza = 330;
    } else if (digitalRead(BUTTON_PIN_FA) == HIGH) {
      nota = "FA";
      frequenza = 349;
    } else if (digitalRead(BUTTON_PIN_SOL) == HIGH) {
      nota = "SOL";
      frequenza = 392;
    } else if (digitalRead(BUTTON_PIN_LA) == HIGH) {
      nota = "LA";
      frequenza = 440;
    } else if (digitalRead(BUTTON_PIN_SI) == HIGH) {
      nota = "SI";
      frequenza = 494;
    } else if (digitalRead(BUTTON_PIN_DOA) == HIGH) {
      nota = "DO+";
      frequenza = 523;
    }

    if (frequenza > 0) {
      tone(BUZZER_PIN, frequenza, 100);
      if (nota_prec != nota) {
        lcd.clear();
        lcd.print(nota);
        nota_prec = nota;
      }
    } else {
      noTone(BUZZER_PIN);
    }
  }
}