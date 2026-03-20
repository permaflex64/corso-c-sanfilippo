/*
 * string.c
 *
 *  Created on: Mar 13, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include "esercizi.h"

void caratteri(){
	char c1 = 'a';
	char c2 = '^A'; //Verbatim

	printf("Hello World %d %d\n",c1,c2);
	printf("%s\n","Hello World");
	printf("[%c]\n",65);
	printf("[%c%c%c%c]\n",65,'x',67,68);
}

void array_e_stringhe(){
	int a[5] = {10,5,50,100,7};
	char str1[6] = {'h','e','l','l','o',0};//zero null terminator
	printf("%d %d %d\n",a[0],a[1],a[2]);
	printf("%s\n",str1);
}

void stringhe(){
	char str[6] = {'h','e','l','l','o',0};//zero null terminator
	int i = 0;
	while(str[i] != 0){
		printf("%c",str[i]);
		i++;
	}
	printf("\n");

	char str2[6] = "hello";
	char str3[] = "hello";
	str3[3] = 'X';
	str3[2] = '65';// 65 ottale corrispnde al char 5
	printf("Hello World: %s %s %s\n",str,str2,str3);
	str3[3]++;
	printf("Hello World: %s\n",str3);
}

void comportamento_anomalo(){
	char a = 10;
	char str[] = {'a','b'};// No! manca il terminatore 0
	char b = 20;
	printf("Hello World: %s\n",str);
}

int lez5_main(){
	caratteri();
	array_e_stringhe();
	stringhe();
	comportamento_anomalo();
	return 0;
}
