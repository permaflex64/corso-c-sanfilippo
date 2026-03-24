/*
 * ptr2.c
 *
 *  Created on: Mar 24, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

static void printstr(char *p, char check) {
	while (*p != check) {
		putchar(p[0]);
		p++;
	}
	printf("\n");
}

static void printstr2(char *p){
	while (*p) {
		putchar(*p);
		p++;
	}
	printf("\n");
}

static void test_printscr() {
	char mystr[] = "AABBCCDDEE.FF";
	char *p = mystr;
	char *origin_p = p;
	printf("At the beginning p is %lu  %p\n", (unsigned long) p, p);
	printstr(p, '.');
	printstr(mystr, '.');
	printstr(mystr + 3, '.');
	printf("At the end p is %p\n", p);

}

int lez11_main() {
//	test_printscr();
	char str[] = "aabb";
	short *s = (short*) str;
	printf("%d %d\n%c %c\nsize of short is %zu\n", s[0], s[1], s[0], s[1],
			sizeof(short));

	char str2[] = { 1, 1, 2, 2 };
	short *s2 = (short*) str2;
	printf("%d %d\n%c %c\nsize of short is %zu\n", s2[0], s2[1], s2[0], s2[1],
			sizeof(short));

	char str3[] = "Hello0000123";
	char *p = str3;
	while (*p) {
//		putchar(*p);
//		printf("%d",*p);
		printf("%c",*p);
		p++;
	}
	printf("\n");

//	printstr2(*p);

	char str4[] = "Hello\0000000123";
	p = str4;
	printstr2(p);

	char str5[] = "\017Hello00\0000000123";
	p = str5;
	printf("My string len is %d\n",p[0]);
	int len = *p++;
	for (int j = 0; j < len; ++j) {
		putchar(p[j]);
	}
	printf("\n");
	return 0;

}
