#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_

#include "nexo.h"
#include "fecha.h"

typedef struct{
	int idHoja;
	int vehiculoId;
	char descripcion[30];
	int precioServicio;
	eFecha fecha;
	int isEmpty;
}eHojaServicio;

void HOJA_inicializarlista(eHojaServicio lista[], int tam);
int HOJA_obtenerId(void);
int HOJA_obtenerIndexLibre(eHojaServicio lista[], int tam);
int HOJA_buscarPosicionPorID(eHojaServicio array[], int tam, int id);
void HOJA_mostrarUno(eHojaServicio aux);
void HOJA_mostrarTodos(eHojaServicio lista[], int tam);
void HOJA_mostrarHojasFechaSeleccionada(eHojaServicio lista[], int tam);
int HOJA_modificarPrecioServicio(eHojaServicio lista[], int tam);

#endif /* HOJASERVICIO_H_ */
