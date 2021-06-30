#include "lista.h"

int main(int argc, char *argv[]){
	
	Palabra *cabeza = NULL;
	FILE *Entrada, *Salida;
	char sAux[MAX]="";
	int N_Palabras = 0;
	
	Entrada = fopen(argv[1], "r");
	Salida = fopen(argv[2], "w");
	
	if (Entrada == NULL || Salida == NULL){
		
		if (argv[1]){

			if(argv[2]){

				printf("El archivo [%s] no existe\n", argv[1]);

			} 

			else{

				printf("Debe indicar el archivo de entrada y salida\n");

			}
		} 

		else{

			printf("Debe indicar el archivo de entrada y salida\n");

		}
	} 

	else{

		while (fscanf(Entrada, "%s", sAux) != EOF){
			agregar_Palabra(&cabeza, sAux);
			N_Palabras++;
		}

		fclose(Entrada);
		printf("\nPalabras en [%s]:\n", argv[1]);
		imprimir_Lista(cabeza);
		ordenar_Lista(cabeza, N_Palabras);

		if(escribir_Lista(cabeza, Salida) == 0){

			printf("\nLas palabras ordenadas se encuentran en el archivo [%s]\n", argv[2]);

		} 

		else {

			printf("\nNo se pudo escribir las palabras en el archivo [%s]\n", argv[2]);

		}

		fclose(Salida);
	}
	return 0;
}
