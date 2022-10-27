/*
 * Jugador.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Facu
 */


#include "Jugador.h"
#include "Confederacion.h"
#include "utn.h"

void imprimirMenu(){
	printf("\n\tMenu Principal - Facundo Estigarribia\n\n"
			"1.Alta\n"
			"2.Modificacion\n"
			"3.Baja\n"
			"4.Informar\n"
			"5.Listar\n"
			"6.Salir\n\n");
}

/**
 * Funcin que autoincrementa el ID
 */
int idAutomatico = 1;
int Jugador_ObtenerIdUnico(void) {
	return idAutomatico++;
}


/**
 * @brief Funcion que imprime un solo Jugador
 * @param arrayJugador: arrayJugador de listado de Jugadors
 */
void Jugador_imprimirUno(Jugador arrayJugador) {
	printf("---------------------------");
	printf("\nID: %d\n",arrayJugador.id);
	printf("Nombre: %s\n",arrayJugador.nombre);
	printf("Posicion: %s\n",arrayJugador.posicion);
	printf("\nNumero de camiseta: %d\n",arrayJugador.numeroCamiseta);
	printf("\nSalario: %.2f\n",arrayJugador.salario);
	printf("\nAnios de contrato: %d\n",arrayJugador.aniosContrato);
	printf("---------------------------");
	printf("---------------------------\n\n");
}

/**
 * @brief Funcion que imprime todos los Jugadors
 * @param arrayJugador: arrayJugador de Jugadors
 * @param size: longitud del arrayJugador
 * @return Retorna 0 caso Exito! (-1) Error!
 */
int Jugador_imprimirTodos(Jugador arrayJugador[], int size) {
	int rtn = -1;
	int i;

	if (arrayJugador != NULL && size > 0) {
			//ESTA TODO BIEN
			for (i = 0; i < size; i++) {
				if (arrayJugador[i].status == OCUPADO) { //Si 'estado' == OCUPADO
					Jugador_imprimirUno(arrayJugador[i]);
					rtn = 0; //Ok
				}
			}
	}

	return rtn;
}

/***
 * Funcion para inicializar el status del array en 0
 * @param arrayJugador
 * @param size
 * @return retorna 1 caso Exito, 0 en caso de Error
 *  */
int Jugador_initArrayJugador(Jugador *arrayJugador,int size){
	int i;
	int retorno = -1;
	if(size > 0)
	{

		for(i=0;i<size;i++)
		{
			arrayJugador[i].status = LIBRE;

		}
		retorno = 0;
	}
	return retorno;
}

/**
 * Funcion que busca un lugar libre en el array
 * @param arrayJugador
 * @param size
 * @return retorna el index del array que esta libre, -1 en caso de error
 */
int Jugador_buscarLugarLibre(Jugador *arrayJugador,int size){
	int index = -1;
	int i;
	if(size > 0)
	{
		index = 0;
		for(i=0;i<size;i++)
		{
			if(arrayJugador[i].status == LIBRE)
			{
				index = i;
				break;
			}
		}

	}
	return index;
}

/**
 * Funcion que busca un ID pasado por parametro
 * @param arrayJugador
 * @param size
 * @param id: ID a buscar
 * @return retorno el indice donde se encuentra el id a buscar, -1 en caso de error
 */
int Jugador_buscarPorIdParametro(Jugador *arrayJugador, int size, int id){
	int rtn = -1;
	int i;

	if (size > 0) {
		for (i = 0; i < size; i++) {
			if (arrayJugador[i].id == id && arrayJugador[i].status == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

/**
 * Funcion para dar de ALTA un Jugador
 * @param arrayJugador
 * @param size
 * @param indice: posicion del array donde se va a dar de alta
 * @param arrayEditoriales
 * @param arrayConfederaciones
 * @param sizeEntities
 * @return retorna 0 en caso de exito, o -1 en caso de error
 */
int Jugador_addJugador(Jugador *arrayJugador,int size,int indice, Confederacion *arrayConfederacion, int limitConfederacion){
	int retorno = -1;
	int i;
	int idConfederacion;
	Jugador bufferJugador;

	if(size > 0 && indice < size && indice >= 0){
		if(utn_get_name(bufferJugador.nombre, MAX_CHARS, "\nIngrese nombre del Jugador: ", "\nError! Ingrese un nombre", 2) == 0){

			strncpy(bufferJugador.nombre, strlwr(bufferJugador.nombre), MAX_CHARS);
			bufferJugador.nombre[0] = toupper(bufferJugador.nombre[0]);
			for(i=0; i<size; i++){
				if(bufferJugador.nombre[i] == ' '){
					bufferJugador.nombre[i + 1] = toupper(bufferJugador.nombre[i + 1]);
				}
			}

			if(utn_get_name(bufferJugador.posicion, MAX_CHARS, "\nIngrese la posicion del Jugador: ", "\nError! Ingrese una posicion", 2) == 0){

				strncpy(bufferJugador.posicion, strlwr(bufferJugador.posicion), MAX_CHARS);
				bufferJugador.posicion[0] = toupper(bufferJugador.posicion[0]);
				for(i=0; i<size; i++){
					if(bufferJugador.posicion[i] == ' '){
						bufferJugador.posicion[i + 1] = toupper(bufferJugador.posicion[i + 1]);
					}
				}

				printf("\nSeleccione el ID de la confederacion del jugador\n");
				for(i = 0; i<limitConfederacion; i++){
					printf("\nID: %d\nNombre:%s", arrayConfederacion[i].id, arrayConfederacion[i].nombre);
				}

				if(utn_getNumero(&idConfederacion, "\nIngrese el ID de la confederacion", "\nError. Ingrese un numero.\n", 1, 6, 2) == 0 &&
				   utn_getNumero(&bufferJugador.numeroCamiseta, "\n\nIngrese el numero de camiseta: ", "\nError. Ingrese un numero.\n", 1, 99, 2) == 0 &&
				   utn_getNumeroFlotante(&bufferJugador.salario, "\nIngrese el salario: ", "\nError! Ingrese un numero", 10, 10000000, 2)== 0 &&
				   utn_getNumero(&bufferJugador.aniosContrato, "\nIngrese los anios de contrato: ", "\nError! Ingrese un numero: ", 1, 35, 2) == 0){
				   bufferJugador.id = Jugador_ObtenerIdUnico();
				   bufferJugador.idConfederacion = idConfederacion;
				   bufferJugador.status = 1;
				   arrayJugador[indice] = bufferJugador;
				   Jugador_imprimirUno(arrayJugador[indice]);
				   retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/**
 * Funcion para dar de BAJA un Jugador
 * @param arrayJugador
 * @param size
 * @return retorna 0 caso exito, 0 -1 en caso de error
 */
int Jugador_bajaJugador(Jugador *arrayJugador, int size){
	int retorno = -1;
	int idBaja;
	int index;
	int confirma;

	if(size > 0){
		if(utn_getNumero(&idBaja, "\nIngrese ID del Jugador a eliminar: ", "\nError! Ingrese un numero: ", 1, 100, 3) == 0){
			while (Jugador_buscarPorIdParametro(arrayJugador, size, idBaja) == -1) {
				printf("NO EXISTE ID.");
				printf("INGRESE ID A DAR DE BAJA: ");
				utn_getNumero(&idBaja, "\nIngrese ID del Jugador a eliminar: ", "\nError! Ingrese un numero: ", 1, 100, 3);
			}
			index = Jugador_buscarPorIdParametro(arrayJugador, size, idBaja);
			if(utn_getNumero(&confirma, "\nEsta seguro que desea continuar con la eliminacion? [1-SI]-[0-NO]", "\nError! Ingrese un numero", 0, 1, 3) == 0){
				if(confirma){
					arrayJugador[index].status = LIBRE;

					//Baja Exitosa
					retorno = 0;
				}else {
					printf("Se ha cancelado el proceso de eliminacion");
				}
			}
		}
	}

	return retorno;
}

/**
 * Funcion para modificar Jugadors
 * @param arrayJugador
 * @param size
 * @param arrayEditoriales
 * @param arrayConfederaciones
 * @param sizeEntities
 * @return
 */
int Jugador_modificar(Jugador *arrayJugador,int size,Confederacion *arrayConfederacion, int limitConfederacion){

	int retorno = -1;
	//int idAux;
	int index;
	Jugador auxJugador;

		index = Jugador_buscarJugadorPorId(arrayJugador, size);
		if(index > -1 && size > 0){
			auxJugador = arrayJugador[index];

			auxJugador = Jugador_modificarUnJugador(auxJugador,size, arrayConfederacion, limitConfederacion);

			arrayJugador[index] = auxJugador;
			retorno = 0;
		}

	return retorno;
}

/**
 * Funcion que modifica UN Jugador del array
 * @param Jugador
 * @param arrayEditoriales
 * @param arrayConfederaciones
 * @param sizeEntities
 * @return retorna el Jugador
 */
Jugador Jugador_modificarUnJugador(Jugador jugador, int size, Confederacion *arrayConfederacion, int limitConfederacion ){
	int opcion;
	int i;
		if(utn_getNumero(&opcion, "\nIngrese la opcion de lo que desea modificar\n"
								"1.Nombre\n"
								"2.Posicion\n"
								"3.Numero de camiseta\n"
								"4.Confederacion\n"
								"5.Salario\n"
								"6.Anios de contrato\n"
								"\n0.CANCELAR Modificacion\n", "Opcion no habilitada", 0, 6, 2) == 0){



		switch (opcion) {
		case 0:
			printf("Modificacion Cancelada\n");
			break;
		case 1:
			if(utn_get_name(jugador.nombre, MAX_CHARS, "\nIngrese nombre del Jugador: ", "\nError! Ingrese un nombre", 2) == 0){

						strncpy(jugador.nombre, strlwr(jugador.nombre), MAX_CHARS);
						jugador.nombre[0] = toupper(jugador.nombre[0]);
						for(i=0; i<size; i++){
							if(jugador.nombre[i] == ' '){
								jugador.nombre[i + 1] = toupper(jugador.nombre[i + 1]);
							}
						}
			}
			break;
		case 2:
			if(utn_get_name(jugador.posicion, MAX_CHARS, "\nIngrese la posicion del Jugador: ", "\nError!", 2) == 0){

				strncpy(jugador.posicion, strlwr(jugador.posicion), MAX_CHARS);
				jugador.posicion[0] = toupper(jugador.posicion[0]);
				for(i=0; i<size; i++){
					if(jugador.posicion[i] == ' '){
						jugador.posicion[i + 1] = toupper(jugador.posicion[i + 1]);
					}
				}
			}
			break;

		case 3:
			utn_getNumero(&jugador.numeroCamiseta, "\nIngrese numero de camiseta.", "\nError! Ingrese un numero\n", 1, 99, 2);
			break;

		case 4:
			//MODIFICAR CONFEDERACION
			if(Confederacion_imprimirConfederaciones(arrayConfederacion, limitConfederacion) == 0){
				utn_getNumero(&jugador.idConfederacion, "\nIngrese el ID de la confederacion\n", "Error. Ingrese un numero\n", 1, 6, 2);
			}
			break;

		case 5:
			utn_getNumeroFlotante(&jugador.salario, "Ingrese el salario del jugador: ", "\nError! Ingrese un numero: ", 10, 10000000, 2);
			break;

		case 6:
			utn_getNumero(&jugador.aniosContrato, "\nIngrese los anios de contrato.", "\nError! Ingrese un numero\n", 1, 20, 2);
			break;
		default:
			printf("Opcion ingresada invalida!\n\n");
			break;
		}
		}else{
			printf("\nError en la modificacion.\n");
		}
		return jugador;
}

/**
 * Busca Jugador por ID
 * @param arrayJugador
 * @param size
 * @return retorna 0 caso exitoso, o -1 en caso de Error
 */
int Jugador_buscarJugadorPorId(Jugador *arrayJugador, int size){
	int rtn = -1;
	int flag = 0;
	int i;
	int buscarID;

	if (size > 0) {

		Jugador_imprimirTodos(arrayJugador, size);

		//PEDIR UN ID
		if(utn_getNumero(&buscarID, "\nIngrese ID: ", "Error! ID incorrecto.\nVuelva  a intentarlo\n", 0, 100, 2) == 0){
			for (i = 0; i < size; i++) {
				if (arrayJugador[i].status == OCUPADO && arrayJugador[i].id == buscarID) {
					flag = 1;
					rtn = i; //retorno index del ID que estoy buscando
					break;

				}
			}
		}
		if (flag == 0) { //Si no encontre ID...
			rtn = -2;
		}

	}
	return rtn;
}