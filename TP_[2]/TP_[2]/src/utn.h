/*
 * utn.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Facu
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_get_name(char* pResultado,int size,char* mensaje,char* mensajeError,int reintentos);
int utn_Val_isValidName(char* nombre);
int get_myGets(char* pResultado, int len);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* UTN_H_ */
