/* Práctica 1
   Porgrama#1: Secuencial
   Isabel Zuluaga
   Nathalia Ortega
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void **suma(int ** m, int **n);
void **resta(int **m, int **n);
void **multi(int **m, int **n);
void imprimir(int ** m,int fila,int columna);
void data(int **m, int columna, int id, int fila);
int col,fil,col2,fil2; 
int x,y; 
FILE *file1, *file2;
char aux[21], aux2[21];


int main(int argc, char* argv[])
{
	char str[10];
	int str2[2], str3[2];
	char  *pch;
	int value;	
	char *name1, *name2;

	int **matrix;
	int **segunda;
	int i;

	if(argc < 2){
		printf ("Error en los parametros, debe ejecutarse asi: %s notas.csv\n", argv[0]);	
		return -1;
	}
	//Archivo 1
	name1 = argv[1];
	name2 = argv[2];

	file1 = fopen(name1, "r");	
	if(file1 == NULL){
		printf ("No pudo abrirse el fichero %s \n", name1);	
		return -1;
	}	
	//Del archivo1
	fgets(str, 10, file1);
	int k=0;
	pch=strtok (str,";");
	while (pch != NULL)
	{		
		value = atoi(pch);
		str2[k]=value;
		pch=strtok (NULL, ";");
		k++;
	}	
	//Tamaño matriz 2 con archivo1
	if(str2[0]<=10&str2[1]<=10)
	{
		fil=str2[0];	
		col=str2[1];
		matrix=(int **)malloc(fil*sizeof(int *));
		for (i = 0; i < fil; ++i)
		{
			matrix[i]=(int *)malloc (col*sizeof(int));
		}
	}
	else
	{
		printf("LA MATRIZ TIENE MÁS DE 10 FILAS O 10 COLUMNAS\n");
	}
	

	
	file2 = fopen(name2, "r");	
	if(file1 == NULL){
		printf ("No pudo abrirse el fichero %s \n", name2);	
		return -1;
	}	
	//Del archivo2
	fgets(str, 10, file2);	
	k=0;
	pch=strtok (str,";");
	while (pch != NULL)
	{		
		value = atoi(pch);
		str3[k]=value;
		pch=strtok (NULL, ";");
		k++;
	}	
	//Tamaño matriz 2 con archivo2
	if (str[3]<=10&str[3]<=10)
	{
		fil2=str3[0];	
		col2=str3[1];
		segunda=(int **)malloc(fil2*sizeof(int *));
		for (i = 0; i < fil; ++i)
		{
			segunda[i]=(int *)malloc (col2*sizeof(int));
		}
	}
	else
	{
		printf("LA MATRIZ TIENE MÁS DE 10 FILAS O 10 COLUMNAS\n");
	}



	data(matrix,col, 1,fil);
	data(segunda,col2, 2, fil2);
	imprimir(matrix,fil,col);
	imprimir(segunda,fil2,col2);

	

	if(col==col2 & fil==fil2)
	{
		suma(matrix,segunda);
		resta(matrix,segunda);
	}
	else
	{
		printf("\nNO es posible hacer sumas o restas, las matrices no tiene el mismo tamaño \n\n");
	}
	

	if(col==fil2 & fil==col2)
	{
		multi(matrix,segunda);
		
	}
	else
	{
		printf("\nNO es posible multiplicar las matrices \n\n");
	}

	free(matrix);
	free(segunda);
	fclose(file1);
	fclose(file2);
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
	imprimir(sum,fil,col);
	free(sum);
}

void **resta(int ** m, int **n)
{
	int j;
	int **res;
	res=(int **)malloc(sizeof(m));
	for (j = 0; j < fil; ++j)
	{
		res[j]=(int *)malloc (sizeof(m[j]));
	}
	
	for(x = 0;x < fil;x++)
	{
		for(y = 0;y < col;y++)
		{
			res[x][y]=n[x][y]-m[x][y];
		}
		
	}	
	printf("\nResta:");
	imprimir(res,fil,col);
	free(res);
}

void **multi(int ** m, int **n)
{
	int j,z;
	int tmp;
	int **mul;
	mul=(int **)malloc(fil*sizeof(int *));
	for (j = 0; j < fil; ++j)
	{
		mul[j]=(int *)malloc (col2*sizeof(int));
	}
	
	for(x = 0;x < fil;x++)
	{
		for(y = 0;y < col2;y++)
		{
			mul[x][y]=0;

			for (z = 0; z < col; z++)
			{
				
				mul[x][y]=(mul[x][y]+(m[x][z]*n[z][y]));
			}
		}
		
	}	
	printf("\nMUltiplicación:");
	imprimir(mul,fil,col2);
	free(mul);
}


void imprimir (int ** m, int fila, int columna)
{
		
	printf("\nMatriz de tamaño %d x %d =\n\n",fila,columna);
	
	for(x = 0;x < fila;x++)
	{
		for(y = 0;y < columna;y++)
		{
			printf("%d\t",m[x][y]); // se imprime los resultados para la visualización previa
		}
		printf("\n");// salto de linea 
	}	
}
void data (int ** m, int columna, int id, int fila)
{	

	char *cmp;
	int valor, f, c;
	if (id==1)
	{
		f=0;		
		valor=0;
		
		while(!feof(file1)&f<fila)
		{
			//if(j>0)
			//{
				fgets(aux, 21, file1);		
				cmp=strtok (aux,";");
				c=0;
				while (cmp != NULL&c<columna)
				{	
					valor = atoi(cmp);
					m[f][c]=valor;
					cmp=strtok (NULL, ";");
					c++;
				}
				f++;	
			//}					
		}
	}


	if (id==2)
	{		
		f=0;	
		valor=0;

		while(!feof(file2)&f<fila)
		{
			//if(j>0)
			//{
				fgets(aux2, 21, file2);		
				cmp=strtok (aux2,";");
				c=0;
				while (cmp != NULL&c<columna)
				{		
					valor = atoi(cmp);
					m[f][c]=valor;
					cmp=strtok (NULL, ";");
					c++;
				}	
			//}			
			f++;		
		}
	}
	

	
}