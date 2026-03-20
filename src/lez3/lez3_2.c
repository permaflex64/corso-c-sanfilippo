/*
 * lez3_2.c
 *
 *  Created on: Mar 12, 2026
 *      Author: navigazione
 */
#include <stdio.h>
#include <limits.h>
#include "esercizi.h"

int incr(int x) {
	x = x + 1;
	return x;
}

void passaggio_parametri_per_valore(){

	int a = 10;
	int b = 10;
	incr(a);
	b = incr(b);
	printf("%d %d\n",a , b);

}

void caos_totale() {
    float y = 1.234;
    int a = 10;
    // Scambiamo solo i segnaposto ma non l'ordine delle variabili
    printf("-Corretto: %f %d\n", y, a);
    printf("-Caos:    %d %f\n", y, a);
}
//porre attenzione ai warnings N.B. i warning si vedono solo dopo il clean & build
void errori_formattazione(){
	int a = 10;
	float y = 1.234;
	printf("%d %f\n",a, y);
	printf("%d %f\n",y, a);
}

//porre attenzione ai range dei tipi
void overflow(){
	char c1 = CHAR_MAX;
	char c2 = CHAR_MAX+1;
	unsigned char uc = UCHAR_MAX;
	short s1 = SHRT_MAX;
	short s2 = SHRT_MAX+1;
	int a = 10;
	unsigned int b = 20;
	float y = 1.234;
	printf("%d %f\n",s1,y);
	printf("%d %f\n",s2,y);
	printf("%d %d\n",c1,c2);
	printf("%d \n",uc);
	printf("%d \n",++uc);
	printf("%d \n",++uc);
	printf("%d \n",++uc);
	printf("%d \n",++uc);

}


int lez3_2_main() {
	passaggio_parametri_per_valore();
	errori_formattazione();
	caos_totale();
	overflow();
	return 0;
}

