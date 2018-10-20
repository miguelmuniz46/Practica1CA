#pragma once
#include "plaza.h"
#include "threads_coche.h"


class Aparcamiento {
	Plaza_t *aparcamiento;
public:
	Aparcamiento();
	void ocuparPlaza(Thread_coche_t *coche);
	void liberarPlaza(Thread_coche_t *coche);
	bool isOcupado(Plaza_t plaza);
	bool plazasLibres();
	void imprimirAparcamiento();
	void imprimirCochesEsperando(Thread_coche_t *coches, int num_coches);
};
