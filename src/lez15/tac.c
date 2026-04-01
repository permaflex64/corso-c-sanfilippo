/*
 * tac.c
 *
 *  Created on: Mar 31, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

struct line {
	char *s;
	struct line *next;
};

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
	printf("%s\n", argv[0]);
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("File does not exist\n");
		return 1;
	}

	char buf[1024];
	struct line *head = NULL;
	while (fgets(buf, sizeof(buf), fp) != NULL) {
//		printf("%s\n",buf);
		struct line *l = malloc(sizeof(struct line));
		size_t linelen = strlen(buf);
//		printf("%d\n",linelen);
		l->s = malloc(linelen+1);
		for (int j = 0; j <= linelen; j++) {
			printf("%c", buf[j]);
			l->s[j] = buf[j];
		}
		l->next = head;
		head = l;
	}
	fclose(fp);

	while(head != NULL){
		printf("%s", head->s);
		head = head->next;
	}

	return 0;
}
