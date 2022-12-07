#ifndef NEXO_H_
#define NEXO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Fecha.h"
#include "Tipo.h"
#include "Vehiculo.h"
#include "HojaServicio.h"
#include "input.h"

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


int NEXO_darAltaHojas(eVehiculo listaVehiculos[], eHojaServicio listaHojas[],int tamVehiculos, int tamHojas);
eHojaServicio NEXO_cargarDatosHoja(eVehiculo vehiculo);
void NEXO_mostrarVehiculosTipo(eVehiculo listaVehiculos[], eTipo listaTipos[],int tamVehiculos, int tamTipos);
void NEXO_mostrarImporteTotalUnVehiculo(eVehiculo listaVehiculos[], eHojaServicio listaHojas[],int tamVehiculos, int tamHojas);
void NEXO_mostrarImporteTotalFecha(eVehiculo listaVehiculos[], eHojaServicio listaHojas[], eTipo listaTipos[], int tamVehiculos, int tamHojas , int tamTipos);
int NEXO_modificarDescripcionVehiculo(eVehiculo listaVehiculos[], eHojaServicio listaHojas[],int tamVehiculos, int tamHojas);

#endif /* NEXO_H_ */
