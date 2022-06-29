/*
 ============================================================================
 Name        : Tp1.c
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
#include "CALCULOS.h"
#include "RESULTADOS.h"

float getkilometros();
float getOpcionLatam();
float getOpcionAero();

int main(void) {

	setbuf(stdout, NULL);

	int opciones;

	/*
	 * Con estas varaiables compruebo si ingreso o hizo el cargado forzado de datos.
	 * Evito que entren a calcular y mostrar
	 */
	int ingresoKLM;
	int ingresoPRECIOS;
	int IngresarAcalculos;
	int calculos;

	float klm;
	float precioLatam;
	float precioAerolineas;

	float resultadoDebitoL;
	float resultadoDebitoAero;
	float resultadoCreditoL;
	float resultadoCreditoAero;
	float resultadoBitcoinL;
	float resultadoBitcoinAero;
	float resultadoPrecioUniL;
	float resultadoPrecioUniAero;
	float resultadoDiferenciaPrecios;

	float cargaKLM;
	float cargaPrecioLatam;
	float cargaPrecioAero;


	do{
		UTN_getNumero(&opciones,"\n----------Menu de vuelo----------"
								"\n1) Ingreso de kilómetros del vuelo"
								"\n2) Opciones de vuelos"
								"\n3) Calcular todos los costos"
								"\n4) Informar Resultados"
								"\n5) Carga forzada de datos"
								"\n6) SALIR"
								"\n---------------------------------------------"
								"\nEliga una opcion: ", "\nERROR ELIGA UNA OPCION VALIDA",1,6,5);
		switch(opciones){

			case 1:
				ingresoKLM = 1;
				klm = getkilometros();
				ingresoPRECIOS = 0;
				calculos = 0;
				break;
			case 2:
				if(ingresoKLM == 1){
					ingresoPRECIOS = 1;
					precioLatam = getOpcionLatam();
					precioAerolineas = getOpcionAero();
					IngresarAcalculos = 1;
				} else {
					printf("\n-INGRESE PRIMERO LOS KILOMETROS");
				}

				break;
			case 3:
				if(ingresoKLM == 1){
					if(ingresoPRECIOS == 1){
						if(IngresarAcalculos == 1){
							resultadoDebitoAero = debitoAerolineas(precioAerolineas);
							resultadoDebitoL = debitoLatam(precioLatam);
							resultadoCreditoAero = creditoAerolineas(precioAerolineas);
							resultadoCreditoL = creditoLatam(precioLatam);
							resultadoBitcoinAero = bitcoinAerolineas(precioAerolineas);
							resultadoBitcoinL = bitcoinLatam(precioLatam);
							resultadoPrecioUniAero = precioUnitarioAerolineas(klm,precioAerolineas);
							resultadoPrecioUniL = precioUnitarioLatam(klm,precioLatam);
							resultadoDiferenciaPrecios = diferenciaEntrePrecios(precioAerolineas, precioLatam);
							calculos = 1;
							printf("\n-----DATOS YA CALCULADOS-----");
						}
					} else {
						printf("\n-DEBE INGRESAR LOS PRECIOS");
					}

				} else {
					printf("\n-INGRESE PRIMERO LOS KILOMETROS");
				}
				break;
			case 4:
				if(ingresoKLM == 1){
					if(ingresoPRECIOS == 1){
						if(calculos == 1){
							showResultados(klm, precioAerolineas, precioLatam, resultadoDebitoAero, resultadoDebitoL, resultadoCreditoAero, resultadoCreditoL, resultadoBitcoinAero,
									resultadoBitcoinL, resultadoPrecioUniAero, resultadoPrecioUniL,resultadoDiferenciaPrecios);

						} else {
							printf("\n-PARA MOSTRAR LOS DATOS, PRIMERO DEBE CALCULAR");
						}
					} else {
						printf("\n-DEBE INGRESAR LOS PRECIOS");
					}

				} else {
					printf("\n-INGRESE PRIMERO LOS KILOMETROS");
				}


				break;
			case 5:

				ingresoKLM = 1;
				ingresoPRECIOS = 1;
				IngresarAcalculos = 1;
				calculos = 0;

				cargaKLM = 7090;
				cargaPrecioLatam = 162965;
				cargaPrecioAero = 159339;

				klm = cargaKLM;
				precioLatam = cargaPrecioLatam;
				precioAerolineas = cargaPrecioAero;

				printf("\n---CARGAR FORZADA DE DATOS REALIZADA---");
				break;
			default:
				return 0;
				break;

		}

	}while(opciones != 6);



	return 0;
}


float getkilometros(){

	float kilometros;

	UTN_getNumeroFlotante(&kilometros, "\n\n\n----------Menu de vuelo| INGRESO KILOMETROS----------"
									"\nIngrese los kilometros del vuelo: ","\nERROR AL INGRESAR LOS KILOMETROS", 0,50000,5);


	return kilometros;
}


float getOpcionLatam(){

	float precioL;

	UTN_getNumeroFlotante(&precioL, "\n\n\n\n----------Menu de vuelo| PRECIO AEROLINEAS----------"
									"\nIngrese el precio de aerolineas LATAM: ","\nERROR AL INGRESAR EL PRECIO", 0,1000000,5);

	return precioL;
}


float getOpcionAero(){

	float precioA;

	UTN_getNumeroFlotante(&precioA,"\nIngrese el precio de aerolineas: ","\nERROR AL INGRESAR EL PRECIO", 0,1000000,5);
	printf("\n\n\n---------------------------------------------");

	return precioA;
}
