/*
 * Confederacion.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Facu
 */
#include "Confederacion.h"

/**
 * Funcin que autoincrementa el ID
 */
/*int idAutomatico = 1;
int Libro_ObtenerIdUnico(void) {
	return idAutomatico++;
}*/

void Confederacion_imprimirUno(Confederacion arrayConfederacion){
	printf("ID: %d\n",arrayConfederacion.id);
	printf("Nombre: %s\n",arrayConfederacion.nombre);
	printf("Region: %s\n",arrayConfederacion.region);
	printf("Anio de creacion: %d\n",arrayConfederacion.anioCreacion);
}


int Confederacion_imprimirConfederaciones(Confederacion *arrayConfederaciones, int size){
	int rtn = -1;
	int i;

	if (size > 0) {
		//ESTA TODO BIEN
		for (i = 0; i < size; i++) {
			if (arrayConfederaciones[i].status == OCUPADO) { //Si 'estado' == OCUPADO
				Confederacion_imprimirUno(arrayConfederaciones[i]);
				rtn = 0; //Ok
			}
		}
	}

	return rtn;
}
