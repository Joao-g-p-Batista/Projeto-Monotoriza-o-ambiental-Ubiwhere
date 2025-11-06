// sensor_chuva.cpp
// Generic rain sensor helper for ESP32/Arduino (PlatformIO)
// Place this file in src/ and include/use from your main sketch.
//
// Simple, dependency-light class that handles debouncing and optional callback.

#include <Arduino.h>

int ler_sensor_chuva(int pin, int tempo_amostragem, int mm_por_pulso) {
    Serial.println("Lendo sensor de chuva...");
        
    int contador_pulsos=0; // contador de Pulsos
    int timer=0; // em milisegundos
    int pulse_lock=0;
    int val= 1;


    while (timer<tempo_amostragem*60*1000){ // tempo_amostragem em minutos
        // lê o pino do sensor
        val = digitalRead(pin);
        if (val == 0 && pulse_lock == 0) {// verifica se houve mudança de estado do segundo anterior
            contador_pulsos = contador_pulsos + 1;
            pulse_lock = 1;  // bloqueia este pulso para náo repetir a contagem
        }
    
        if (val == HIGH && pulse_lock == 1)// desbloqueia o pulso quando o sinal volta ao estado normal
        {
            pulse_lock = 0;
        }
        
        // aguarda 10 milisegundo antes de nova leitura
        delay(10);
        timer = timer + 10;
    }

    return contador_pulsos * mm_por_pulso / tempo_amostragem; // retorna mm/min

}