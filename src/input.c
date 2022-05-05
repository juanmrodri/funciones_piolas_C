/*
 * input.c
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#include <stdlib.h>
#include <ctype.h>
#include "input.h"


// static func. firma

static int getInt(int* pResultado);

static int getFloat(float* pResultado);

static int isNumeric(char* pResultado);

static int isFloat(char* pResultado);

static int myGets(char* cadena, int longitud);

// stactic func. desarrollo

static int getInt(int* pResultado)
{
	int ret=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && isNumeric(buffer))
	{
		ret=0;
		*pResultado = atoi(buffer);
	}
	return ret;
}

static int getFloat(float* pResultado)
{
	int ret=-1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && isFloat(buffer))
	{
		ret=0;
		*pResultado = atof(buffer);
	}
	return ret;
}

static int myGets(char* pResultado, int longitud)
{
	fflush(stdin);

	fgets(pResultado,longitud,stdin);

	pResultado[strlen(pResultado)-1]='\0'; // arregla el enter que se agrega al final, para que fgets cargue correctamente la cadena

	return 0;
}

static int isNumeric(char* pResultado)
{
	int ret=-1;
	int i; // me tomo esta licencia aca

	if(pResultado[0] == '-') // negativos
	{
		i = 1;
	}
	for(i=0; pResultado[i] !='\0'; i++)
	{
		if(pResultado[i] > '9' || pResultado[i] < '0')
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

static int isFloat(char* pResultado)
{
	int ret=-1;
	int i=0; // me tomo esta licencia aca

	if(pResultado[0] == '-') // negativos
	{
		i = 1;
	}
	for( ; pResultado[i] !='\0'; i++)
	{
		if((pResultado[i] > '9' || pResultado[i] < '0') && pResultado[i]!='.')
		{
			ret = 0;
			break;
		}
	}

	return ret;
}

static int isLetter(char* pResultado, int len)
{
	int ret=-1;
	int i;
	for(i=0; i<len;i++)
	{
		if(pResultado[i]!='\0')
		{
			if((pResultado[i] < 'A' || pResultado[i] > 'Z') && (pResultado[i] < 'a' || pResultado[i] > 'z') && (pResultado[i] != ' '))
				{
					ret = 0;
				}
		}
	}
	return ret;
}

int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int aux;
	int i;
	int ret=-1;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				if(getInt(&aux) == 0 && aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					ret=0; // salio bien
					break;
				}
				else
				{
					printf("%s",mensajeError);
					ret=-1;
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=-1; // salio mal
		}

	return ret;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float aux;
	int i;
	int ret=-1;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				if(getFloat(&aux) == 0 && aux >= minimo && aux <= maximo)
				{
					*pResultado = aux;
					ret=0; // salio bien
					break;
				}
				else
				{
					printf("%s",mensajeError);
					ret=-1;
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=-1; // salio mal
		}

	return ret;
}

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
	char aux[2];
	int ret=-1;
	int i;

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				if(isdigit(*pResultado)==0)
				{
					printf("%s",mensaje);
					fgets(aux,sizeof(aux),stdin);
					strcpy(pResultado, aux);
					ret=0;
					break;
				}
				else
				{
					printf("%s",mensaje);
					ret=-1; // salio mal
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=-1; // salio mal
		}

	return ret;
}

int utn_getText(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	char aux[124];
	int i;
	int ret=-1;

		if(pResultado!=NULL && len>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				fflush(stdin);
				fgets(aux,sizeof(aux),stdin);
				aux[strlen(aux)-1]='\0';
				if(isLetter(aux, len)==0) // que solo sean letras y no numeros
				{
					strcpy(pResultado, aux);
					ret=0;
					break;
				}
			}
		}
		else
		{
			printf("%s",mensaje);
			ret=1; // salio mal
		}

	return ret;
}

int utn_cargaForzada(int* kilometros, float* precioAerolineas, float* precioLatam, int km, float aerolineas, float latam)
{
	int ret;

	ret=1;
	if(kilometros!=NULL && precioAerolineas!=NULL && precioLatam!=NULL && km >0 && aerolineas>0 && latam>0)
	{
		*kilometros = km;
		*precioAerolineas = aerolineas;
		*precioLatam = latam;
		ret=0;
		printf("\nCarga forzada realizada exitosamente\n\n");
	}

	return ret;
}


