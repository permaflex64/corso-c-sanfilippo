/*
 * chat_gemini.c
 *
 *  Created on: Mar 22, 2026
 *      Author: navigazione
 */

/*ripartire da qui
 *
 * 3. Riassunto degli operatori
		Operatore	Nome	Cosa fa	Esempio
		&	Indirizzo di	Estrae l'indirizzo (sola lettura)	p = &x;
 	 	*	Deferenziazione	"Entra" nell'indirizzo per leggere/scrivere	*p = 10;
 *
 *
 * */

#include <stdio.h>
#include "esercizi.h"

static void assegnare_e_stampare_puntatore() {

	int n = 0;
	int *p_int = &n;
	char c = 'a';    // Una variabile char normale
	char *p_char = &c;    // p_char contiene l'indirizzo di c

	printf("Indirizzo attuale di p_int: %p\n", (void*) p_int);
	printf("Indirizzo + 1 di p_int:      %p\n", (void*) (p_int + 1));
	printf("Dimensione int:     %zu byte\n", sizeof(int));

	printf("Indirizzo attuale di p_char: %p\n", (void*) p_char);
	printf("Indirizzo + 1 di p_char:      %p\n", (void*) (p_char + 1));
	printf("Dimensione char:     %zu byte\n", sizeof(char));

}

static void riassunto() {

	char lettera = 'A';
	char *p = &lettera;

	printf("Valore originale: %c\n", *p);

	*p = 66; // Uso il codice ASCII
	printf("Dopo *p = 66, la lettera è: %c\n", *p);

	*p = *p + 1; // Incremento il valore numerico
	printf("Dopo l'incremento, la lettera è: %c\n", *p); // Diventerà 'C'

	//?
	printf("%p &p\n",&p);
	printf("%p p\n",p);
}

static void errore_e_punt_al_punt() {
	int x1 = 10;
	int *p1 = &x1;

//	&x=&p;
/*NO. Errore categorico.
Perché? &x è un numero costante che rappresenta la posizione fisica della variabile x
nella RAM del tuo PC.Non puoi cambiare l'indirizzo di una variabile una volta che
il programma è partito.È come se cercassi di cambiare le coordinate geografiche di
casa tua senza spostarela casa: la casa è lì, il suo "indirizzo" è una proprietà fissa.*/

	int x = 42;       // x si trova all'indirizzo 1000
	int *p = &x;      // p si trova all'indirizzo 2000, e dentro ha scritto "1000"
	int **pp = &p;    // pp si trova all'indirizzo 3000, e dentro ha scritto "2000"


}

int chat_gemini_main() {
//assegnare_e_stampare_puntatore();
//	separa();
riassunto();
//errore_e_punt_al_punt();
return 0;
}

