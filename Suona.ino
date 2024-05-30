void suona() {
    lcd.clear();
    lcd.print("Suona liberamente!");
    char nota_prec[4];

    while (digitalRead(PIN_PULSANTE_MI)==HIGH){} // Aspetta che il pulsante mi usato per selezionare suona venga rilasciato

    while (digitalRead(PIN_PULSANTE_RESET) != HIGH) {
        short frequenza = 0;
        char nota[4] = "";

        if (digitalRead(PIN_PULSANTE_DO) == HIGH) {   // Imposta la nota e la frequenza in base al pulsante premuto
            strcpy(nota, "DO");
            frequenza = 262;
        } else if (digitalRead(PIN_PULSANTE_RE) == HIGH) {
            strcpy(nota, "RE");
            frequenza = 294;
        } else if (digitalRead(PIN_PULSANTE_MI) == HIGH) {
            strcpy(nota, "MI");
            frequenza = 330;
        } else if (digitalRead(PIN_PULSANTE_FA) == HIGH) {
            strcpy(nota, "FA");
            frequenza = 349;
        } else if (digitalRead(PIN_PULSANTE_SOL) == HIGH) {
            strcpy(nota, "SOL");
            frequenza = 392;
        } else if (digitalRead(PIN_PULSANTE_LA) == HIGH) {
            strcpy(nota, "LA");
            frequenza = 440;
        } else if (digitalRead(PIN_PULSANTE_SI) == HIGH) {
            strcpy(nota, "SI");
            frequenza = 494;
        } else if (digitalRead(PIN_PULSANTE_DOA) == HIGH) {
            strcpy(nota, "DO+");
            frequenza = 523;
        }

        if (frequenza > 0) {  // Se è stata premuta una nota
            tone(PIN_BUZZER, frequenza, 100);   // Suona la nota
            // Aggiorna il display solo se la nota è cambiata
            // Questo evita di aggiornare il display ad ogni ciclo, causando sfarfallio
            if (strcmp(nota, nota_prec) != 0){
                lcd.clear();
                lcd.print(nota);
                strcpy(nota_prec, nota);
            }
        } else {  // Nessuna nota premuta
            noTone(PIN_BUZZER);
        }
    }
}