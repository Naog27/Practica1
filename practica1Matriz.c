/* Práctica 1
   Porgrama#1: Secuencial
   Isabel Zuluaga
   Nathalia Ortega
*/

#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	//int **matrix = NULL; // se asgina el NULL en caso de valores erráticos
	int **matrix;
	int col,fil; // almacenan las cantidades de columnas y filas
	int x,y,i; // para el movimiento entre los arreglos

	printf("Ingresa Columnas: ");
	scanf("%d",&col);
	printf("Ingresa Filas: ");
	scanf("%d",&fil);
	matrix=(int **)malloc(fil*sizeof(int *));

	for (i = 0; i < fil; ++i)
	{
		matrix[i]=(int *)malloc (col*sizeof(int));
	}
	//int matrix[fil][col];
	
	//matrix = (int **)malloc(fil*sizeof(int*)); // se asigna memoria para las filas
	//if(matrix == NULL) { perror(""); } // se comprueba si no hay errores
	
	/*for (i = 1;i <= fil;i++) // se inicia un movimiento en el arreglo para asignar memoria para las columnas 
	{
		matrix[i] = (int*)malloc(col*sizeof(int)); // se asigna memoria mientras se mueve por el arreglo
		//if(matrix[i] == NULL) perror("Error: "); // se comprueba que no hay errores
	}*/
	
	for(y = 0;y < fil;y++) // esto nos movera por las filas
	{
		for(x = 0;x < col;x++) // esto nos movera por las columnas
		{
			printf("Valor [%d][%d] : ",y,x); // nos imprimira por que columna y fila (coordenada) estamos
			scanf("%d",&matrix[y][x]); // se asigna el valor a la matrix
		}
	}
	printf("Matriz Actual\n");
	printf("-------------\n");
	for(y = 0;y < fil;y++)
	{
		for(x = 0;x < col;x++)
		{
			printf("%d\t",matrix[y][x]); // se imprime los resultados para la visualización previa
		}
		printf("\n");// salto de linea 
	}	
	free(matrix); // se libera la memoria asignada a la matriz si asi se requiere
	//matrix = NULL; // se asigna NULL por metodos de seguridad 
	return 0;
}
