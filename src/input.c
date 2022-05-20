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

static int myGets(char* pResultado, int len)
{
	int ret=-1;
	int index;
	fflush(stdin);

	if(fgets(pResultado,len,stdin)!=NULL)
		{
			index = strlen(pResultado)-1;
				if(pResultado[index]=='\n')
					{
						pResultado[index]='\0';
					}
			ret=0;
		}
	return ret;
}

static int isNumeric(char* pResultado)
{
	int ret=-1;
	int i=0; // me tomo esta licencia aca

	if(pResultado[0] == '-') // negativos
	{
		i = 1;
	}
	for( ; pResultado[i] !='\0'; i++)
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
			if((pResultado[i] >= 'A' || pResultado[i] <= 'Z') && (pResultado[i] >= 'a' || pResultado[i] <= 'z'))
				{
					ret = 0;
				}
		}
	}
	return ret;
}

static int isDni(char* pResultado, int len)
{
	int ret=-1;
	int i;
	int dotCount=0;

	for(i=1; i<len;i++)
		{
		//printf("Esta llegando aca\n");
			if(pResultado[i]!= '\0')
			{
				//printf("Esta llegando aca 2\n");
				if(pResultado[i] == '.')
				{
					ret = 0;
				}
				printf("Esta llegando aca 3\n");
				if(pResultado[i] < '1' || pResultado[i] > '9')
					{
						ret = 0;
					}
				if(pResultado[i] == '.')
					{
						//printf("Hay un punto\n");
						dotCount++;
					}
				if(dotCount !=2)
				{
					ret = -1;
				}
			}
		}
	// por ahora existen estas variantes para gente de 80/90 anios (dnis 0.000.000) y los centennials has 99 millones (dnis 00.000.000)
	if(pResultado[1] =='.' && pResultado[5] =='.')
	{
		if(pResultado[9] != '\0')
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}

	}
	else
	{
		if(pResultado[2] =='.' && pResultado[6] =='.')
		{
			ret = 0;
		}
		else
		{
			// no fue un dni valido
			ret = -1;
		}
	}

	//printf("pResultado en pos[8] %c \n", pResultado[8]);
	//printf("pResultado en pos[9] %c \n", pResultado[9]);
	//printf("el strlen de pResultado al final de la func. isDni %d \n", strlen(pResultado));
	if(strlen(pResultado)==9 && pResultado[8]!='\0' && pResultado[9]=='\0')
	{
		printf("strlen 9 pos 8 0 \n");
		ret=0;

	}
	else
	{
		if(pResultado[2]=='.' && pResultado[9]!='\0' && pResultado[10]=='\0')
		{
			ret=0;
		}
		else
		{
			// no cumple con el formato
			ret=-1;
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

	return ret;
}

int utn_getText(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	char aux[124];
	int ret=-1;
	int i;

		if(pResultado!=NULL && len>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				fflush(stdin);
				fgets(aux,sizeof(aux),stdin);
				aux[strlen(aux)-1]='\0';
				if(isNumeric(aux)==0)
				{
					if(isLetter(aux, len)==0) // que solo sean letras y no numeros
					{
						ret=0;
						strcpy(pResultado, aux);
						break;
					}
					else
						{
							if(isNumeric(aux)!=0)
							{
								ret=-1; // salio mal
								printf("%s",mensaje);
							}
						}
				}

			}
		}

	return ret;
}


int utn_getDni(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{
	char aux[12];
	int i;
	int ret=-1;

		if(pResultado!=NULL && len>0 && len<=12 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
		{
			for(i=0;i<reintentos;i++)
			{
				printf("%s",mensaje);
				fflush(stdin);
				fgets(aux,len,stdin);
				aux[strlen(aux)-1]='\0';
				if(isDni(aux, len)==0 && strlen(aux)<=10)
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



