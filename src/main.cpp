#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <DNSServer.h>
#include "main.h"
#include "led.h"
#include "webserver.h"

unsigned long led_last_time = 0;
unsigned long speaker_last_time = 0;
double speaker_freq = 78;
unsigned long speaker_duration = 300;
unsigned long speaker_period = 900;
DNSServer dnsServer;
AsyncWebServer server(80);

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  print_init_info();
  Serial.print("\nStarting WiFi in Acess Point mode...");
  WiFi.softAP(wifi_ssid, wifi_password, wifi_channel, 0, 1);
  Serial.print("\nIP Address: ");
  Serial.print(WiFi.softAPIP());
  Serial.print("\nStarting DNS Server...");
  dnsServer.start(53, "*", WiFi.softAPIP());
  Serial.print("\nStarting Web Server...");
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);
  server.begin();
}

void loop() {
  dnsServer.processNextRequest();

  /* Speaker looping */
  if (millis() - speaker_last_time > speaker_period) {
    speaker_last_time = millis();
    tone(SPEAKER_PIN, speaker_freq, speaker_duration);
    noTone(SPEAKER_PIN);
  }

  /* Led looping */
  if (millis() - led_last_time >= LED_INTERVAL) {
    led_last_time = millis();
    led_blink();
  }
}