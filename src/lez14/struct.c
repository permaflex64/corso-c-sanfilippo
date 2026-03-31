/*
 * struct.c
 *
 *  Created on: Mar 30, 2026
 *      Author: navigazione
 *
 *	Esercitazione sulle strutture usando come esempio
 *	la gestione delle frazioni
 *
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

#if 0
//varie implementazioni di fract per ragionare sull'occupazione di memoria
//di una struct.
/*Internal layout
 * P = padding
 * +----+----+-----+
 * |cPPP|num | den |
 * +----+----+-----+
 * */
struct fract{
	unsigned char color;
	int num;
	int den;
};

/*Internal layout
 *
 * +----+----+----+
 * |num |den |abcd|
 * +----+----+----+
 * */
struct fract {
	int num;
	int den;
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
};

struct fract {
	unsigned char a;
	int num;
	unsigned char b;
	int den;
	unsigned char c;
	unsigned char d;
};
#endif

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

static void fraction_first_version() {
	/* |1111|2222|
	 *  f[0] f[1]
	 * */
	int *f = malloc(sizeof(int) * 2);
	set_fraction(f, 1, 2);
	print_fraction(f);
}

static void fraction_completo_senza_struct() {
	int *f1 = create_fraction(10, 20);
	int *f2 = create_fraction(3, 4);
	simplify_fraction(f1);
	print_fraction(f1);
	simplify_fraction(f2);
	print_fraction(f2);
}

static void intro_a_struct(){

	printf("%d\n", (int) sizeof(struct fract));

	/* puntatore, medesima area di memoria */
	struct fract a;
	struct fract *b = &a;
	a.num = 1;
	a.den = 2;
	printf("%d %d\n", a.num, a.den);
	b->num = 10;
	b->den = 20;
	printf("%d %d\n", a.num, a.den);

	/* copia, due distinte aree di memoria */
	struct fract c = a; //copia di a
	printf("a: %d %d\n", a.num, a.den);
	printf("c: %d %d\n", c.num, c.den);
	c.num = 100;
	c.den = 200;
	printf("c: %d %d\n", c.num, c.den);
}

int struct_main() {
//	fraction_first_version();
//	fraction_completo_senza_struct();
	intro_a_struct();

	return 0;
}

