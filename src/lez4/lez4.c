/*
 * lez4.c
 *
 *  Created on: Mar 13, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include "esercizi.h"

void clear(){
	printf("\033[H\033[2J\033[3J");
}


void scopri_dimensione(){
	char c = 1;// interno 8 bit, 1 byte
	short s = 2000; // 16 bit, 2 byte
	int x = 5; // 32 bit, 4 bytes
	long l = 10;
	uint64_t _uint = 10^6;
	printf("Hello World: int is %lu bytes \n", sizeof(x));
	printf("Hello World: int min: %d, int max %d\n",
			INT_MIN,INT_MAX);
	printf("Hello World: long is %lu bytes \n", sizeof(l));
	printf("Hello World: includendo stdint.h si puo usare uint64_t che e' %lu bytes \n", sizeof(_uint));
}

int lez4_main(){
	clear();
	scopri_dimensione();
	return 0;
}
