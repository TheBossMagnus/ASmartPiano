void impara(Nota canzone[], int lungh) {
    delay(300);
    int i = 0;
    while (true) {
        if (digitalRead(BUTTON_PIN_RESET) == HIGH){
            lcd.clear();
            return;
        }
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

        int buttonStateDo = digitalRead(BUTTON_PIN_DO);
        int buttonStateRe = digitalRead(BUTTON_PIN_RE);
        int buttonStateMi = digitalRead(BUTTON_PIN_MI);
        int buttonStateFa = digitalRead(BUTTON_PIN_FA);
        int buttonStateSol = digitalRead(BUTTON_PIN_SOL);
        int buttonStateLa = digitalRead(BUTTON_PIN_LA);
        int buttonStateSi = digitalRead(BUTTON_PIN_SI);
        int buttonStateDoa = digitalRead(BUTTON_PIN_DOA);

        if (buttonStateDo == HIGH) {
            if (canzone[i].frequenza == 262) {
                tone(BUZZER_PIN, 262, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (buttonStateRe == HIGH) {
            if (canzone[i].frequenza == 294) {
                tone(BUZZER_PIN, 294, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (buttonStateMi == HIGH) {
            if (canzone[i].frequenza == 330) {
                tone(BUZZER_PIN, 330, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (buttonStateFa == HIGH) {
            if (canzone[i].frequenza == 349) {
                tone(BUZZER_PIN, 349, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (buttonStateSol == HIGH) {
            if (canzone[i].frequenza == 392) {
                tone(BUZZER_PIN, 392, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (buttonStateLa == HIGH) {
            if (canzone[i].frequenza == 440) {
                tone(BUZZER_PIN, 440, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        } else if (buttonStateSi == HIGH) {
            if (canzone[i].frequenza == 494) {
                tone(BUZZER_PIN, 494, canzone[i].durata*10);
                delay(canzone[i].durata*10 + canzone[i].ritardo*10 + 25);
                i++;
            } else {
                errore(i);
            }
        }
        else if (buttonStateDoa == HIGH) {
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
    tone(BUZZER_PIN, 100, 100);
    delay(500);
}