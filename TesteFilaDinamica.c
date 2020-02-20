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

// Bibliotecas
#include <stdio.h> // Para scanf, printf, fgets, gets
#include <string.h> // Para strcpy
#include <stdlib.h> // Para exit e malloc
#include <stdio_ext.h> // Para o __fflush
#include <stdbool.h> // Para o bool
#include <locale.h> // Para config. idioma local
#include "FilaDinamica.c"


int main( void ){
	setlocale(LC_ALL, "Portuguese");
	
	/*
	 * Para melhor utilização, add nesse programa um menu para 
	 * informar ao usuário as opções que o programa implementa. 
	 * Desenvolva casos de teste para cada função do programa.
	 */

	// Variáveis
	Fila *fila;
    NO item;
	int op, inicio;

	// Menu
	do{
		printf("-----------------------------------------------------------------\n");
        printf("Escolha uma opção: \n");
        printf("1 - Criar Fila (create);\n");
        printf("2 - Enfileirar (enqueue);\n");
        printf("3 - Desenfileirar (dequeue);\n");
        printf("4 - Ver início da fila (front);\n");
        printf("5 - Ver elementos (display);\n");
        printf("0 - Sair.\n");
        printf("-----------------------------------------------------------------\n");
        printf("Sua escolha: ");
        scanf("%d", &op);

        system("clear"); // No windows use cls no lugar de clear
        
        switch ( op )
        {
            case 1:
                fila = create( fila );
                break;
    
            case 2:
            	if(fila != NULL ){
            		printf( "Valor a ser enfileirado: " ); scanf( "%d", &item.dado );
                	if( enqueue( fila, item.dado ) )
                		printf( "Enfileirado com sucesso!\n" );
                	else
                		printf( "Erro ao enfileirar!\n" );
            	}
            	else
            		printf( "Crie a fila antes...\n" );
                break;
            
            case 3:
            	if(fila != NULL )
                	if( dequeue( fila ) )
                		printf( "Desenfileirado com sucesso!\n" );
                	else
                		printf( "Erro ao desenfileirar!\n" );
                else
            		printf( "Crie a fila antes...\n" );
                break;
            
            case 4:
                if(fila != NULL ){
                    inicio = front( fila );
                    if( inicio == EMPTY ) 
                        printf( "Pilha vazia.\n" );
                    else
                        printf( "Início da fila: %d\n", inicio );
                }
                else
                    printf( "Crie a fila antes...\n" );
                break;
            
            case 5:
                if(fila != NULL )
                    display(fila);
                else
                    printf( "Crie a fila antes...\n" );
                break;

            case 0:
            	exit(0);
           
            default:
                printf("Valor incorreto!\n");
                break;
        }
	} while( op != 0 );

	return 0;
}