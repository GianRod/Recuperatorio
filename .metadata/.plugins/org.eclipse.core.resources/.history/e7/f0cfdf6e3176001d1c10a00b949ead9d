#ifndef VEHICULO_H_
#define VEHICULO_H_

#define TAM_COLOR 10
#define MAX_DESC 30

typedef struct{

	int idVehiculo;
	char descripcion[MAX_DESC];
	int modelo;
	char color[TAM_COLOR];
	int tipoId;
	int isEmpty;
}eVehiculo;

void VEH_inicializarlista(eVehiculo lista[], int tam);
int VEH_buscarPosicionPorID(eVehiculo array[], int tam, int id);
int VEH_obtenerIndexLibre(eVehiculo lista[], int tam);
eVehiculo VEH_pedirDatos(void);
int VEH_darAltaVehiculo(eVehiculo lista[], int tam);
void VEH_mostrarUno(eVehiculo aux);
void VEH_mostrarTodos(eVehiculo lista[], int tam);
int VEH_modificarDescripcionVehiculo(eVehiculo lista[], int tam);
int VEH_darBajaVehiculo(eVehiculo lista[], int tam);
int VEH_mostrarOrdenados(eVehiculo lista[], int tam);

#endif /* VEHICULO_H_ */
