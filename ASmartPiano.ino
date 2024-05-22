#include "canzoni.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const uint8_t BUZZER_PIN = 5;
const uint8_t BUTTON_PIN_DO = 7;
const uint8_t BUTTON_PIN_RE = 8;
const uint8_t BUTTON_PIN_MI = 9;
const uint8_t BUTTON_PIN_FA = 10;
const uint8_t BUTTON_PIN_SOL = 11;
const uint8_t BUTTON_PIN_LA = 12;
const uint8_t BUTTON_PIN_SI = 13;
const uint8_t BUTTON_PIN_RESET = 2;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(BUTTON_PIN_DO, INPUT_PULLUP);  
    pinMode(BUTTON_PIN_RE, INPUT_PULLUP);
    pinMode(BUTTON_PIN_MI, INPUT_PULLUP);
    pinMode(BUTTON_PIN_FA, INPUT_PULLUP); 
    pinMode(BUTTON_PIN_SOL, INPUT_PULLUP); 
    pinMode(BUTTON_PIN_LA, INPUT_PULLUP); 
    pinMode(BUTTON_PIN_SI, INPUT_PULLUP); 
    pinMode(BUZZER_PIN, OUTPUT); 

    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
    lcd.init();
    lcd.backlight();
}

void loop() {
    menu();
}