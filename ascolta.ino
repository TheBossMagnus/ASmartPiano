void ascolta(Nota canzone[], short lungh) {
    delay(300);
    short i = 0;
    const uint8_t DELAY_NOTA = 25;
    while (digitalRead(BUTTON_PIN_RESET) != HIGH)
     {
        if (digitalRead(BUTTON_PIN_DOA)){ //ricomincia
            while(digitalRead(BUTTON_PIN_DOA) == HIGH){
            }
            delay(666);
            i = 0;
        }
        if (digitalRead(BUTTON_PIN_SI)) { // Pausa
            while (digitalRead(BUTTON_PIN_SI) == HIGH) {
            }

            while (digitalRead(BUTTON_PIN_SI) == LOW) {
            }
        
            while (digitalRead(BUTTON_PIN_SI) == HIGH) {
            }
        }
        if(strcmp(canzone[i].nome,"END")==0){
            return;
        }
        lcd.setCursor(0, 0);
        lcd.print(canzone[i].nome);
        lcd.print(" ");
        
        tone(BUZZER_PIN, canzone[i].frequenza, canzone[i].durata*10);
        delay(canzone[i].ritardo*10+ canzone[i].durata*10  + DELAY_NOTA);
        i++;
    }
    return;
}