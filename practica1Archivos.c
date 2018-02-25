/* strtok example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[]){
	
	//char str[] = "3.0;4.2;5.0;2.5";
	char str[100];
	char * pch;
	int value;	
	char *filename;
	FILE *file;
	//printf ("Splitting string \"%s\" into tokens:\n",str);

	if(argc != 2){
		printf ("Error en los parametros, debe ejecutarse asi: %s notas.csv\n", argv[0]);	
		return -1;
	}
	filename = argv[1];
	file = fopen(filename, "rw");
	
	if(file == NULL){
		printf ("No pudo abrirse el fichero %s \n", filename);	
		return -1;
	}

	//Ya esta abierto el fichero
	int i=0;
	while (!feof(file))
	{
	
		fgets(str, 100,file);	
		
		puts(str);
		
		pch = strtok (str,",");
		while (pch!=NULL)
		{

			
			value = atoi(pch);
			//value++;			//Verificar que puedo operar con el numero 
			printf ("value: %d\n",value);
			pch = strtok (NULL, ",");
			
		}
		
	}
	
	
	fclose(file);
	return 0;
}