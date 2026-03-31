/*
 * struct2.c
 *
 *  Created on: Mar 31, 2026
 *      Author: navigazione
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "esercizi.h"

/*Internal layout
 *
 * +----+-----+
 * |num | dem |
 * +----+-----+
 * */
struct fract{
	int num;
	int den;
};


static void set_fraction(int *f, int num, int den) {
#if 0
	f[0] = num;
	f[1] = den;
#endif
	*f = num;
	f = f + 1;
	*f = den;
}

/*Create a new fraction, setting num and den as the numerator
 * and denominator of the fraction.
 * The function returns NULL on out of memory, otherwise the
 * fraction object is returned. */
static int* create_fraction(int num, int den) {
	int *f = malloc(sizeof(int) * 2);
	if (f == NULL)
		return NULL; // malloc error checking.
	f[0] = num;
	f[1] = den;
	return f;
}

/* Simplify the provided fraction.*/
static void simplify_fraction(int *f) {
	for (int d = 2; d <= f[0] && d <= f[1]; d++) {
		if (f[0] % d == 0 && f[1] % d == 0) {
			f[0] /= d;
			f[1] /= d;
		}
	}
}

static void print_fraction(int *f) {
	printf("%d/%d\n", f[0], f[1]);
}


static void fraction_completo_senza_struct() {
	int *f1 = create_fraction(10, 20);
	int *f2 = create_fraction(3, 4);
	simplify_fraction(f1);
	print_fraction(f1);
	simplify_fraction(f2);
	print_fraction(f2);
}


int struct2_main() {
	fraction_completo_senza_struct();

	return 0;
}

