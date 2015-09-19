// Copyright Nat Weerawan 2015-2016
// MIT License

#define MQTT_DEBUG_MODE
#define WIFI_DEBUG_MODE

#include <WiFiConnector.h>
#include <MqttConnector.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

#define ON LOW
#define OFF HIGH

#define RELAY1 4
#define RELAY2 5

MqttConnector *mqtt;
WiFiConnector *wifi;

/* MQTT INFO */
#define MQTT_HOST        "rabbit.cmmc.ninja"
#define MQTT_PORT        1883
#define PUBLISH_EVERY    2 *1000 // every 15 seconds

/* comment ทิ้งถ้าไม่ส่ username/password */
#define MQTT_USERNAME    "nat:nat" 
#define MQTT_PASSWORD    "freedom"

/* SENSOR INFO */
#define DEVICE_NAME "RELAY-001"
#define AUTHOR      "Nat Weerawan"
#define BOARD       "dw.espmini"
#define PROJECT     "test"
#define SENSOR      "-"

/* WIFI INFO */
#define SSID        "NAT.WRTNODE"
#define PASSPHARSE  "devicenetwork"

#include "init_wifi.h"
#include "_publish.h"
#include "_receive.h"
#include "init_mqtt.h"

void init_hardware()
{
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println("BEGIN");
}

void setup()
{
  init_hardware();
  init_wifi();
  init_mqtt();
}

void loop()
{
  mqtt->loop(wifi);
}
