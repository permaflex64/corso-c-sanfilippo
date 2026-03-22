/*
 * chat_gemini.c
 *
 *  Created on: Mar 22, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

int chat_gemini_main() {
	int n = 0;
	int *p = &n;

	printf("Indirizzo attuale: %p\n", (void*) p);
	printf("Indirizzo + 1:      %p\n", (void*) (p + 1));
	printf("Dimensione int:     %zu byte\n", sizeof(int));
	return 0;
}

