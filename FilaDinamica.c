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

#include "FilaDinamica.h"


// Fila
struct fila_dinamica{
	NO *inicio;
	NO *fim;
};


// Implementações das operações da fila
Fila *create( ){   // Criar fila
	Fila *fila = ( Fila* ) malloc( sizeof(Fila) );
	
	if( fila != NULL ){
		fila->inicio = fila->fim = NULL;
		printf( "Fila criada com sucesso...\n" );
		return fila;
	}

	printf( "Erro ao alocar memória...\n" );
	return NULL;
}

int get_size( Fila *fila ){
	if( fila == NULL )
		return 0;

	int cont = 0;
	NO *no = fila->inicio;

	while( no != NULL ){
		cont++;
		no = no->prox;
	} 

	return cont;
}

bool is_empty( Fila *fila ){  // Verificar se a fila está vazia
	printf( "Verificando se a fila está vazia...\n" );
	
	if( fila == NULL )
		return true;

	return ( fila->inicio == NULL );
}

bool is_full( Fila *fila ){   // Verificar se a fila está cheia
	printf( "Verificando se a fila está cheia...\n" );
	return false;
}


bool enqueue( Fila *fila, int dado ){ // Enfilerar item
	
	if( !is_full( fila ) ){
		NO *no = ( NO* ) malloc( sizeof(NO) );
		
		if( no == NULL )
			return false;
		
		no->dado = dado;
		no->prox = NULL;

		// Insere no início da fila quando ela está vazia
		if( fila->fim == NULL ) // fila vazia
			fila->inicio = no;
		
		// Insere no final da fila em todos os outros casos
		else
			fila->fim->prox = no;

		fila->fim = no;

		printf( "Enfilerando %d...\n", no->dado );
		return true;	
	}
	else
		printf( "Fila cheia!\n" );

	return false;
}


bool dequeue( Fila *fila ){  // Desenfileirar item

	if( fila == NULL )
		return false;

	if( !is_empty( fila ) ){

		NO *no = fila->inicio;
		fila->inicio = fila->inicio->prox;

		if( fila->inicio == NULL ) // Ficou vazia
			fila->fim = NULL;

		printf( "Desenfilerando %d...\n", no->dado );
		free( no );
		return true;
	}
	else
		printf( "Fila vazia!\n" );

	return false;
}

void display( Fila *fila ){
	if( fila == NULL )
		printf("Fila não foi criada!\n");;

	NO *no = fila->inicio;

	printf("Fila [");
	while( no != NULL ){
		printf("%d <- ", no->dado);
		no = no->prox;
	} 
	printf(" NULL]\n");
}

int front( Fila *fila ){
	printf( "Verificando início da fila...\n" );
	if( !is_empty( fila ) )
		return fila->inicio->dado; // se fila vazia retun é -1
	
	return EMPTY;
}