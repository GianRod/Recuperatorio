#include "input.h"

int verificarRespuesta(char mensaje[]){
	char respuesta;

	printf("\n%s (s/n): ", mensaje);
	fflush(stdin);
	scanf("%c", &respuesta);
	respuesta = tolower(respuesta);

	while(respuesta != 's' && respuesta != 'n'){
		printf("Error: Desea salir del menu?  s/n: ");
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = tolower(respuesta);
	}

	if(respuesta == 's'){
		return 1;
	}
	else
	{
		return 0;
	}
}

int pedirEnteroAcotado(int* numero, char mensaje[], int min, int max){

	int retorno;
	int aux;

	retorno = -1;

	if(mensaje != NULL)
	{
		printf("\n%s(entre %d y %d)", mensaje, min, max);

		while((scanf("%d", &aux))!= 1 || (aux < min || aux > max) )
		{
			printf("\nError! Por favor ingrese un número (entre %d y %d)", min, max);
			fflush(stdin);
		}


		*numero = aux;
		retorno = 0;
	}
	return retorno;
}

int pedirEntero(int* numero, char mensaje[]){

	int retorno;
	int aux;

	retorno = -1;

	if(mensaje != NULL)
	{
		printf("\n%s", mensaje);

		while((scanf("\n%d", &aux))!= 1)
		{
			printf("\nError! Por favor ingrese un número");
			fflush(stdin);
		}


		*numero = aux;
		retorno = 0;
	}
	return retorno;
}

int ordenarCadena(char array[], int tam){
	int retorno;

	retorno = -1;

	if(array != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(array[i] == 32)
			{
				i++;
				array[i] = toupper(array[i]);
			}
			else
			{
				array[i] = tolower(array[i]);
			}
		}
		array[0] = toupper(array[0]);
		retorno = 0;

	}


	return retorno;
}

int pedirCadena(char array[], char mensaje[], int tam)
{

	int retorno;
	int largo;

	retorno = -1;

	if(array != NULL && tam > 0)
	{
		printf("%s\n", mensaje);
		fflush(stdin);
		fgets(array, tam, stdin);
		array[strlen(array)-1] = '\0';
		ordenarCadena(array, tam);
		largo = strlen(array);

		retorno = 0;
		for(int i = 0; i < largo; i++)
		{
			if(array[i] != 32)
			{
				if(isalpha(array[i]) == 0)
				{
					return -1;
					break;
				}
			}
		}
	}

	return retorno;
}
