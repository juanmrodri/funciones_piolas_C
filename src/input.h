/*
 * input.h
 *
 *  Created on: 7 abr 2022
 *      Author: juanm
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* \brief Solicita un número entero a un usuario y se llama a la funcion getInt para recibirlo
* \param pResultado Se carga el numero ingresado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
* \brief Solicita un número flotante a un usuario y se llama a la funcion getInt para recibirlo
* \param pResultado Se carga el numero ingresado
* \param mensaje Mensaje que solicita que se debe hacer
* \param mensajeError Es el mensaje a ser mostrado en caso de error
* \param minimo Limite inferior a validar
* \param maximo Limite superior a validar
* \param reintentos cantidad de intentos en caso de error
* \return exito = [0] - error = [1]
*/
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getText(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

int utn_getDni(char* pResultado, int len, char* mensaje, char* mensajeError, int reintentos);

int utn_cargaForzada(int* kilometros, float* precioAerolineas, float* precioLatam, int km, float aerolineas, float latam);


#endif /* INPUT_H_ */
