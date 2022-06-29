/*
 * ARRAYPASSANGER.c
 *
 *  Created on: 28 jun. 2022
 *      Author: ignac
 */

#include "ARRAYPASSENGER.h"

#define LONGITUD_DESEADA 6

int rangoDelcodigo(int minimo, int maximo);
void generarFlyCode(int longitud, char *code);
int sortPassengers(Passenger ListPassenger[], int len);
int sortPassengersByCode (Passenger ListPassenger[], int len);
int contadorPasajeros (Passenger ListPassenger[], int len);
int contadorPrecioDePasajeros (Passenger ListPassenger[], int len);
int calcularPromedio (Passenger ListPassenger[], int len);

static int generateID = -1;
static int generateSpace = -1;

int GenerateId(){

	generateID++;

	return generateID;

}

int GenerateSpace(){

	generateSpace++;

	return generateSpace;

}


int initPassengers(Passenger ListPassenger[], int len){

	for(int i = 0; i <= len; i++){

		ListPassenger[i].isEmpty = 0;

	}

	return 0;
}


int addPassenger(Passenger ListPassenger[], int len, char name[],char lastName[],float price,int typePassenger, char destino[], int statusFlight){

	int posList;
	char flycodigo[LONGITUD_DESEADA + 1] = "";

	posList = GenerateSpace();

	ListPassenger[posList].id = GenerateId();
	strcpy(ListPassenger[posList].name,name);
	strcpy(ListPassenger[posList].lastname, lastName);
	ListPassenger[posList].price = price;
	ListPassenger[posList].typePassenger = typePassenger;
	strcpy(ListPassenger[posList].destino,destino);
	ListPassenger[posList].statusFlight = statusFlight;
	generarFlyCode(LONGITUD_DESEADA, flycodigo);
	strcpy(ListPassenger[posList].flycode, flycodigo);
	ListPassenger[posList].isEmpty = 1;

	return 0;
}


int removePassenger(Passenger ListPassenger[], int len, int id){

	int retorno;

	for(int i = 0; i <= len; i++){
		if( ListPassenger[i].isEmpty == 1){
			if(ListPassenger[i].id == id){
				ListPassenger[i].isEmpty = 0;
				retorno = 0;
			} else {
				retorno = 1;
			}
		}
	}

	return retorno;
}


int findPassengerById(Passenger ListPassenger[], int len,int id){

	int retorno;


	for(int i = 0; i <= len; i++){
		if( ListPassenger[i].isEmpty == 1){
			if(ListPassenger[i].id == id){
				retorno = 0;
			} else {
				retorno = 1;
			}
		}
	}

	return retorno;
}


int changeDataPassengerById(Passenger ListPassenger[], int len,int id, int opciones){

	char typePassenger[51];
	char changename[51];
	char changlastname[51];
	int changetypePassenger;
	char flycodigo[LONGITUD_DESEADA + 1] = "";

	for(int i = 0; i <= len ; i++){
		if(ListPassenger[i].id == id){
			if(ListPassenger[i].isEmpty == 1){
				switch(opciones){
					case 1:
						printf("\n\n\nAnterior nombre: %s ", ListPassenger[i].name);
						UTN_getString(changename, 51, "\n- INGRESE NUEVO NOMBRE DEL PASAJERO: ", "\n- ERROR...AL INGRESAR EL NOMBRE DEL PASAJERO: ", 5);
						strcpy(ListPassenger[i].name,changename);
						break;
					case 2:
						printf("\n\n\nAnterior apellido: %s ", ListPassenger[i].lastname);
						UTN_getString(changlastname, 51, "\n- INGRESE NUEVO APELLIDO DEL PASAJERO: ", "\n- ERROR...AL INGRESAR EL APELLIDO DEL PASAJERO: ", 5);
						strcpy(ListPassenger[i].lastname,changlastname);
						break;
					case 3:
						if(ListPassenger[i].typePassenger == 1){
							strcpy(typePassenger, "CLASE ALTA");
						}else{
							if(ListPassenger[i].typePassenger == 2){
								strcpy(typePassenger, "CLASE ECONOMICA");
							} else {
								if(ListPassenger[i].typePassenger == 3){
									strcpy(typePassenger, "CLASE BAJA");
								}
							}
						}
						printf("\nAnterio clase del pasajero: %s ", typePassenger);
						UTN_getNumero(&changetypePassenger, "\n|----- (1 - CLASE ALTA)----(2 - CLASE MEDIA)-----(3 - CLASE BAJA)-----|"
													"\n- INGRESE UNA OPCION: ","\n- ERROR...ELIGA UNA OPCION VALIDA: ", 1, 3, 5);
						ListPassenger[i].typePassenger = changetypePassenger;
						break;
					case 4:
						printf("\nAnterior codigo de vuelo: %s ", ListPassenger[i].flycode);
						generarFlyCode(LONGITUD_DESEADA, flycodigo);
						printf("\nEl nuevo codigo de vuelo es: %s", flycodigo);
						strcpy(ListPassenger[i].flycode, flycodigo);
						break;
					default:
						return 0;
						break;

				}
			}
		}
	}


	return 0;
}

int printPassenger(Passenger ListPassenger[], int length, int opciones){

	int promedioTotal;
	int totalPasajeros;
	int totalDePrecio;

	switch(opciones){

		case 1:
			sortPassengers(ListPassenger, length);
			break;
		case 2:
			totalPasajeros = contadorPasajeros(ListPassenger, length);
			totalDePrecio = contadorPrecioDePasajeros(ListPassenger, length);
			promedioTotal = calcularPromedio(ListPassenger, length);

			printf("\n TOTAL DE PASAJEROS: %d", totalPasajeros);
			printf("\n TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJEROS: %d", totalDePrecio);
			printf("\n PROMEDIO TOTAL: %d", promedioTotal);

			break;
		case 3:
			sortPassengersByCode(ListPassenger, length);
			break;
		default:
			return 0;
			break;

	}

	return 0;
}


int sortPassengers(Passenger ListPassenger[], int len){

	Passenger LastName;
	char typePassenger[51];
	char statusFlight[51];

	printf("\n\t\t     LISTA DE PASAJEROS");
	printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
	printf("\n|ID|\tNOMBRE\t|\tAPELLIDO\t|\tPRECIO\t\t|\tCODIGO DE VUELO\t|\tTIPO DE PASAJERO\t|\tESTADO DEL VUELO\t|\tDESTINO\t|");
	printf("\n|=======================================================================================================================================================|");


	for(int i = 0; i < len - 1; i++){
		for(int x = i + 1; x < len; x++){
			if(strcmp(ListPassenger[i].lastname, ListPassenger[x].lastname) > 0){
				LastName = ListPassenger[i];
				ListPassenger[i] = ListPassenger[x];
				ListPassenger[x] = LastName;
			}
			if(strcmp(ListPassenger[i].lastname, ListPassenger[x].lastname) == 0){
				if(ListPassenger[i].typePassenger > ListPassenger[x].typePassenger){
					LastName = ListPassenger[i];
					ListPassenger[i] = ListPassenger[x];
					ListPassenger[x] = LastName;
				}
			}
		}

		if(ListPassenger[i].isEmpty == 1){
			if(ListPassenger[i].statusFlight == 1){
				strcpy(statusFlight, "EN VUELO");
			}else{
				if(ListPassenger[i].statusFlight == 2){
					strcpy(statusFlight, "ATERRIZO");
				} else {
					if(ListPassenger[i].statusFlight == 3){
						strcpy(statusFlight, "EN DESENSO");
					} else {
						if(ListPassenger[i].statusFlight == 4){
							strcpy(statusFlight, "CANCELADO");
						}
					}
				}
			}
			if(ListPassenger[i].typePassenger == 1){
				strcpy(typePassenger, "CLASE ALTA");
			}else{
				if(ListPassenger[i].typePassenger == 2){
					strcpy(typePassenger, "CLASE ECONOMICA");
				} else {
					if(ListPassenger[i].typePassenger == 3){
						strcpy(typePassenger, "CLASE BAJA");
					}
				}
			}

			printf("\n|%d |\t%s\t|\t%s\t\t|\t%2.f\t\t|\t%s\t\t|\t%s\t\t|\t\t%s\t|\t%s\t|", ListPassenger[i].id, ListPassenger[i].name,ListPassenger[i].lastname,ListPassenger[i].price,ListPassenger[i].flycode,typePassenger,statusFlight,ListPassenger[i].destino);
			printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
		}

	}

	return 0;
}


int sortPassengersByCode (Passenger ListPassenger[], int len){


	Passenger auxFlycodeANDStatus;
	char typePassenger[51];
	char statusFlight[51];

	printf("\n\t\t     LISTA DE PASAJEROS");
	printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
	printf("\n|ID|\tNOMBRE\t|\tAPELLIDO\t|\tPRECIO\t\t|\tCODIGO DE VUELO\t|\tTIPO DE PASAJERO\t|\tESTADO DEL VUELO\t|\tDESTINO\t|");
	printf("\n|=======================================================================================================================================================|");


	for(int i = 0; i < len - 1; i++){
		for (int j = i + 1; j < len; j++){
			if (strcmp(ListPassenger[i].flycode, ListPassenger[j].flycode) > 0){
				auxFlycodeANDStatus = ListPassenger[i];
				ListPassenger[i] = ListPassenger[j];
				ListPassenger[j] = auxFlycodeANDStatus;
			}
			if (strcmp(ListPassenger[i].flycode, ListPassenger[j].flycode) == 0){
				if (ListPassenger[i].statusFlight > ListPassenger[j].statusFlight){
					auxFlycodeANDStatus = ListPassenger[i];
					ListPassenger[i] = ListPassenger[j];
					ListPassenger[j] = auxFlycodeANDStatus;
				}
			}
		}

		if(ListPassenger[i].isEmpty == 1){
					if(ListPassenger[i].statusFlight == 1){
						strcpy(statusFlight, "EN VUELO");
					}else{
						if(ListPassenger[i].statusFlight == 2){
							strcpy(statusFlight, "ATERRIZO");
						} else {
							if(ListPassenger[i].statusFlight == 3){
								strcpy(statusFlight, "EN DESENSO");
							} else {
								if(ListPassenger[i].statusFlight == 4){
									strcpy(statusFlight, "CANCELADO");
								}
							}
						}
					}
					if(ListPassenger[i].typePassenger == 1){
						strcpy(typePassenger, "CLASE ALTA");
					}else{
						if(ListPassenger[i].typePassenger == 2){
							strcpy(typePassenger, "CLASE ECONOMICA");
						} else {
							if(ListPassenger[i].typePassenger == 3){
								strcpy(typePassenger, "CLASE BAJA");
							}
						}
					}
					printf("\n|%d |\t%s\t|\t%s\t\t|\t%2.f\t\t|\t%s\t\t|\t%s\t\t|\t\t%s\t|\t%s\t|", ListPassenger[i].id, ListPassenger[i].name,ListPassenger[i].lastname,ListPassenger[i].price,ListPassenger[i].flycode,typePassenger,statusFlight,ListPassenger[i].destino);
					printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
		}

	}
	return 0;
}

/*
 * GENERO UN CODIGO DE VUELO ALEATORIO
 */

int rangoDelcodigo(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}


void generarFlyCode(int longitud, char *code){
    char letrasYnumeros[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    for (int i = 0; i < longitud; i++){
        int codigoDeVueloAleatorio = rangoDelcodigo(0, (int) strlen(letrasYnumeros) - 1);
        code[i] = letrasYnumeros[codigoDeVueloAleatorio];
    }
}

/*
 * CALCULOS TOTALES DE PROMEDIOS DE PASAJEROS Y PRECIOS
 *
 */

int contadorPasajeros (Passenger ListPassenger[], int len){
	int contPassenger;

	contPassenger = 0;

	for (int i = 0; i < len; i++)
	{
		if(ListPassenger[i].isEmpty == 1)
		{
			contPassenger++;
		}
	}

	return contPassenger;
}


int contadorPrecioDePasajeros (Passenger ListPassenger[], int len){
	int contPassengerPrecios;

	contPassengerPrecios = 0;

	for (int i = 0; i < len; i++)
	{
		if(ListPassenger[i].isEmpty == 1)
		{
			contPassengerPrecios = contPassengerPrecios + ListPassenger[i].price;
		}
	}

	return contPassengerPrecios;
}


int calcularPromedio (Passenger ListPassenger[], int len){

	int promedio;
	int totalPasajeros = contadorPasajeros(ListPassenger, len);
	int totalPrecioPasajero = contadorPrecioDePasajeros(ListPassenger, len);

	promedio = totalPrecioPasajero / totalPasajeros;

	return promedio;
}
