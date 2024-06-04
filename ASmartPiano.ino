#include "canzoni.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const uint8_t PIN_BUZZER = 5;
const uint8_t PIN_PULSANTE_DO = 6;
const uint8_t PIN_PULSANTE_RE = 7;
const uint8_t PIN_PULSANTE_MI = 8;
const uint8_t PIN_PULSANTE_FA = 9;
const uint8_t PIN_PULSANTE_SOL = 10;
const uint8_t PIN_PULSANTE_LA = 11;
const uint8_t PIN_PULSANTE_SI = 12;
const uint8_t PIN_PULSANTE_DOA = 13;
const uint8_t PIN_PULSANTE_RESET = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(PIN_BUZZER, OUTPUT);
    pinMode(PIN_PULSANTE_DO, INPUT_PULLUP);
    pinMode(PIN_PULSANTE_RE, INPUT_PULLUP);
    pinMode(PIN_PULSANTE_MI, INPUT_PULLUP);
    pinMode(PIN_PULSANTE_FA, INPUT_PULLUP);
    pinMode(PIN_PULSANTE_SOL, INPUT_PULLUP);
    pinMode(PIN_PULSANTE_LA, INPUT_PULLUP);
    pinMode(PIN_PULSANTE_SI, INPUT_PULLUP);
    pinMode(PIN_PULSANTE_DOA, INPUT_PULLUP);

    lcd = LiquidCrystal_I2C(0x3F, 16, 2); //init display
    lcd.init();
    lcd.backlight();
}

void loop() {
    menu();
    lcd.clear();
}
