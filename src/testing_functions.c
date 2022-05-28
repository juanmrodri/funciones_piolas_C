/*
 ============================================================================
 Name        : testing_functions.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 Camila Iglesias Guerrero21:31
En validaciones:
como las funciones suelen ser preguntas acerca de cómo es el dato
-ej SonSoloLetras- las respuestas son sí o no, o verdadero o falso.
Por eso los retornos son 0 (falso) o 1 (distinto de 0, o sea, verdadero)
En las otras funciones, retornamos cómo salió nuestro programa,
negativos para gestion de errores, 0 para 0 errores, salio todo Ok.


 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main(void) {
	setbuf(stdout, NULL);

	int enteroIngresado;
	float flotanteIngresado;
	char caracterIngresado;
	char cadenaIngresada[124];
	char dniIngresado[12];
	int i;


	// pedir cadena de char
	if(utn_getText(cadenaIngresada,124,"Por favor ingrese una cadena de caracteres ", "error al ingresar la cadena de caracteres\n\n", 2)==0)
	{
		for(i=0;i<strlen(cadenaIngresada);i++)
		{
			printf("\nPos %d: %c\n",cadenaIngresada[i],cadenaIngresada[i]);
		}
		printf("\nEl strlen de la cadena es: %d\n",strlen(cadenaIngresada));
		printf("\nLa cadena de caracteres es: %s\n", cadenaIngresada);
	}
	else
	{
		printf("\nNo fue posible tomar la cadena, volver a intentar\n\n");
	}
	// pedir float
	if(utn_getFloat(&flotanteIngresado, "Por favor ingrese un numero flotante ", "error al ingresar el flotante\n\n", 0, 100, 2)==0)
	{
		printf("\nEl numero entero seleccionado fue: %.2f\n", flotanteIngresado);
	}
	else
	{
		printf("\nNo fue posible tomar el numero flotante, volver a intentar\n\n");
	}

	// pedir int
	if(utn_getNumber(&enteroIngresado, "Por favor ingrese un numero entero ", "error al ingresar el entero\n\n", 1, 100, 2)==0)
	{
		printf("\nEl numero entero seleccionado fue: %d\n", enteroIngresado);
	}
	else
	{
		printf("\nNo fue posible tomar el numero entero, volver a intentar\n\n");
	}

	// pedir char
	if(utn_getChar(&caracterIngresado, "Por favor ingrese un caracter de la a a la z ", "error al ingresar el caracter\n\n", 97, 122, 2)==0)
	{
		printf("\nEl caracter seleccionado fue: %c\n", caracterIngresado);
	}
	else
	{
		printf("\nNo fue posible tomar el caracter, volver a intentar\n\n");
	}
	// pedir dni
	if(utn_getDni(dniIngresado,12,"Por favor ingrese un dni ", "error al ingresar el dni\n\n", 10)==0)
	{
		printf("\nEl dni seleccionado fue: %s\n", dniIngresado);
	}
	else
	{
		printf("\nNo fue posible tomar el dni, volver a intentar\n\n");
	}







	return EXIT_SUCCESS;
}
