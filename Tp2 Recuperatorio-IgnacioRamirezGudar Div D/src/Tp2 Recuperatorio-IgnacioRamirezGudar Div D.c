/*
 ============================================================================
 Name        : Tp2.c
 Author      : Ignacio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input-UTN.h"
#include "ARRAYPASSENGER.h"

#define TAM_MAX_PASSENGER 2000


int banderaINIT = 0;

int getPassenger(Passenger ListPassenger[], int TAM_LISTA);
int modificPassenger(Passenger ListPassenger[], int TAM_LISTA);
int removePassengerID(Passenger ListPassenger[], int TAM_LISTA);
int listPassenger(Passenger ListPassenger[], int TAM_LISTA);

int main(void) {

	setbuf(stdout, NULL);

	Passenger ListPassenger[TAM_MAX_PASSENGER];

	if(banderaINIT == 0){
		initPassengers(ListPassenger, TAM_MAX_PASSENGER);
		banderaINIT = 1;
	}


	int opciones;

	do{

		UTN_getNumero(&opciones,"\n|--------------SISTEMA DE REGISTROS AEROLINEAS--------------|"
								"\n\t1) ALTAS PASAJERO"
								"\n\t2) MODIFICAR PASAJERO"
								"\n\t3) BAJA PASAJERO"
								"\n\t4) INFORMAR"
								"\n\t5) SALIR"
								"\n|-----------------------------------------------------------|"
								"\nELIGA UNA OPCION: ", "\nERROR...ELIGA UNA OPCION VALIDA",1,5,5);

		switch(opciones){
			case 1:
				getPassenger(ListPassenger,TAM_MAX_PASSENGER);
				break;
			case 2:
				modificPassenger(ListPassenger,TAM_MAX_PASSENGER);
				break;
			case 3:
				removePassengerID(ListPassenger,TAM_MAX_PASSENGER);
				break;
			case 4:
				listPassenger(ListPassenger,TAM_MAX_PASSENGER);
				break;
			default:
				return 0;
				break;
		}

	}while(opciones != 5);


	return 0;
}


int getPassenger(Passenger ListPassenger[], int TAM_LISTA){

	char nombre_passenger[51];
	char lastname_passenger[51];
	float price;
	int typePassenger;
	char destino[51];
	int statusFlight;

	printf("\n|--------------SISTEMA DE REGISTROS AEROLINEAS || ALTA PASAJERO--------------|");
	UTN_getString(nombre_passenger, 51, "\n- INGRESE NOMBRE DEL PASAJERO: ", "\n- ERROR...AL INGRESAR EL NOMBRE DEL PASAJERO: ", 5);
	UTN_getString(lastname_passenger, 51, "\n- INGRESE APELLIDO DEL PASAJERO: ", "\n- ERROR...AL INGRESAR EL APELLIDO DEL PASAJERO: ", 5);
	UTN_getNumeroFlotante(&price, "\n- INGRESE EL PRECIO DEL VUELO: ","\n- ERROR...AL INGRESAR EL PRECIO DEL VUELO: ", 1000, 1000000, 5);
	UTN_getNumero(&typePassenger, "\n|----- (1 - CLASE ALTA)----(2 - CLASE MEDIA)-----(3 - CLASE BAJA)-----|"
								"\n- INGRESE UNA OPCION: ","\n- ERROR...ELIGA UNA OPCION VALIDA: ", 1, 3, 5);
	UTN_getString(destino, 51, "\n- INGRESE EL DESTINO DEL PASAJERO: ", "\n- ERROR...AL INGRESAR EL DESTINO DEL PASAJERO: ", 5);
	UTN_getNumero(&statusFlight, "\n|----- (1 - EN VUELO)----(2 - ATERRIZO)-----(3 - EN DESENSO)-----(4 - CANCELADO)-----|"
								"\n- INGRESE UNA OPCION: ","\n- ERROR...ELIGA UNA OPCION VALIDA: ", 1, 4, 5);


	addPassenger(ListPassenger, TAM_LISTA, nombre_passenger, lastname_passenger, price, typePassenger, destino, statusFlight);

	return 0;
}

int modificPassenger(Passenger ListPassenger[], int TAM_LISTA){

	int ingresarID;
	int opciones;
	int findPassenger;

	printf("\n|--------------SISTEMA DE REGISTROS AEROLINEAS || MODIFICAR PASAJERO--------------|");
	UTN_getNumero(&ingresarID, "\n- INGRESE LA ID DEL PASAJERO A MODIFICAR: ", "\n -ERROR...ESA ID NO EXISTE: ", 0,2000,5);

	findPassenger = findPassengerById(ListPassenger, TAM_LISTA, ingresarID);

	if(findPassenger == 0){
		UTN_getNumero(&opciones,"\n||--------------------------------------------------------||"
								"\n\t    OPCIONES DE MODIFICACION"
								"\n<-------------------------------------------------------->"
								"\n\t\t 1- Modificar nombre del pasajero"
								"\n\t\t 2- Modificar apellido del pasajero"
								"\n\t\t 3- Modificar la clase del pasajero"
								"\n\t\t 4- Modificar el codigo de vuelo"
								"\n\t\t 5- CANCELAR"
								"\n<-------------------------------------------------------->"
								"\nEliga una opcion: ", "\nERROR...ELIGA UNA OPCION VALIDA: ", 1,5,5);
		changeDataPassengerById( ListPassenger,TAM_LISTA,ingresarID, opciones);
	} else{
		printf("\n-ERROR...NO SE ENCONTRO AL PASAJERO");
	}

	return 0;
}

int removePassengerID(Passenger ListPassenger[], int TAM_LISTA){

	int ingresarID;
	int remove;

	printf("\n|--------------SISTEMA DE REGISTROS AEROLINEAS || BAJAR USUARIO--------------|");
	UTN_getNumero(&ingresarID, "\n- INGRESE LA ID DEL PASAJERO A BAJAR: ", "\n -ERROR...ESA ID NO EXISTE: ", 0,2000,5);

	remove = removePassenger(ListPassenger, TAM_LISTA, ingresarID);

	if(remove == 0){

		printf("\n-USUARIO ELIMINADO");

	} else {

		printf("\n-ERROR... AL ELIMINAR ESTE USUARIO");

	}

	return 0;
}


int listPassenger(Passenger ListPassenger[], int TAM_LISTA){

	int opciones;

	UTN_getNumero(&opciones, "\n\t    MOSTRAR LISTA"
			"\n<-------------------------------------------------------->"
			"\n1- Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
			"\n2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
			"\n3- Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
			"\n4- CANCELAR"
			"\n<-------------------------------------------------------->"
			"\nEliga una opcion: ", "\n -ERROR...AL INGRESAR UNA OPCION: ", 1,5,5);

	printPassenger(ListPassenger, TAM_LISTA, opciones);

	return 0;
}
