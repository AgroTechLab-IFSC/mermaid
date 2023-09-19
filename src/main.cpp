#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "main.h"
#include "led.h"

unsigned long led_last_time = 0;
unsigned long speaker_last_time = 0;
double speaker_freq = 78;
unsigned long speaker_duration = 300;
unsigned long speaker_period = 900;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  print_init_info();
  WiFi.softAP(wifi_ssid, wifi_password, wifi_channel, 0, 1);
}

void loop() {

  /* Led looping */
  if (millis() - led_last_time >= LED_INTERVAL) {
    led_last_time = millis();
    led_blink();
  }

  /* Speaker looping */
  if (millis() - speaker_last_time > speaker_period) {
    speaker_last_time = millis();
    tone(SPEAKER_PIN, speaker_freq, speaker_duration);
    noTone(SPEAKER_PIN);
  }
}