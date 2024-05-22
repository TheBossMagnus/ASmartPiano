void menu(){
        lcd.clear();
    lcd.print(F("1-Ascolta"));
    lcd.setCursor(0,1);
    lcd.print(F("2-Impara 3-Suona"));

    while(true){
        if(digitalRead(BUTTON_PIN_DO) == HIGH){
            lcd.clear();
            lcd.print(F("Premi numero canzone"));
            delay(300);
            while (true)
            {
            if (digitalRead(BUTTON_PIN_RESET) == HIGH){
                lcd.clear();
                return;
            }
            
            if (digitalRead(BUTTON_PIN_DO) == HIGH){
                lcd.clear();
                ascolta(innoAllaGioia, sizeof(innoAllaGioia) / sizeof(Nota));
                return;
            }
            if (digitalRead(BUTTON_PIN_RE) == HIGH){
                lcd.clear();
                ascolta(TTLS, sizeof(TTLS) / sizeof(Nota));
                return;
            }
            if (digitalRead(BUTTON_PIN_MI) == HIGH){
                lcd.clear();
                ascolta(FraMartino, sizeof(FraMartino) / sizeof(Nota));
                return;
            }
            }
        }
        if(digitalRead(BUTTON_PIN_RE) == HIGH){
            lcd.clear();
            lcd.print(F("Premi numero canzone"));
            delay(300);
            while (true)
            {
            if (digitalRead(BUTTON_PIN_RESET) == HIGH){
                lcd.clear();
                return;
            }
            
            if (digitalRead(BUTTON_PIN_DO) == HIGH){
                lcd.clear();
                impara(innoAllaGioia, sizeof(innoAllaGioia) / sizeof(Nota));
                return;
            }
            if (digitalRead(BUTTON_PIN_RE) == HIGH){
                lcd.clear();
                impara(TTLS, sizeof(TTLS) / sizeof(Nota));
                return;
            }
            if (digitalRead(BUTTON_PIN_MI) == HIGH){
                lcd.clear();
                impara(FraMartino, sizeof(FraMartino) / sizeof(Nota));
                return;
            }
            }
        } else if(digitalRead(BUTTON_PIN_MI) == HIGH){
            suona();
            return;
        }
    }
}