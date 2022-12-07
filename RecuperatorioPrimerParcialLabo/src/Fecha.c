#include "nexo.h"

eFecha FECHA_pedirFecha()
{
	eFecha aux;

	pedirEntero(&aux.anio, "\nIngrese año: ");
	pedirEnteroAcotado(&aux.mes, "\nIngrese mes: ", 1, 12);

	switch(aux.mes)
	{
	case 2:
		pedirEnteroAcotado(&aux.dia, "\nIngrese día: ", 1, 28);
	break;
	case 4:
	case 6:
	case 9:
	case 11:
		pedirEnteroAcotado(&aux.dia, "\nIngrese día: ", 1, 30);
	break;
	default:
		pedirEnteroAcotado(&aux.dia, "\nIngrese día: ", 1, 31);
	break;
	}

	return aux;
}
