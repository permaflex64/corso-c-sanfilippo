/*
 * loop.c
 *
 *  Created on: Mar 16, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

void ciclo_infinito() {
	l10: printf("ciao\n");
	l20: goto l10;
}

static void traccia(int start,int end){
	printf("%p %p\n",&start,&end);
}

//Ricorsione
void conta(int start,int end){
	traccia(start,end);
	if(start > end) return;
	printf("%d§\n",start);
	conta(++start,end);
}

void _goto() {
	int i = 0;

	again: printf("%d\n", i);
	i++;
	if (i < 10)
		goto again;

	i = 0;
	while (i<10) {
		printf("%d#\n", i);
		i++;
	}

	i = 0;

	loop:
	if(i >= 10) goto next;
		printf("%d@\n", i);
		i++;
		goto loop;

		next:

	i = 0;

	loop2:
	if(i < 10) goto enter_loop;
		goto next2;
		enter_loop:
		printf("%d-\n", i);
		i++;
		goto loop2;

		next2:
;//
}

int lez6_loop_main() {
	_goto();
//	ciclo_infinito();
	conta(0,9);
	return 0;
}
