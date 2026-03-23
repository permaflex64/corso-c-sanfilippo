/*
 * ptr1.c
 *
 *  Created on: Mar 22, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

static void incr(int *p) {
	printf("Before incr: %d\n", *p);
	p[0] = p[0] + 1;
}

//static void puntatore_e_deferenziazione() {
//}

static void uso_di_incr() {
	int x = 15;

	printf("x was %d\n", x);
	incr(&x);
	printf("x now is %d\n", x);
}

int lez10_main() {
	uso_di_incr();
	return 0;
}
