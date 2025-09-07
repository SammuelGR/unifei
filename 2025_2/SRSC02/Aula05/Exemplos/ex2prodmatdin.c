/*
 * ex2prodmatdin.c
 *
 *  Created on: 6 de set de 2021
 *      Author: minoru
 * Multiplicação de matrizes simples com
 * Alocação dinâmica
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int main( int argc, char **argv )
{
	float **a, **b;
	float **c;  // Matriz resultante
	int i, j, k;
	clock_t hora1, hora2;

	// alocação das matrizes

	a = ( float ** )malloc( sizeof( float * )*MAX );
	b = ( float ** )malloc( sizeof( float * )*MAX );
	c = ( float ** )malloc( sizeof( float * )*MAX );

	for( i = 0; i < MAX; i++ )
	{
		a[ i ] = ( float * )malloc( sizeof( float )*MAX );
		b[ i ] = ( float * )malloc( sizeof( float )*MAX );
		c[ i ] = ( float * )malloc( sizeof( float )*MAX );
	}

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


	// Multiplicação de matrizes

	hora1 = clock();
	for( i = 0; i < MAX; i++ )
	{
		for( j = 0; j < MAX; j++ )
		{
			c[ i ][ j ] = 0.0;
			for( k = 0; k < MAX; k++ )
			{
				c[ i ][ j ] = c[ i ][ j ] + a[ i ][ k ] * b[ k ][ j ];
			}
		}
	}
	hora2 = clock();
	printf( "\n%lf segundos\n", ((float)( hora2 - hora1 ))/CLOCKS_PER_SEC );

	// Liberando a memória alocada

	for( i = 0; i < MAX; i++ )
	{
		free( a[ i ] );
		free( b[ i ] );
		free( c[ i ] );
	}

	free( a );
	free( b );
	free( c );

}
