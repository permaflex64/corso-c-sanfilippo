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
struct fract {
	int num;
	int den;
};

/*Create a new fraction, setting num and den as the numerator
 * and denominator of the fraction.
 */
static struct fract create_fraction(int num, int den) {
	struct fract f;
	f.num = num;
	f.den = den;
	return f;
}

/* Simplify the provided fraction.*/
static void simplify_fraction(struct fract *f) {
	for (int d = 2; d <= f->num && d <= f->den; d++) {
		if (f->num % d == 0 && f->den % d == 0) {
			f->num /= d;
			f->den /= d;
		}
	}
}

static void print_fraction(struct fract *f) {
	printf("%d/%d\n", f->num, f->den);
}

static void fraction_completo_con_struct() {
	struct fract f1 = create_fraction(10, 20);
	struct fract f2 = create_fraction(3, 4);
	simplify_fraction(&f1);
	print_fraction(&f1);
	simplify_fraction(&f2);
	print_fraction(&f2);
}

int struct2_main() {
	fraction_completo_con_struct();

	return 0;
}

