/*
 * RESULTADOS.c
 *
 *  Created on: 28 jun. 2022
 *      Author: ignac
 */


#include "RESULTADOS.h"

void showResultados(float kilometros,float aerolineasArgentinas,float latam, float totDebitoAerolineasArg, float totDebitoLatam, float totInteresAerolineasArg,
			float totInteresLatam, float totBitcoinAerolineasArg, float totBitcoinLatam, float precioUnitarioporKmAerolineasArg,
			float precioUnitarioporKmLatam, float diferenciaDePreciosDeVuelo){


		printf("\n\n\n\t\t<-----------------Informacion de los datos------------------>");
			printf("\n\t\t\tKMs Ingresados: %2.f"
				"\n\t\t\tPrecio Aerolineas: $%1.f"
				"\n\t\t\ta) Precio con tarjeta de debito: $%2.f"
				"\n\t\t\tb) Precio con tarjeta de credito: $%2.f"
				"\n\t\t\tc) Precio pagado can bitcoin: BTC %f"
				"\n\t\t\td) Mostrar precio unitario: $%2.f",kilometros,aerolineasArgentinas,totDebitoAerolineasArg,totInteresAerolineasArg,
				totBitcoinAerolineasArg, precioUnitarioporKmAerolineasArg);
		printf("\n\t\t\tPrecio Latam: $ %1.f"
				"\n\t\t\ta) Precio con tarjeta de debito: $%2.f"
				"\n\t\t\tb) Precio con tarjeta de credito: $%2.f"
				"\n\t\t\tc) Precio pagado can bitcoin: BTC %f"
				"\n\t\t\td) Mostrar precio unitario: $%2.f",latam,totDebitoLatam,totInteresLatam,totBitcoinLatam,
				precioUnitarioporKmLatam);

		printf("\n\t\t\tLa diferencia de precio es: $%2.f", diferenciaDePreciosDeVuelo);
		printf("\n\t\t<--------------------------------------------------------->");


}
