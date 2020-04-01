#ifndef _TIPOS_DEFS_H_
#define _TIPOS_DEFS_H_

/* Definição dos estados de operação */
enum {
  estadoParado,
  estadoOperando
  //estadoPausado,
  //estadoParadaEmergencia
};

//speed in steps per second
//acceleration in steps per second
typedef struct Operacao_t {
  uint8_t estado = 0;
  uint32_t contadorReinicio = 0;
  float currentSpeed = 1500.0;
  float currentAcc = 10000.0;
  float currentRate = 2.0;
  long currentCourse = 350;
  long stepsPerRevFactor = 2;  
};

#endif
