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

static void analisi_var_e_punt() {

	int x = 5;
	int *y = &x;
	int **z = &y;
	printf("x is stored in %p and y is stored in %p\n", y, z);
	printf("%d %d %d\n", (int) sizeof(x), (int) sizeof(y), (int) sizeof(z));

}

static void array_di_char() {
	char mystr[] = "Hello World";
	char *p = mystr;
	printf("%d\n",*p);//prima
	printf("a %p I can see: %s\n",mystr,mystr);//mystr e' sia puntatore che valore
	printf("%c\n", 65);
	printf("%c%c%c%c%c\n", p[0], p[1], p[2], p[3], p[4]);
	printf("%c%c%c%c%c\n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4));
//	printf("%c%c%c%c%c\n", *p, *(p++), *(p++), *(p++), *(p++));//?il puntatore punta alla o
	printf("%d\n",*p);//dopo
}

static void array_di_char_2() {
	char mystr[] = "AABBCCDDEEFF";
	short *p = (short*)mystr;
	short *old_p = p;
	printf("%d %p\n",*p,p);//,(int)sizeof(p));
	p++;
	printf("%d %p\n",*p,p);
	p = old_p;
	printf("%d %p\n",*p,p);

//	printf("%s",mystr);
//	*p = (short)'Z';
//	printf("%s  %c %p",mystr,*p,p);

	p +=4; //punta EE == 69,  69*(69*256) 17733
	printf("%d\n",*p);
	p = old_p;
	while(*p != 0){
		putchar(*p);
		p++;
	}

	printf("\n");

	char *p2 = mystr;
	char *old_p2 = p2;
	while(*p2 != 0){
		putchar(*p2);
		p2++;
	}

	printf("\n");
	printf("i puntatori hanno dimensioni p=%d p2=%d mentre i tipi  char=%d short=%d ,sono loro che deteminano il passo di avanzamento nello scorrere l'array mystr\n",
			(int)sizeof(p),(int)sizeof(p2), (int)sizeof(char), (int)sizeof(short));

	printf("At the end p2 is %p and old_p2 at the beginning is %p\n",p2,old_p2);

}


int lez10_main() {
//	uso_di_incr();
//	analisi_var_e_punt();
//	array_di_char();
	array_di_char_2();
	return 0;
}
