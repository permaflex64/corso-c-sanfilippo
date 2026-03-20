# Corso C - Salvatore Sanfilippo (antirez)
Esercizi e appunti realizzati seguendo la playlist di Salvatore Sanfilippo sul suo canale youtube.

## Struttura del progetto
* **src/**: Contiene le cartelle divise per lezione.
* **esercizi.h**: Header comune per i prototipi.
* **salvatore_sanfilippo.c**: Main "regista" del progetto.

## Come compilare
Per compilare il progetto manualmente da terminale:
`gcc salvatore_sanfilippo.c src/lez*/[nome_file].c -I. -o programma`