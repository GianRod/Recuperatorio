#ifndef TIPO_H_
#define TIPO_H_

#include "nexo.h"

#define TAM_DESC 30

typedef struct{
	int idTipo;
	char descripcion[TAM_DESC];
}eTipo;

int TIPO_buscarPosicionPorID(eTipo array[], int tam, int id);
void TIPO_mostrarUnTipo(eTipo aux);
void TIPO_mostrarTodoTipo(eTipo listaTipos[], int tam);

#endif /* TIPO_H_ */
