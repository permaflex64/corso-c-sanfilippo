/*
 * tac.c
 *
 *(vedi https://www.geeksforgeeks.org/c/linked-list-in-c/)
 *  Created on: Mar 31, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esercizi.h"

struct line {
	char *s;
	struct line *next;
};

#define NOME_FILE "src/lez15/tac.c"

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
		struct line *l = malloc(sizeof(struct line));
		size_t linelen = strlen(buf);
		l->s = malloc(linelen + 1);
		for (size_t j = 0; j <= linelen; j++) {
			printf("%c", buf[j]);
			l->s[j] = buf[j];
		}
		l->next = head;
		head = l;
	}
	fclose(fp);

	while (head != NULL) {
		printf("%s", head->s);
		head = head->next;
	}

	return 0;
}
