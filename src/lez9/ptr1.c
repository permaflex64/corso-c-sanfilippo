/*
 * ptr1.c
 *
 *  Created on: Mar 22, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

static void incr(int *p) {
	*p = *p + 1;
//	p[0] = p[0] + 1;
}

static void puntatore_e_deferenziazione() {

	int x = 5;
	int *y = NULL;
	printf("%d\n", x);
	printf("%p\n", y);
	y = &x;
	printf("x is stored at the address %p\n", y);
	*y = 10;
	printf("x now is %d\n", x);
	printf("*y now is %d\n", *y); //deferenziazione
	printf("x now is %d\n", x);
}

static void uso_di_incr() {

	int x = 5;
	int *y = NULL;

	printf("x was %d\n", x);
	y = &x;
	incr(y);
	printf("x now is %d\n", x);
	incr(&x);
	printf("x now is %d\n", x);

}

int lez9_main() {
//	puntatore_e_deferenziazione();
	uso_di_incr();
	return 0;
}
