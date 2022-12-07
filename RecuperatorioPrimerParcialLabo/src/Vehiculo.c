#include "nexo.h"

int VEH_obtenerId(void) {
	static int idVehiculo = 0;
	idVehiculo++;
	return idVehiculo;
}

void VEH_inicializarlista(eVehiculo lista[], int tam)
{
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
	}
}

int VEH_buscarPosicionPorID(eVehiculo array[], int tam, int id){
	int retorno;

	retorno = -1;

	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(array[i].isEmpty == OCUPADO && array[i].idVehiculo == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int VEH_obtenerIndexLibre(eVehiculo lista[], int tam)
{
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

eVehiculo VEH_pedirDatos(void)
{
	eVehiculo aux;
	int tipo;

	if(pedirCadena(aux.descripcion, "\nIngrese la descripción del vehículo", TAM_DESC) == 0)
	{
		printf("\t**********La acción se ha completado correctamente**********\n");
		if(pedirCadena(aux.color, "\nIngrese el color del vehículo", TAM_COLOR) == 0)
		{
			printf("\t**********La acción se ha completado correctamente**********\n");
			if(pedirEntero(&aux.modelo, "\nIngrese año de fabricacion del vehiculo") == 0)
			{
				do
				{
					printf( "\nIngrese el tipo de auto:"
								"\n1- SEDAN 3PTAS"
								"\n2- SEDAN 5PTAS"
								"\n3- CAMIONETA");
					if(scanf("%d", &tipo) == 1)
					{
						switch(tipo)
						{
							case 1:
								aux.tipoId = 1001;
							break;
							case 2:
								aux.tipoId = 1002;
							break;
							case 3:
								aux.tipoId = 1003;
							break;
							default:
								aux.tipoId = 0;
								printf("\nERROR! Opción no válida.");
							break;
						}
					}
				}while(aux.tipoId == 0);
			}
			else
			{
				printf("ERROR! No se pudo asignar el año correctamente");
			}
		}
		else
		{
			do{
				printf("ERROR! No se pudo ingresar el color correctamente");
			}while(pedirCadena(aux.color, "\nIngrese el color del vehículo", TAM_COLOR));

		}
	}
	else
	{
		do{
			printf("ERROR! No se pudo ingresar la descripcion correctamente");
		}while(pedirCadena(aux.descripcion, "\nIngrese la descripción del vehículo", TAM_DESC) != 0);
	}

	return aux;
}

int VEH_darAltaVehiculo(eVehiculo lista[], int tam)
{
	eVehiculo aux;
	int posicionLibre;
	int retorno = -1;

	posicionLibre = VEH_obtenerIndexLibre(lista, tam);
	aux = VEH_pedirDatos();

	if(posicionLibre != -1)
	{
		aux.idVehiculo = VEH_obtenerId();
		aux.isEmpty = OCUPADO;
		lista[posicionLibre] = aux;
		retorno = 0;
	}

	return retorno;
}

void VEH_mostrarUno(eVehiculo aux)
{
	int id;
	char tipo[MAX_DESC];

	id = aux.tipoId;

	switch(id)
	{
		case 1001:
			strcpy(tipo, "SEDAN 3PTAS");
		break;
		case 1002:
			strcpy(tipo, "SEDAN 5PTAS");
		break;
		case 1003:
			strcpy(tipo, "CAMIONETA");
		break;
	}

	printf("\n+-----+------------+-------+----------+------------------------------+");
	printf("\n|%-5d|%-12s|%-7d|%-10s|%-30s|", aux.idVehiculo, aux.descripcion, aux.modelo, aux.color, tipo);
	printf("\n+-----+------------+-------+----------+------------------------------+");
}

void VEH_mostrarTodos(eVehiculo lista[], int tam)
{
	if(lista != NULL && tam > 0)
	{
		printf("\n+-----+------------+-------+----------+------------------------------+");
		printf("\n|ID   |DESCRIPCION |MODELO |COLOR     |TIPO                          |");
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				VEH_mostrarUno(lista[i]);
			}
		}
	}
}

int VEH_darBajaVehiculo(eVehiculo lista[], int tam)
{
	int id;
	int retornoId;
	int posicion;
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		VEH_mostrarTodos(lista, tam);
		retornoId = pedirEnteroAcotado(&id, "Ingrese el ID a dar de baja: ", 1, tam);

		if(retornoId != -1)
		{
			posicion = VEH_buscarPosicionPorID(lista, tam, id);
			if(posicion != -1){
				lista[posicion].isEmpty = LIBRE;
				retorno = 0;
			}
			else{
				retorno = -2;
			}
		}
		else{
			retorno = -1;
		}
	}


	return retorno;
}

















