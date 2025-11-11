#include "mqtt.h"
#include "Classes.h"
#include <string.h>

// nota: modificar esta função para operar com um array de ponteiros para sensores em vez de apenas um sensor.!
string formatar_sensores_mqtt(sensor* Sensor_atual, char separator_char){
    string mensagem_output = "";
    mensagem_output += Sensor_atual->tipo_sensor + separator_char;
    mensagem_output += to_string(Sensor_atual->valor) + separator_char;
    mensagem_output += Sensor_atual->unidade_medida + separator_char;
    mensagem_output += Sensor_atual->flags + separator_char;
    return mensagem_output;
}
