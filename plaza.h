#pragma once


#include <stdio.h>
#include <stdlib.h>
#define PLAZAS 10

typedef struct Plaza_t {
	bool ocupado;
	int numeroPlaza;
	int thread_Id_coche;
}Plaza_t;
