// codigo principal do projeto
// estrutura basica do código:
// - inclui bibliotecas
// - define variaveis globais
// - configura conexao Wi-Fi e MQTT
// - teste de sensores
// - loop principal publica dados no broker MQTT
// - dormir entre leituras
// Versão 1: mensagem em char* ( texto corrido )

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <iostream>
using namespace std;

// bibliotecas por sensor
#include "mqtt.h"
#include "sensor_chuva.h"
#include "sensor_dir_vento.h"
#include "sensor_vel_vento.h"

// Sensores e variaveis globais
int val_sensor_chuva = 9999;
int sample_sensor_chuva = 2; // tempo de amostragem em minutos

int val_sensor_dir_vento = 9999;
int sample_sensor_dir_vento = 2; // tempo de amostragem em minutos

int val_sensor_vel_vento = 9999;
int sample_sensor_vel_vento = 2; // tempo de amostragem em minutos

// Wi-Fi credentials
const char* ssid = "Sony_jb";
const char* password = "carapau2000";

// MQTT broker details
const char* mqtt_broker = "7ffa7871af3f46a4b95c1c22b38661f2.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_username = "Rede_sensores_IOT";
const char* mqtt_password = "Senha1234";

// definições wifi
WiFiClientSecure espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao broker MQTT...");
    if (client.connect("ESP32Client", mqtt_username, mqtt_password)) {
      Serial.println("conectado");
    } else {
      Serial.print("falha, rc=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  espClient.setInsecure(); // Usar conexão insegura para MQTT sobre TLS
  client.setServer(mqtt_broker, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop(); // 
  
  // leitura de sensores:
  val_sensor_chuva = ler_sensor_chuva(12, sample_sensor_chuva, 0.2794); // pino 12( trocar mais tarde), tempo amostragem em minutos, mm por pulso

  // formata mensagem MQTT



  // enviar pacote inteiro
  


  char* msg= "Teste MQTT do ESP32 ";
  client.publish("testes", msg);
  delay(5000); // Publica a cada 1 segundo
}