/*
 * albero.c
 *
 *  Created on: Mar 13, 2026
 *      Author: navigazione
 */

#include <stdio.h>
#include <stdlib.h>
#include "esercizi.h"

// Definizione del nodo
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Funzione per ottenere l'altezza
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Funzione per ottenere il massimo tra due interi
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Crea un nuovo nodo
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

// Rotazione a destra
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Rotazione a sinistra
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Ottieni il fattore di bilanciamento
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Inserimento nodo e ribilanciamento
struct Node* insert(struct Node* node, int key) {
    // 1. Normale inserimento BST
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Chiavi uguali non ammesse

    // 2. Aggiorna altezza di questo nodo antenato
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Ottieni il fattore di bilanciamento
    int balance = getBalance(node);

    // Casi di sbilanciamento:

    // Caso Sinistra-Sinistra
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso Destra-Destra
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso Sinistra-Destra
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso Destra-Sinistra
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Stampa Pre-order (Radice, Sinistra, Destra)
void preOrder(struct Node *root) {
    if(root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Funzione per visualizzare l'albero in modo grafico (ruotato di 90 gradi)
void display(struct Node *root, int space) {
    int COUNT = 10; // Distanza tra i livelli
    if (root == NULL) return;

    space += COUNT;

    // Elabora prima il figlio destro
    display(root->right, space);

    // Stampa il nodo corrente dopo lo spazio
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");
    printf("%d\n", root->key);

    // Elabora il figlio sinistro
    display(root->left, space);
}

int albero_main() {
	    struct Node *root = NULL;
	    int valori[] = {10, 20, 30, 40, 50, 25};

	    /* L'albero risultante dovrebbe essere:
	     * N.B. viene stampato colla root non in alto ma a sisnistra
	             30
	            /  \
	          20    40
	         /  \     \
	        10  25    50
	    */

	    for(int i = 0; i < 6; i++) {
	        printf("\n--- Step %d: Inserisco %d ---", i+1, valori[i]);
	        root = insert(root, valori[i]);
	        display(root, 0);
	        printf("\n--------------------------\n");
	    }

	    return 0;
}

int _albero_main() {
    struct Node *root = NULL;

    /* Costruzione dell'albero */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* L'albero risultante dovrebbe essere:
             30
            /  \
          20    40
         /  \     \
        10  25    50
    */

    printf("Attraversamento Pre-order dell'albero AVL: \n");
    preOrder(root);
    printf("\n");

    return 0;
}
