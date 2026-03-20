/*
 * lez3.c
 *
 *  Created on: Mar 11, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

//comportamento di variabili locali globali e statiche
int x = 0;


//locale
void incr_loc(){
	int x = 0;
	x = x + 1;
	printf("%d\n",x);
}

//locale statica = globale che vede solo la funzione,
void incr_loc2(){
	static int x = 0;
	x = x + 1;
	printf("%d\n",x);
}

//globale
void incr_glob(){
	x = x + 1;
	printf("%d\n",x);
}

int lez3_main(){

//	incr_loc();
//	incr_loc();
//	incr_loc();
//	incr_loc();

//	incr_glob();
//	incr_glob();
//	incr_glob();
//	incr_glob();

	incr_loc2();
	incr_loc2();
	incr_loc2();
	incr_loc2();

	return 0;
}


