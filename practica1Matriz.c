/* Práctica 1
   Porgrama#1: Secuencial
   Isabel Zuluaga
   Nathalia Ortega
*/

#include <stdio.h>
#include <stdlib.h>



void **suma(int ** m, int **n);
void imprimir(int ** m);
void data(int **m, int fila, int columna);
int col,fil,col2,fil2; 
int x,y; 

int main(void)
{
	int **matrix;
	int **segunda;
	
	
	int i,j;
	printf("Ingresa Filas de la matriz 1: ");
	scanf("%d",&fil);
	printf("Ingresa Columnas de la matriz 1: ");
	scanf("%d",&col);	
	matrix=(int **)malloc(fil*sizeof(int *));
	for (i = 0; i < fil; ++i)
	{
		matrix[i]=(int *)malloc (col*sizeof(int));
	}

	printf("\nIngresa Filas de la matriz 2: ");
	scanf("%d",&fil2);
	printf("Ingresa Columnas de la matriz 2: ");
	scanf("%d",&col2);	
	segunda=(int **)malloc(fil*sizeof(int *));
	for (i = 0; i < fil; ++i)
	{
		segunda[i]=(int *)malloc (col*sizeof(int));
	}
	printf("Para la primera matriz=\n");
	data(matrix, fil,col);
	printf("\nPara la segunda matriz=\n");
	data(segunda, fil2, col2);
	imprimir(matrix);
	imprimir(segunda);
	if(col==col2 & fil==fil2)
	{
		suma(matrix,segunda);
	}
	else
	{
		printf("\nNO es posible hacer sumas o restas, las matrices no tiene el mismo tamaño \n\n");
	}
	
	free(matrix);
	return 0;
}

void **suma(int ** m, int **n)
{
	int j;
	int **sum;
	sum=(int **)malloc(sizeof(m));
	for (j = 0; j < fil; ++j)
	{
		sum[j]=(int *)malloc (sizeof(m[j]));
	}
	
	for(x = 0;x < fil;x++)
	{
		for(y = 0;y < col;y++)
		{
			sum[x][y]=n[x][y]+m[x][y];
		}
		
	}	
	printf("\nSuma:");
	imprimir(sum);
}


void imprimir (int ** m)
{
		
	printf("\nMatriz de tamaño %d x %d =\n\n",fil,col);
	
	for(x = 0;x < fil;x++)
	{
		for(y = 0;y < col;y++)
		{
			printf("%d\t",m[x][y]); // se imprime los resultados para la visualización previa
		}
		printf("\n");// salto de linea 
	}	
}
void data (int ** m, int fila, int columna)
{	
		
	for(x = 0;x < fila;x++) // esto nos movera por las filas
	{
		for(y = 0;y < columna;y++) // esto nos movera por las columnas
		{
			printf("Valor [%d][%d] : ",x,y); // nos imprimira por que columna y fila (coordenada) estamos
			scanf("%d",&m[x][y]); // se asigna el valor a la matrix
		}
	}

}