#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "main.h"
#include "led.h"

unsigned long led_last_time = 0;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  print_init_info();
  WiFi.softAP(wifi_ssid, wifi_password, wifi_channel, 0, 1);
}

void loop() {
  if (millis() - led_last_time >= LED_INTERVAL) {
    led_last_time = millis();
    led_blink();
  }
}