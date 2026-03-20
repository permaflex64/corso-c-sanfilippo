/*
 * if.c
 *
 *  Created on: Mar 15, 2026
 *      Author: navigazione
 */


#include <stdio.h>
#include "esercizi.h"

void _if(){

	int i = 5;

	if(i > 3){
		printf("i > 3\n");
	}else {
		printf("i <= 3\n");
	}

	if(i > 3)
		printf("i > 3\n");
	else
		printf("i <= 3\n");

	{
		int i = 3;
		printf("la i locale interna al blocco vale %d\n",i);
	}

	printf("la i esterna al blocco vale sempre %d\n",i);
}

void puntatori(){
	int i = 8;

	//contiguita' indirizzi e dimensione puntatore, la distanza corrisponde alla dimensione di 4 bytes
	{
		int i = 4;
		printf("i (%zu bytes) e' memorizzata ad %p\n", sizeof(i),&i);
	}


	{
		int j = 3;
		printf("i (%zu bytes) e' memorizzata ad %p\n", sizeof(j),&j);
	}

	printf("i (%zu bytes) e' memorizzata ad %p\n", sizeof(i),&i);

}

int lez6_if_main(){
	_if();
	puntatori();
	return 0;
}
