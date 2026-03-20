/*
 * loop.c
 *
 *  Created on: Mar 16, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"


static void separa(){
	printf("\n");
}

void switch_case(){
	int i = 10;
	//N.B. porre attenzione a non dimenticare il break
	switch (i) {
		case 5:printf("E' un cinque\n"); break;
		case 7:printf("E' un sette\n"); break;
		default:printf("Qualche altro numero\n"); break;
	}

	i=5;

	if (i == 5) {
		printf("E' un cinque\n");
	} else if ((i == 7)) {
		printf("E' un 7\n");
	} else {
		printf("Qualche altro numero\n");
	}


}

void ciclo_do_while(){
	do {
		//...
	} while (1);

	while(1){
		if(1) break;
	}

}



void cicli_while_for(){
	int i = 0;

	for(i = 0; i < 10; i++) printf("%d\n",i);

	i = 0;
	while(i<10) printf("%d\n",i++);
}

void cicli_for(){
	int i = 0;

	for(int i = 0; i < 10; i++) printf("%d&\n",i);
	separa();
	for(i = 0; i < 10; i++) printf("%d#\n",i);
	separa();
	i = 0;
	for(; i < 10; i++) printf("%d+\n",i);
	separa();
	i = 0;
	for(; ; i++){
		printf("%d@\n",i);
		if(i == 9) break;
	}
	separa();
}


void scorri_array(){
	int a[] = {1,5,8,4,9,0};//0 e' il terminatore
	int i;
	for (i = 0; a[i] != 0; i++) {
		if(a[i] == 8) break;
	}
	if (a[i] == 0) {
		printf("Non trovato\n");
	} else {
		printf("Trovato\n");
	}
}


//risparmia memoria stack
void conta_goto(int start,int end){
iterate:
	if(start > end) return;
	printf("%p  %d\n",&start,start++);
	goto iterate;
}

//Ricorsione
void conta_ricorsivo(int start,int end){
	if(start > end) return;
	printf("%p  %d\n",&start,start);
	conta_ricorsivo(++start,end);
}



int lez7_main(){
	printf("lezione 7\n");
	conta_ricorsivo(0,9);
	separa();
	conta_goto(0,9);
//	cicli_while_for();
	separa();
	cicli_for();
	scorri_array();
	switch_case();
	return 0;
}
