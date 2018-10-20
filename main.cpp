#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#include  "aparcamiento.h"
#include "threads_coche.h"


int main(int argc, char **argv) {
	srand(time(NULL));

	Aparcamiento *aparcamiento;
	aparcamiento = new Aparcamiento();

	Thread_coche_t *threads_coches;
	threads_coches = inicializarCoches();

	int flag = 0;
	int libre = 0;
	int full = 0;
	double runtime;
	/*
#pragma omp parallel for num_threads(NUM_COCHES)
			for (int i = 0; i < NUM_COCHES; i++) {
				if (aparcamiento->plazasLibres()) {
					aparcamiento->ocuparPlaza(&threads_coches[i]);
				}
				else {
					threads_coches[i].estado = "Esperando";
				}
			}

		//for (int i = 0; i < 5; i++) {
		//	aparcamiento->liberarPlaza(&threads_coches[i]);
		//}

		aparcamiento->imprimirAparcamiento();
		printf("\n");
		aparcamiento->imprimirCochesEsperando(threads_coches, NUM_COCHES);
		printf("\n");
		system("pause");

*/
	while (true) {
#pragma omp parallel sections
		{
#pragma omp section
			{
				for (int i = 0; i < NUM_COCHES; i++) {
					if (aparcamiento->plazasLibres()) {
						aparcamiento->ocuparPlaza(&threads_coches[i]);
						libre = 1;
#pragma omp flush(libre)
						flag = 1;
#pragma omp flush(flag)
					}
					else {
						strcpy(threads_coches[i].estado, "Esperando");
					}
				}
			}

#pragma omp section
			{
				//for (int i = 0; i < NUM_COCHES; i++) {
				while (flag != 1)
				{
#pragma omp flush(flag)
				}
#pragma omp flush(libre)
				for (int i = 0; i < NUM_COCHES; i++) {
					aparcamiento->liberarPlaza(&threads_coches[i]);
				}
			}

		}

		aparcamiento->imprimirAparcamiento();
		printf("\n");
		aparcamiento->imprimirCochesEsperando(threads_coches, NUM_COCHES);
		printf("\n");
		system("pause");
	}
	getchar();
	return 0;
}