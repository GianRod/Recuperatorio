#ifndef INPUT_H_
#define INPUT_H_

#include "nexo.h"

int verificarRespuesta(char mensaje[]);
int pedirEnteroAcotado(int* numero, char mensaje[], int min, int max);
int pedirEntero(int* numero, char mensaje[]);
int pedirCadena(char array[], char mensaje[], int tam);
int ordenarCadena(char array[], int tam);

#endif /* INPUT_H_ */
