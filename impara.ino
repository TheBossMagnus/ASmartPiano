void impara(Nota canzone[], int lungh) {
    delay(300);
    lcd.clear();
    
    int i = 0;
    while (digitalRead(BUTTON_PIN_RESET) != HIGH) {
        if(strcmp(canzone[i].nome,"END")==0){
            return;
        }
        lcd.setCursor(0, 0);
        lcd.print(canzone[i].nome);
        lcd.print(" ");
        lcd.setCursor(0, 1);
        lcd.print("succ: ");
        lcd.print(canzone[i+1].nome);
        lcd.print(", ");
        lcd.print(canzone[i+2].nome);
        lcd.print(" ");

        if (digitalRead(BUTTON_PIN_DO) == HIGH) {
            if (canzone[i].frequenza == 262) {
                tone(BUZZER_PIN, 262, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (digitalRead(BUTTON_PIN_RE) == HIGH) {
            if (canzone[i].frequenza == 294) {
                tone(BUZZER_PIN, 294, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (digitalRead(BUTTON_PIN_MI) == HIGH) {
            if (canzone[i].frequenza == 330) {
                tone(BUZZER_PIN, 330, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (digitalRead(BUTTON_PIN_FA) == HIGH) {
            if (canzone[i].frequenza == 349) {
                tone(BUZZER_PIN, 349, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (digitalRead(BUTTON_PIN_SOL) == HIGH) {
            if (canzone[i].frequenza == 392) {
                tone(BUZZER_PIN, 392, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (digitalRead(BUTTON_PIN_LA) == HIGH) {
            if (canzone[i].frequenza == 440) {
                tone(BUZZER_PIN, 440, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (digitalRead(BUTTON_PIN_SI) == HIGH) {
            if (canzone[i].frequenza == 494) {
                tone(BUZZER_PIN, 494, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        }
        else if (digitalRead(BUTTON_PIN_DOA) == HIGH) {
            if (canzone[i].frequenza == 523) {
                tone(BUZZER_PIN, 523, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        }
        if (i == lungh) {
            return;
        }
    }
}

void errore(int i) {
    tone(BUZZER_PIN, 100, 250);
    delay(500);
}