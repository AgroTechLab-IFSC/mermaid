#pragma once
#include <Arduino.h>

#define MAJOR_VERSION 0
#define MINOR_VERSION 1
#define PATCH_VERSION 0
#define SERIAL_BAUDRATE 115200
#define LED_INTERVAL 1000
#define LED_PIN 5
#define SPEAKER_PIN 6

const char* wifi_ssid = "MarmeidDev";
const char* wifi_password = "AgroTechLab";
const int wifi_channel = 11;

void print_init_info() {
    Serial.print("\n=====================================================");
    Serial.print("\n                  Mermaid Device                     ");
    Serial.print("\n                  by AgroTechLab                     ");
    Serial.print("\n        Instituto Federal de Santa Catarina          ");
    Serial.print("\n                   Câmpus Lages                      ");
    Serial.print("\n=====================================================\n");
    Serial.print("\nVersion: ");
    Serial.print(MAJOR_VERSION);
    Serial.print(".");
    Serial.print(MINOR_VERSION);
    Serial.print(".");
    Serial.print(PATCH_VERSION);
}