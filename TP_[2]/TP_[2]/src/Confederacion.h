/*
 * Confederacion.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Facu
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define MAX_CHARS 200
#define LIBRE 0
#define OCUPADO 1

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	int status;

}Confederacion;

void Confederacion_imprimirUno(Confederacion arrayConfederacion);
int Confederacion_imprimirConfederaciones(Confederacion *arrayConfederaciones, int size);


#endif /* CONFEDERACION_H_ */
