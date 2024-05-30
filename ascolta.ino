void ascolta(Nota canzone[]) {
    delay(300);
    short i = 0;
    const uint8_t RITARDO_NOTA = 25;

    while (digitalRead(PIN_PULSANTE_RESET) != HIGH) {
        if (digitalRead(PIN_PULSANTE_DOA)) { // Ricomincia
            while(digitalRead(PIN_PULSANTE_DOA) == HIGH) {}
            delay(666);
            i = 0;
        }

        if (digitalRead(PIN_PULSANTE_SI)) { // Pausa
            while (digitalRead(PIN_PULSANTE_SI) == HIGH) {}  // Aspetta che il pulsante venga rilasciato e ripremuto
            while (digitalRead(PIN_PULSANTE_SI) == LOW) {}
            while (digitalRead(PIN_PULSANTE_SI) == HIGH) {}
        }

        if(strcmp(canzone[i].nome,"END")==0) { // Fine canzone
            return;
        }

        lcd.setCursor(0, 0);    //stampo la nota e pulisci la riga
        lcd.print(canzone[i].nome);
        lcd.print(" ");

        tone(PIN_BUZZER, canzone[i].frequenza, canzone[i].durata*10);
        delay(canzone[i].ritardo*10 + canzone[i].durata*10 + RITARDO_NOTA);
        i++;
    }
    return;
}