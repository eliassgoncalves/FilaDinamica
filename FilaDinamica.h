/*
*
* Computer Science Section
* Faculdades Doctum de Caratinga
* Caratinga, MG, Brazil
* Feb. 20, 2020
* author: Elias Goncalves
* email: falarcomelias@gmail.com
* Licensed under the Apache License, Version 2.0
*
*/

#ifndef _FILA_DINAMICA_H_INCLUDED_
#define _FILA_DINAMICA_H_INCLUDED_

#define EMPTY -1

// Definição da Fila
typedef struct fila_dinamica Fila;

// Elemento
typedef struct no{
	int dado;
	struct no *prox;
} NO;


// Protótipos da fila
Fila *create( );    	    // Criar fila
int get_size( Fila* );		// Tamanho da fila
bool is_empty( Fila* );     // Verificar se a fila está vazia
bool is_full( Fila* );      // Verificar se a fila está cheia
bool enqueue( Fila*, int );  // Enfilerar item
bool dequeue( Fila* );  	// Desenfilerar item
int front( Fila* );		    // Acessa o item no início da fila
void display( Fila* ); 		// Mostra elementos da fila

#endif