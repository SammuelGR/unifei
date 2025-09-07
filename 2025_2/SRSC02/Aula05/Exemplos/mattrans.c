/*
 * mattrans.c
 *
 *  Created on: 6 de set de 2021
 *      Author: minoru
 * Multiplicação de matrizes simples com
 * Alocação estática e o máximo de elementos possível
 * e uso da memória cache realizando a transposta da matriz b
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Valor de MAX máximo:
// int e float 835
// double 590

#define MAX 835

int main( int argc, char **argv )
{
	float a[ MAX ][ MAX ], b[ MAX ][ MAX ]; //, b1[ MAX ][ MAX ];
	float c[ MAX ][ MAX ];  // Matriz resultante
	float aux;
	int i, j, k;
	clock_t hora1, hora2;

	srand( time( NULL ) );

	// criando os elementos aleatoriamente

	for( i = 0; i < MAX; i++ )
	{
		for( j = 0; j < MAX; j++ )
		{
			a[ i ][ j ] = rand();
			b[ i ][ j ] = rand();
		}
	}

	// transposta da matriz b para b1

	for( i = 0; i < MAX; i++)
	{
		for( j = 0; j < MAX; j++ )
		{
			aux = b[ i ][ j ];
			b[ i ][ j ] = b[ j ][ i ];
			b[ j ][ i ] = aux;
		}
	}

	hora1 = clock();
	for( i = 0; i < MAX; i++ )
	{
		for( j = 0; j < MAX; j++ )
		{
			c[ i ][ j ] = 0.0;
			for( k = 0; k < MAX; k++ )
			{
				c[ i ][ j ] = c[ i ][ j ] + a[ i ][ k ] * b[ j ][ k ];
			}
		}
	}
	hora2 = clock();
	printf( "\n%lf segundos\n", ((float)( hora2 - hora1 ))/CLOCKS_PER_SEC );
}
