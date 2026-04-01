/*
 * tac.c
 *
 *  Created on: Mar 31, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

static void gemini_configurazione_main(int argc, char **argv) {

	// argc è il numero di argomenti (il nome del programma è il primo, quindi argc >= 1)
	// argv è un array di stringhe (puntatori a char)

	printf("Ho ricevuto %d argomenti.\n", argc - 1);

	if (argc > 1) {
		printf("Il primo argomento è: %s\n", argv[1]);
	}

}

//int tac_main(){
int tac_main(int argc, char **argv) {
	printf("lezione 15\n");
	gemini_configurazione_main(argc, argv);

	return 0;
}
