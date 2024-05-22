void ascolta(Nota canzone[], int lungh) {
    delay(300);
    int i = 0;
    const uint8_t DELAY_NOTA = 25;
    while (true)
     {
        if (digitalRead(BUTTON_PIN_RESET) == HIGH){
            lcd.clear();
            return;
        }
        if (digitalRead(BUTTON_PIN_SI)){ //ricomincia
            while(digitalRead(BUTTON_PIN_SI) == HIGH){
            }
            delay(666);
            i = 0;
        }
        if (digitalRead(BUTTON_PIN_LA)) { // If the button is pressed
            while (digitalRead(BUTTON_PIN_LA) == HIGH) {
            }

            while (digitalRead(BUTTON_PIN_LA) == LOW) {
            }
        
            while (digitalRead(BUTTON_PIN_LA) == HIGH) {
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