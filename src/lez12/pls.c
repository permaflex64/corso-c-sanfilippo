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
	*lenptr = len;  //(?)equivalente a lenptr[0] = len;
	for (int j = 0; j < len; ++j) {
		s[j + 1] = init[j];
	}
}


//riprendere la 16:17 n.b la ps_create di antirez non ritorna ancora niente,
//creare varie ps_print per ogni versione con malloc e senza
static char* ps_create(char *s, int len){
	char *ps_string = malloc(256);
	*ps_string = len;  //(?)equivalente a lenptr[0] = len;
//	ps_string[0] = len;
	for (int j = 0; j < len; ++j) {
		ps_string[j + 1] = s[j];
	}

	return ps_string;
}
/* Display the string 's' on the screen. */
static void ps_print(char *s) {
	unsigned char *lenptr = (unsigned char*) s;
	for (int j = 0; j < *lenptr; ++j) {
		putchar(s[j + 1]);
	}

}

static void test_init_e_print() {
	char buf[256];
	ps_init(buf, "Hello World", 11);
	printf("%s %s %d:\n", buf,
			"la stringa e' stata riempita a partire dalla seconda posizione di buf, "
					"la prima posizione e' la lunghezza ", buf[0]);
	ps_print(buf);
	ps_print(buf);

}

int pls_main() {
	printf("lezione 12\n");
//	test_init_e_print();
	char *mystr = ps_create("Hello World", 11);
	ps_print(mystr);
	ps_print(mystr);

	return 0;
}
