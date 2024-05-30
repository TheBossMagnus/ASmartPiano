void menu() {
    lcd.print(F("1-Ascolta"));
    lcd.setCursor(0,1);
    lcd.print(F("2-Impara 3-Suona"));

    while(digitalRead(PIN_PULSANTE_RESET) != HIGH) {
        if(digitalRead(PIN_PULSANTE_DO) == HIGH) {
            lcd.clear();
            lcd.print(F("Premi numero canzone"));
            delay(300);
            while (digitalRead(PIN_PULSANTE_RESET) != HIGH) {
                if (digitalRead(PIN_PULSANTE_DO) == HIGH) {
                    lcd.clear();
                    ascolta(innoAllaGioia);
                    return;
                }
                if (digitalRead(PIN_PULSANTE_RE) == HIGH) {
                    lcd.clear();
                    ascolta(TTLS);
                    return;
                }
                if (digitalRead(PIN_PULSANTE_MI) == HIGH) {
                    lcd.clear();
                    ascolta(FraMartino);
                    return;
                }
            }
        }
        if(digitalRead(PIN_PULSANTE_RE) == HIGH) {
            lcd.clear();
            lcd.print(F("Premi numero canzone"));
            delay(300);
            while (digitalRead(PIN_PULSANTE_RESET) != HIGH) {
                if (digitalRead(PIN_PULSANTE_DO) == HIGH) {
                    lcd.clear();
                    impara(innoAllaGioia);
                    return;
                }
                if (digitalRead(PIN_PULSANTE_RE) == HIGH) {
                    lcd.clear();
                    impara(TTLS);
                    return;
                }
                if (digitalRead(PIN_PULSANTE_MI) == HIGH) {
                    lcd.clear();
                    impara(FraMartino);
                    return;
                }
            }
        } else if(digitalRead(PIN_PULSANTE_MI) == HIGH) {
            suona();
            return;
        }
    }
}