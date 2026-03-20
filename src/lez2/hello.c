#include <stdio.h>

#include "esercizi.h"

int sum(int a, int b){
	return a+b;
}

int sum2(){
	int a = 10;
	int b = 20;
	int c = a+b;
	return c;
}

void lez2_main(){

	printf("Ciao %d %d\n", sum(30,20), sum2());
}
