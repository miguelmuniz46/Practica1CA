#include "aparcamiento.h"
#include "threads_coche.h"


Aparcamiento::Aparcamiento() {
	aparcamiento = (Plaza_t *)malloc(sizeof(Plaza_t)*PLAZAS);

	for (int i = 0; i < PLAZAS; i++) {
		aparcamiento[i].ocupado = false;
		aparcamiento[i].numeroPlaza = i + 1;
		aparcamiento[i].thread_Id_coche = NULL;
	}
}

void Aparcamiento::ocuparPlaza(Thread_coche_t *coche) {

	for (int i = 0; i < PLAZAS; i++) {
		if (!isOcupado(aparcamiento[i])) {
			aparcamiento[i].ocupado = true;
			aparcamiento[i].thread_Id_coche = coche->thread_Id;
			strcpy(coche->estado, "Aparcado");
			return;
		}
	}
}

void Aparcamiento::liberarPlaza(Thread_coche_t *coche) {
	for (int i = 0; i < PLAZAS; i++) {
		if (aparcamiento[i].thread_Id_coche == coche->thread_Id) {
			aparcamiento[i].ocupado = false;
			aparcamiento[i].thread_Id_coche = NULL;
			strcpy(coche->estado, "Ocioso");
		}
	}
}

bool Aparcamiento::isOcupado(Plaza_t plaza) {
	if (plaza.ocupado) {
		return true;
	}

	return false;
}

bool Aparcamiento::plazasLibres() {
	for (int i = 0; i < PLAZAS; i++) {
		if (!aparcamiento[i].ocupado) {
			return true;
		}
	}

	return false;
}


void Aparcamiento::imprimirAparcamiento() {
	for (int i = 0; i < PLAZAS; i++) {
		printf("Plaza: %d Coche: %d \n", aparcamiento[i].numeroPlaza, aparcamiento[i].thread_Id_coche);
	}
}

void Aparcamiento::imprimirCochesEsperando(Thread_coche_t * coches, int num_coches) {
	for (int i = 0; i < num_coches; i++) {
		if (coches[i].estado == "Esperando") {
			printf("Coche: %d Estado: %s \n", coches[i].thread_Id, coches[i].estado);
		}
	}
}