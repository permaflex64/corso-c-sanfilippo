/*
 * myclear.c
 *
 *  Created on: Mar 13, 2026
 *      Author: navigazione
 */

#include <stdio.h>

//per vedere myclear funzionante vai in ~/bin/myclear.c

void _clear(void){
	printf("\x1b[H");
}

int _main(void) {
	_clear();
	printf("Hello World\n");
	return 0;
}


