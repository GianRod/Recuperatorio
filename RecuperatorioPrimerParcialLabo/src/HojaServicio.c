#include "nexo.h"

void HOJA_inicializarlista(eHojaServicio lista[], int tam)
{
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
	}
}

int HOJA_obtenerId(void) {
	static int idHoja = 20000;
	idHoja++;
	return idHoja;
}

int HOJA_obtenerIndexLibre(eHojaServicio lista[], int tam)
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

int HOJA_buscarPosicionPorID(eHojaServicio array[], int tam, int id){
	int retorno;

	retorno = -1;

	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(array[i].isEmpty == OCUPADO && array[i].idHoja == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void HOJA_mostrarUno(eHojaServicio aux)
{
	printf("\n+--------+------------+-------------------------------+-------+-----------------+");
	printf("\n|%-8d|%-12d|%-31s|%-7d|%d/%d/%-8d|", aux.idHoja, aux.vehiculoId, aux.descripcion, aux.precioServicio, aux.fecha.dia, aux.fecha.mes, aux.fecha.anio );
	printf("\n+--------+------------+-------------------------------+-------+-----------------+");
}

void HOJA_mostrarTodos(eHojaServicio lista[], int tam)
{
	if(lista != NULL && tam > 0)
	{
		printf("\n+--------+------------+-------------------------------+-------+-----------------+");
		printf("\n|ID HOJA |ID VEHICULO |DESCRIPCION                    |PRECIO |FECHA DE SERVICIO|");
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == OCUPADO)
			{
				HOJA_mostrarUno(lista[i]);
			}
		}
	}
}

void HOJA_mostrarHojasFechaSeleccionada(eHojaServicio lista[], int tam)
{
	eFecha auxFecha;
	eHojaServicio auxHoja;
	auxFecha = FECHA_pedirFecha();

	for(int i = 0; i < tam; i++)
	{
		auxHoja = lista[i];
		if((auxFecha.dia == auxHoja.fecha.dia) && (auxFecha.mes == auxHoja.fecha.mes) && (auxFecha.anio == auxHoja.fecha.anio))
		{
			HOJA_mostrarUno(auxHoja);
		}
	}
}


int HOJA_modificarPrecioServicio(eHojaServicio lista[], int tam)
{
	int id;
	int retornoId;
	int posicion;
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		HOJA_mostrarTodos(lista, tam);
		retornoId = pedirEnteroAcotado(&id, "Ingrese el ID a modificar: ", 20000, 20000+tam);

		if(retornoId != -1)
		{
			posicion = HOJA_buscarPosicionPorID(lista, tam, id);
			if(posicion != -1)
			{
				pedirEntero(&lista[posicion].precioServicio, "\nIngrese el nuevo costo del servicio");
				retorno = 0;
			}
			else{
				retorno = -2;
			}
		}
	}

	return retorno;
}









































