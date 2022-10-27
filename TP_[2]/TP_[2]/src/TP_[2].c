/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Jugador.h"
#include "Confederacion.h"
#define MAX_CONFEDERACION 6
#define MAX_JUGADORES 3000

int main(void) {

	setbuf(stdout, NULL);
	Confederacion listConfederacion [MAX_CONFEDERACION] = {{1, "CONMEBOL", "SUDAMERCIA",1916},
														   {2, "UEFA", "EUROPA",1954},
														   {3, "AFC", "ASIA",1954},
														   {4, "CAF", "AFRICA",1957},
														   {5, "CONCACAF", "NORTE Y CENTRO AMERICA",1961},
														   {6, "OFC", "OCEANIA",1966}};


	Jugador listJugadores[MAX_JUGADORES];

	int opcion, opcionListar, opcionInforme;
	int contadorJugador = 0;
	int auxiliarIndice;
	int flagCase1 = 0;

	do{

		imprimirMenu();
					if(utn_getNumero(&opcion, "Ingrese opcion: \n", "\nERROR! Ingrese opcion: \n", 1, 6, 2) == 0){

						switch(opcion){
						//ALTA
						case 1:
							if(contadorJugador < MAX_JUGADORES){
								auxiliarIndice = Jugador_buscarLugarLibre(listJugadores, MAX_JUGADORES);
								if(auxiliarIndice >= 0){
									if(Jugador_addJugador(listJugadores, MAX_JUGADORES, auxiliarIndice, listConfederacion, MAX_CONFEDERACION)==0){
										printf("\nCarga realizada con exito\n");
										contadorJugador++;
										flagCase1 = 1;
									}
									else{
										printf("\nERROR al realizar la carga\n");
									}
								}
							}else{
								printf("\nNo hay mas espacio\n");
							}
							break;
						//MODIFICACION
						case 2:

							if(flagCase1 != 0){
								printf("\nSeleccione el ID del Jugador que desea modificar.\nIngrese 0 para cancelar la modificacion.\n");
								if(Jugador_modificar(listJugadores, MAX_JUGADORES, listConfederacion, MAX_CONFEDERACION) == 0){
									printf("\nModificacion exitosa\n");
									Jugador_imprimirTodos(listJugadores, MAX_JUGADORES);
								}
								else{
									printf("\nModificacion cancelada.\n");
								}
							} else {
								printf("\nDebe ingresar al menos un jugador para poder Modificar.\n");
							}

							break;

						//BAJA
						case 3:
							printf("----------------------------------------");
							printf("\nIngreso al menu de Baja de jugadores\n");
							if(contadorJugador > 0 && contadorJugador < MAX_JUGADORES){
								if(Jugador_imprimirTodos(listJugadores, MAX_JUGADORES) == 0){
									if(Jugador_bajaJugador(listJugadores, MAX_JUGADORES) == 0){
										printf("\nEliminacion exitosa\n");
										Jugador_imprimirTodos(listJugadores, MAX_JUGADORES);
										contadorJugador--;
									}
									else {
										printf("\nEliminacion cancelada");
									}
								}
							} else{
								printf("\nDebe ingresar al menos 1 Jugador para poder dar de Baja\n");
							}
							break;

						//INFORMAR
						/*case 4:
							if(contadorJugador > 0){
								if(utn_getNumero(&opcionInforme, "\nQue desea informar?\n1. Total y promedios de los importes, y cuantos listJugadores superan ese promedio."
														"\n2. Cantidad de listJugadores cuya fecha de publicacion es MENOR al 1-1-2000",
														"\Error! Ingrese un numero", 1, 2, 3) == 0){

									switch(opcionInforme){
									case 1:
										if(Jugador_informarPuntoA(listJugadores, MAX_JUGADORES) == 0){
											printf("\nInforme exitoso.\n");
										}
										break;
									case 2:
										if(Jugador_informarPuntoB(listJugadores, MAX_JUGADORES) == 0){
											printf("\nInforme exitoso.\n");
										}
										break;
									}

								}
							} else {
								printf("\nDebe ingresar al menos un Jugador para poder ingresar a la opcion de Informar\n");
							}*/
							break;

						//LISTAR
						case 5:
							if(contadorJugador > 0){
								if(utn_getNumero(&opcionListar, "\nQue desea listar?"
														"\n1. Todas las Jugadores"
														"\n2. Todos los paises"
														"\n3. Todos los autores"
														"\n4. Todos los listJugadores"
														"\n5. Listado de listJugadores ordenados por importe y titulo"
														"\n\nIngrese opcion: ", "\nError! Ingrese un numero: ",1, 5, 2) == 0){
									switch(opcionListar){
									case 1:
										printf("---- LISTADO DE JugadorES ----\n");
											/*if(Jugador_imprimirJugadores(Jugadores, MAX_ENTITIES) == 0){
												continue;
											}*/
										break;
									case 2:

										break;
									case 3:

										break;
									case 4:
										/*printf("---- LISTADO DE listJugadores ----\n");
										if(Jugador_listarlistJugadoresCompletos(listJugadores, MAX_JUGADORES) == 0){
											continue;
										}*/
										break;
									case 5:

										break;
									}

								}
							} else{
								printf("\nDebe ingresar al menos un Jugador para poder Listar\n");
							}
							break;
						case 6:
							printf("\nSaliendo del programa...");
							system("pause");
							break;
						}


					}

	}while(opcion != 6);

}