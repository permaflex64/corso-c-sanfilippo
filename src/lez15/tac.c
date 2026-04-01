/*
 * tac.c
 *
 *  Created on: Mar 31, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

#define NOME_FILE "src/lez15/tac.c"

#if 0
// argc è il numero di argomenti (il nome del programma è il primo, quindi argc >= 1)
// argv è un array di stringhe (puntatori a char)
static void gemini_configurazione_main(int argc, char **argv) {
	for (int i = 0; i < argc; ++i) {
		printf("%d:%s\n", i, argv[i]);
	}
}
#endif

int tac_main(int argc, char **argv) {
	printf("lezione 15\n");
	if (argc != 2) {
		printf("Missing file name\n");
		return 1;
	}
	printf("%s\n",argv[0]);
	FILE *fp = fopen(argv[1],"r");
	if (fp == NULL) {
		printf("File does not exist\n");
		return 1;
	}

	char buf[1024];
	while(fgets(buf,sizeof(buf),fp) != NULL){
		printf("%s\n",buf);
	}

	fclose(fp);
	return 0;
}
