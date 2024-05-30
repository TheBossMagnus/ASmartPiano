void impara(Nota canzone[]) {
    delay(300);
    lcd.clear();

    short i = 0;
    while (digitalRead(PIN_PULSANTE_RESET) != HIGH) {
        if(strcmp(canzone[i].nome,"END")==0){ // Fine canzone
            return;
        }

        // Stampa la nota da suonare e le due successive
        lcd.setCursor(0, 0);
        lcd.print(canzone[i].nome);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print("succ: ");
        lcd.print(canzone[i+1].nome);
        lcd.print(", ");
        lcd.print(canzone[i+2].nome);
        lcd.print(" ");

        // Aspetta che il pulsante corrispondente alla nota venga premuto, fai la nota e passa alla successiva
        // Se il pulsante premuto non corrisponde alla nota, fai un errore
        if (digitalRead(PIN_PULSANTE_DO) == HIGH) {
            if (canzone[i].frequenza == 262) {
                tone(PIN_BUZZER, 262, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        } else if (digitalRead(PIN_PULSANTE_RE) == HIGH) {
            if (canzone[i].frequenza == 294) {
                tone(PIN_BUZZER, 294, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        } else if (digitalRead(PIN_PULSANTE_MI) == HIGH) {
            if (canzone[i].frequenza == 330) {
                tone(PIN_BUZZER, 330, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        } else if (digitalRead(PIN_PULSANTE_FA) == HIGH) {
            if (canzone[i].frequenza == 349) {
                tone(PIN_BUZZER, 349, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        } else if (digitalRead(PIN_PULSANTE_SOL) == HIGH) {
            if (canzone[i].frequenza == 392) {
                tone(PIN_BUZZER, 392, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        } else if (digitalRead(PIN_PULSANTE_LA) == HIGH) {
            if (canzone[i].frequenza == 440) {
                tone(PIN_BUZZER, 440, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        } else if (digitalRead(PIN_PULSANTE_SI) == HIGH) {
            if (canzone[i].frequenza == 494) {
                tone(PIN_BUZZER, 494, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        }
        else if (digitalRead(PIN_PULSANTE_DOA) == HIGH) {
            if (canzone[i].frequenza == 523) {
                tone(PIN_BUZZER, 523, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore();
            }
        }
    }
}

void errore() {
    lcd.setCursor(0, 1);
    lcd.print("ERRORE!"); //stampa errore
    lcd.print("        ");  //ripulisce il resto della riga
    tone(PIN_BUZZER, 100, 250); //suono errore
    delay(500);
    lcd.print("        ");  //ripulisce la riga
}