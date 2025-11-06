// sensor_chuva.h
// Generic header for a rain sensor (sensor de chuva).
// Minimal, portable interface suitable for ESP32/Arduino projects.
#ifndef SENSOR_CHUVA_H
#define SENSOR_CHUVA_H

#include <Arduino.h>

int ler_sensor_chuva(int pin, int tempo_amostragem, int mm_por_pulso); 
// faz amostragem do sensor de chuva no pino 'pin' por 'tempo_amostragem' minutos
// retorna a média das leituras em mm/min
// pin: pino digital conectado ao sensor de chuva
// tempo_amostragem: tempo em minutos para fazer a amostragem






#endif

