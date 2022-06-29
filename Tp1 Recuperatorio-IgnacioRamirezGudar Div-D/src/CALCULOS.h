/*
 * CALCULOS.h
 *
 *  Created on: 28 jun. 2022
 *      Author: ignac
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include <stdio.h>
#include <stdlib.h>

float debitoAerolineas(float precioAerolineas);
float debitoLatam(float precioLatam);
float creditoAerolineas(float precioAerolineas);
float creditoLatam(float precioLatam);
float bitcoinAerolineas( float precioAerolineas);
float bitcoinLatam(float precioLatam);
float precioUnitarioAerolineas(float kilometros,float precioAerolineas);
float precioUnitarioLatam(float kilometros,float precioLatam);
float diferenciaEntrePrecios(float precioAerolineas, float precioLatam);

#endif /* CALCULOS_H_ */
