/*
 ============================================================================
 Name        : PrimerParcialLabo.c
 Author      : Gian Rodriguez
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "nexo.h"

#define TAM_VEHICULOS 10
#define TAM_HOJAS 10
#define TAM_TIPOS 3


int main(void)
{
	setbuf(stdout, NULL);
	int retornoBaja;
	int retornoModificar;
	int retornoAltaHojas;
	int opcion;
	int opcionModificar;
	int opcionInformes;
	int contadorAltas = 0;
	int salirMenuModificaciones = 0;
	int salir = 0;
	int salirInformes = 0;

	eHojaServicio listaHojas [20000+TAM_HOJAS];
	eVehiculo listaVehiculos[TAM_VEHICULOS] = {{1, "FORD", 2010, "ROJO", 1001, OCUPADO},{2, "FIAT", 2012, "ROSA", 1001, OCUPADO}};
	eTipo listaTipo[TAM_TIPOS] = {{1001, "SEDAN 3PTAS"}, {1002, "SEDAN 5PTAS"}, {1003, "CAMIONETA"}};

	VEH_inicializarlista(listaVehiculos, TAM_VEHICULOS);
	HOJA_inicializarlista(listaHojas, TAM_HOJAS);

    do{
		printf("\n\nMENU DE OPCIONES"
				"\n\n1. ALTA VEHICULO"
				"\n2. MODIFICAR VEHICULO"
				"\n3. BAJA VEHICULO"
				"\n4. LISTAR VEHICULO"
				"\n5. LISTAR TIPOS DE VEHICULO"
				"\n6. ALTA HOJA DE SERVICIO"
				"\n7. LISTAR HOJA DE SERVICIO"
				"\n8. INFORMES"
				"\n9. SALIR "
				"\n\nIngrese una opcion: ");
			fflush(stdin);
			if(scanf("%d", &opcion) == 1)
			{
				switch(opcion)
				{
					case 1:
						if(VEH_darAltaVehiculo(listaVehiculos, TAM_VEHICULOS) != 0)
						{
							printf("\nERROR. No se pudo dar de alta.");
						}
						else
						{
							printf("\nVehiculo dado de alta correctamente.");
							contadorAltas++;
						}
					break;
					case 2:
						if(contadorAltas > 0)
						{
							do{
								printf("\n\n MENU MODIFICACIONES"
										"\n1- MODIFICAR DESCRIPCION"
										"\n2- MODIFICAR PRECIO DEL SERVICIO"
										"\n3- VOLVER AL MENU PRINCIPAL"
										"\n\nIngrese una opcion: ");
								if(scanf("%d", &opcionModificar) ==1)
								{
									switch(opcionModificar)
									{
										case 1:
											retornoModificar = NEXO_modificarDescripcionVehiculo(listaVehiculos, listaHojas, TAM_VEHICULOS, TAM_HOJAS);

											switch(retornoModificar)
											{
												case 0:
													printf("\nLa descripción se ha cambiado exitosamente");
												break;
												case -1:
													printf("\nError al intentar modificar");
												break;
												case -2:
													printf("\nEl ID solicitado no existe");
												break;
											}
										break;
										case 2:
											retornoModificar = HOJA_modificarPrecioServicio(listaHojas, TAM_HOJAS);

											switch(retornoModificar)
											{
												case 0:
													printf("\nLa descripción se ha cambiado exitosamente");
												break;
												case -1:
													printf("\nError al intentar modificar");
												break;
												case -2:
													printf("\nEl ID solicitado no existe");
												break;
											}
										break;
										case 3:
											salirMenuModificaciones = verificarRespuesta("¿Desea volver al menu principal?");
										break;
										default:
											printf("\ERROR! Por favor, ingrese una opcion valida.");
										break;
									}
								}
								else
								{
									printf("\ERROR! Por favor, ingrese una opcion valida.");
								}
							}while(salirMenuModificaciones != 1);
						}
						else{
							printf("\nPor favor, ingrese una alta para continuar con ésta acción");
						}
					break;
					case 3:
						if(contadorAltas > 0)
						{
							retornoBaja = VEH_darBajaVehiculo(listaVehiculos, TAM_VEHICULOS);

							switch(retornoBaja)
							{
								case 0:
									printf("\nEl vehiculo ha sido dado de baja exitosamente");
									contadorAltas--;
								break;
								case -1:
									printf("\nFallo al intentar dar de baja");
								break;
								case -2:
									printf("\nEl ID ingresado no existe");
								break;
							}
						}
						else{
							printf("\nPor favor, ingrese una alta para continuar con ésta acción");
						}
					break;
					case 4:
						if(contadorAltas > 0)
						{
							VEH_mostrarTodos(listaVehiculos, TAM_VEHICULOS);
						}
						else{
							printf("\nPor favor, ingrese una alta para continuar con ésta acción");
						}
					break;
					case 5:
						if(contadorAltas > 0)
						{
							TIPO_mostrarTodoTipo(listaTipo, TAM_TIPOS);
						}
						else{
							printf("\nPor favor, ingrese una alta para continuar con ésta acción");
						}
					break;
					case 6:
						if(contadorAltas > 0)
						{
							retornoAltaHojas = NEXO_darAltaHojas(listaVehiculos, listaHojas, TAM_VEHICULOS, TAM_HOJAS);

							switch(retornoAltaHojas)
							{
								case 0:
									printf("\nLa hoja ha sido dada de alta exitosamente");
								break;
								case -1:
									printf("\nFallo al intentar dar de alta");
								break;
								case -2:
									printf("\nEl ID ingresado no existe");
								break;
							}
						}
						else{
							printf("\nPor favor, ingrese una alta para continuar con ésta acción");
						}
					break;
					case 7:
						if(contadorAltas > 0)
						{
							HOJA_mostrarTodos(listaHojas, TAM_HOJAS);
						}
						else{
							printf("\nPor favor, ingrese una alta para continuar con ésta acción");
						}
					break;
					case 8:
						do{
								printf("\n\nMENU DE OPCIONES"
										"\n\n1. VER VEHICULOS DE UN TIPO SELECCIONADO"
										"\n2. VER TODAS LAS HOJAS DE SERVICIO EFECTUADAS EN UNA FECHA SELECCIONADA"
										"\n3. VER IMPORTE TOTAL DE LAS HOJAS DE SERVICIO DE UN VEHÍCULO"
										"\n4. VER IMPORTE DE TODAS LAS HOJAS DE SERVICIO EFECTUADAS EN UNA FECHA SELECCIONADA"
										"\n5. SALIR "
										"\n\nIngrese una opcion: ");
									fflush(stdin);
									if(scanf("%d", &opcionInformes) == 1)
									{
										switch(opcionInformes)
										{
											case 1:
												NEXO_mostrarVehiculosTipo(listaVehiculos, listaTipo, TAM_VEHICULOS, TAM_TIPOS);
											break;
											case 2:
												HOJA_mostrarHojasFechaSeleccionada(listaHojas, TAM_HOJAS);
											break;
											case 3:
												NEXO_mostrarImporteTotalUnVehiculo(listaVehiculos, listaHojas, TAM_VEHICULOS, TAM_HOJAS);
											break;
											case 4:
												NEXO_mostrarImporteTotalFecha(listaVehiculos, listaHojas, listaTipo, TAM_VEHICULOS, TAM_HOJAS, TAM_TIPOS);
											break;
											case 5:
												salirInformes = verificarRespuesta("\n¿Desea salir del programa?");
											break;
											default:
												printf("\nLa opción ingresada no es válida");
											break;
										}
									}
									else
									{
										printf("\nLa opción ingresada no es válida");
									}
						}while(salirInformes != 1);
					break;
					case 9:
						salir = verificarRespuesta("\n¿Desea salir del programa?");
					break;
					default:
						printf("\nERROR! La opcion ingresada no es válida");
					break;
				}
			}
			else
			{
				printf("\nERROR! La opcion ingresada no es válida");
			}

	}while(salir != 1);

	return 0;
}
