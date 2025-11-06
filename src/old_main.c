/* #include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

// variaveis partilhadas
int soma = 1;


// Wi-Fi credentials
const char* ssid = "Sony_jb";
const char* password = "carapau2000";

// MQTT broker details
const char* mqtt_broker = "7ffa7871af3f46a4b95c1c22b38661f2.s1.eu.hivemq.cloud";
const int mqtt_port = 8883;
const char* mqtt_username = "ESP32";
const char* mqtt_password = "Senha1234";

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
   Serial.println(" ponto 1");
  setup_wifi();
   Serial.println(" ponto 2");
  espClient.setInsecure(); // Usar conexão insegura para MQTT sobre TLS
   Serial.println(" ponto 3");
  client.setServer(mqtt_broker, mqtt_port);
   Serial.println(" ponto 4");
}

void loop() {
  if (!client.connected()) {
    reconnect();
    int result = 1;
  }
  client.loop();
  Serial.print(" loop: ");
  soma = soma + 1;
  Serial.print(soma);
  Serial.print("\n");
  char msg[10];
  snprintf(msg, 10, "%d", soma);
  client.publish("botao", msg);
  delay(5000); // Publica a cada 1 segundo
} */