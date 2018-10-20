#include "threads_coche.h"


Thread_coche_t * inicializarCoches() {
	Thread_coche_t *auxiliar;
	auxiliar = (Thread_coche_t *)malloc(sizeof(Thread_coche_t)*NUM_COCHES);

	for (int i = 0; i < NUM_COCHES; i++) {
		auxiliar[i].thread_Id = i + 1;
		auxiliar[i].estado = (char *)malloc(sizeof(char) * 20);
		strcpy(auxiliar[i].estado, "Ocioso");
	}

	return auxiliar;
}