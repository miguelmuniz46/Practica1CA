#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_COCHES 20

typedef struct Thread_coche_t {
	int thread_Id;
	char *estado;
}Thread_coche_t;

Thread_coche_t *inicializarCoches();

