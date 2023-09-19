#pragma once
#include <Arduino.h>
#include "main.h"

void led_blink() {
    if (digitalRead(LED_PIN) == HIGH) {
        digitalWrite(LED_PIN, LOW);
    } else {
        digitalWrite(LED_PIN, HIGH);
    }
}