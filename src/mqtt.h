// mqtt.h
// Generic header for a rain sensor (sensor de chuva).
// Minimal, portable interface suitable for ESP32/Arduino projects.
#ifndef MQTT_H
#define MQTT_H

#include <Arduino.h>

char* formatar_sensores_mqtt(char* nome_sensor, int val_sensor, int flag_sensor, char* Unidades , char separator_char);
// formata numa string 
// nome_sensor: nome do sensor (ex: "sensor_chuva")
// val_sensor: valor do sensor (ex: 23) 
// Unidades: unidades do sensor (ex: "mm/min")
// flag_sensor: flag do sensor (ex: 1 - válido, 0 - inválido)
// separator_char: caractere separador entre mensagens (ex: '#')

#endif

