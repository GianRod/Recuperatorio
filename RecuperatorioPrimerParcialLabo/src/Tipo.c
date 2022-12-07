#include "nexo.h"

int TIPO_buscarPosicionPorID(eTipo array[], int tam, int id){
	int retorno;

	retorno = -1;

	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(array[i].idTipo == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void TIPO_mostrarUnTipo(eTipo aux)
{
	printf("\n+-----+------------+");
	printf("\n|%-5d|%-12s|", aux.idTipo, aux.descripcion);
	printf("\n+-----+------------+");
}

void TIPO_mostrarTodoTipo(eTipo listaTipos[], int tam)
{
	if(listaTipos != NULL && tam > 0)
	{
		printf("\n+-----+------------+");
		printf("\n|ID   |DESCRIPCION |");
		for(int i = 0; i < tam; i++)
		{
				TIPO_mostrarUnTipo(listaTipos[i]);
		}
	}
}

/*

int TIPO_obtenerId(void) {
	static int idTipo = 1000;
	idTipo++;
	return idTipo;
}

void TIPO_inicializarlista(eTipo lista[], int tam)
{
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
	}
}

int TIPO_obtenerIndexLibre(eTipo lista[], int tam)
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

eTipo TIPO_pedirDatos(void)
{
	eTipo aux;

	if(pedirCadena(aux.descripcion, "\nIngrese la descripción del vehículo", TAM_DESC) == 0)
	{
		printf("\t**********La acción se ha completado correctamente**********\n");
	}
	else
	{
		do{
			printf("ERROR! No se pudo ingresar la descripcion correctamente");
		}while(pedirCadena(aux.descripcion, "\nIngrese la descripción del vehículo", TAM_DESC) != 0);
	}

	return aux;
}

int TIPO_darAltaVehiculo(eTipo lista[], int tam)
{
	eTipo aux;
	int posicionLibre;
	int retorno = -1;

	posicionLibre = TIPO_obtenerIndexLibre(lista, tam);
	aux = TIPO_pedirDatos();

	if(posicionLibre != -1)
	{
		aux.idTipo = TIPO_obtenerId();
		aux.isEmpty = OCUPADO;
		lista[posicionLibre] = aux;
		retorno = 0;
	}

	return retorno;
}

int TIPO_modificarVehiculo(eTipo lista[], int tam)
{
	int id;
	int retornoId;
	int posicion;
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		TIPO_mostrarTodoTipo(lista, tam);
		retornoId = pedirEnteroAcotado(&id, "Ingrese el ID a modificar: ", 1000, 1000+tam);

		if(retornoId != -1)
		{
			posicion = TIPO_buscarPosicionPorID(lista, tam, id);
			if(posicion != -1){
				lista[posicion] = TIPO_pedirDatos();
				lista[posicion].idTipo = id;
				lista[posicion].isEmpty = OCUPADO;
				printf("ID: %d", lista[posicion].idTipo);
				retorno = 0;
			}
			else{
				retorno = -2;
			}
		}
	}

	return retorno;
}

int TIPO_darBajaTipo(eTipo lista[], int tam)
{
	int id;
	int retornoId;
	int posicion;
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		TIPO_mostrarTodoTipo(lista, tam);
		retornoId = pedirEnteroAcotado(&id, "Ingrese el ID a dar de baja: ", 1000, 1000+tam);

		if(retornoId != -1)
		{
			posicion = TIPO_buscarPosicionPorID(lista, tam, id);
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

*/
