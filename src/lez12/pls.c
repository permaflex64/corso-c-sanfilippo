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

//static char* my_ps_create(char *s, int len) {
//	char *ps_string = malloc(len + 1);
//	*ps_string = len;  //(?)equivalente a lenptr[0] = len;
////	ps_string[0] = len;
//	for (int j = 0; j < len; ++j) {
//		ps_string[j + 1] = s[j];
//	}
//
//	return ps_string;
//}

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
 * +-+-----------\\\
 * |L|My string here
 * +-+------------\\\
 *
 * Where L is one unsigned byte stating the total length of the string.
 * Thus this strings are binary safe: zero bytes are permitted in the
 * middle.
 *
 * Warning this function don't check for buffer overflows.
 * */
static char* ps_create(char *init, int len) {
	char *s = malloc(1 + len);
	unsigned char *lenptr = (unsigned char*) s;
	*lenptr = len;
	printf("lenptr %s is in %p and s in %p\n",lenptr,lenptr,s);
	for (int j = 0; j < len; j++) {
		s[j + 1] = init[j];
	}
	s[len+1] = 0;
	return s;
}

/* Display the string 's' on the screen. */
static void ps_print(char *s) {
	unsigned char *lenptr = (unsigned char*) s;
	for (int j = 0; j < *lenptr; ++j) {
		putchar(s[j + 1]);
	}
	printf("\n");
}


/* Return the pointer to the null terminated C string embedded
 * inside our PS string 's'.
 */
static char *ps_getc(char *s){
	return s+1;
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
	printf("mystr in formato pascal %s\n",mystr);
	printf("%s\n",ps_getc(mystr));
	free(mystr);
	return 0;
}
