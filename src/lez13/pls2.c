/*
 * pls2.c
 *
 * Prefixed Length String
 *
 * Le stringhe in Pascal ed in C hanno formati diversi, queste
 * funzioni puntano all'interoperabilita
 *
 *  Created on: Mar 28, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "esercizi.h"

static void ps_init(char *s, char *init, int len) {
	unsigned char *lenptr = (unsigned char*) s;
	*lenptr = len;  //(?)equivalente a lenptr[0] = len;
	for (int j = 0; j < len; ++j) {
		s[j + 1] = init[j];
	}
}
/*
 * Initialize a prefixed length string withe the specified
 * string in 'init' of length 'len'
 *
 * The created strings have the following layout:
 *
 * +----+-----------\\\
 * |LLLL|My string here
 * +----+------------\\\
 *
 * Where L is one unsigned byte stating the total length of the string.
 * Thus this strings are binary safe: zero bytes are permitted in the
 * middle.
 *
 * Warning this function don't check for buffer overflows.
 * */
static char* ps_create(char *init, int len) {
	char *s = malloc(4 + len + 1);
	uint32_t *lenptr = (uint32_t*) s;
	*lenptr = len;

	s += 4;
	for (int j = 0; j < len; j++) {
		s[j] = init[j];  // We should use memcpy() here.
	}
	s[len] = 0;
	return s;
}

/* Display the string 's' on the screen. */
static void ps_print(char *s) {
	uint32_t *lenptr = (uint32_t*) (s - 4);
	for (int j = 0; j < *lenptr; j++) {
		putchar(s[j]);
	}
	printf("\n");
}

/* Free a previously created PS string. */
static void ps_free(char *s) {
	free(s - 4);
}

/* Return the length of the string in 0(1) time. */
static uint32_t ps_len(char *s) {
	uint32_t *lenptr = (uint32_t*) (s - 4);
	return *lenptr;
}


int pls2_main() {
	printf("lezione 13\n");
//	test_init_e_print();
	char *mystr = ps_create("Hello WorldHello WorldHello World", 33);
	ps_print(mystr);
	ps_print(mystr);
	printf("%s %d\n", mystr, (int)ps_len(mystr));
	ps_free(mystr);
	return 0;
}
