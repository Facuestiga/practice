/*
 * Jugador.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Facu
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Confederacion.h"

#define MAX_CHARS 200
#define LIBRE 0
#define OCUPADO 1



typedef struct{
	int id;
	char nombre[MAX_CHARS];
	char posicion[MAX_CHARS];
	int numeroCamiseta;
	int idConfederacion;
	float salario;
	int aniosContrato;
	int status;
}Jugador;

int Jugador_ObtenerIdUnico(void);
void Jugador_imprimirUno(Jugador arrayJugador);
int Jugador_imprimirTodos(Jugador arrayJugador[], int size);

int Jugador_initArrayJugador(Jugador *arrayJugador,int size);
int Jugador_buscarLugarLibre(Jugador *arrayJugador,int size);
int Jugador_addJugador(Jugador *arrayJugador,int size,int indice, Confederacion *arrayConfederacion, int limitConfederacion);
int Jugador_bajaJugador(Jugador *arrayJugador, int size);
int Jugador_modificar(Jugador *arrayJugador,int size, Confederacion *arrayConfederacion, int limitConfederacion);
Jugador Jugador_modificarUnJugador(Jugador Jugador, int size, Confederacion *arrayConfederacion, int limitConfederacion);
int Jugador_buscarJugadorPorId(Jugador *arrayJugador, int size);
int Jugador_buscarPorIdParametro(Jugador *arrayJugador, int size, int id);



int Jugador_listarJugadorsCompletos(Jugador *arrayJugadors, int size);

/***Menu***/
void imprimirMenu();

/***Informar***/
int Jugador_informarPuntoA(Jugador *arrayJugador, int size);
int Jugador_informarPuntoB(Jugador *arrayJugador, int size);



#endif /* JUGADOR_H_ */
