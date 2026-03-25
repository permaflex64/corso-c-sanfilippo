/*
 * pls.c
 *
 * Prefixed Length String
 *
 *  Created on: Mar 25, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

static void ps_init(char *s, char *init, int len) {
	unsigned char *lenptr = (unsigned char*) s;
	*lenptr = len;
	for (int j = 0; j < len; ++j) {
		s[j + 1] = init[j];
	}
}

/* Display the strin 's' on the screen. */
static void ps_print(char *s) {
	unsigned char *lenptr = (unsigned char*) s;
	for (int j = 0; j < *lenptr; ++j) {
		putchar(s[j + 1]);
	}

}

int pls_main() {
	printf("lezione 12\n");
	char buf[256];
	ps_init(buf, "Hello World", 11);
	printf("%s %s\n", buf,
			"la stringa e' stata riempita a partire dalla seconda posizione di buf");
	ps_print(buf);
	ps_print(buf);

	return 0;
}
