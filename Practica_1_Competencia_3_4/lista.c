#include "lista.h"

Palabra* crear_Nodo(char *word) {

	Palabra *Nueva_Palabra = NULL;
	Nueva_Palabra = (Palabra*)malloc(sizeof(Palabra));
	Nueva_Palabra->palabra = (char *) malloc (MAX * sizeof (char));
	
	if(Nueva_Palabra != NULL){

		strcpy(Nueva_Palabra->palabra, word);
		Nueva_Palabra->sig = NULL;

	}
	
  return Nueva_Palabra;

}


void imprimir_Lista(Palabra *cabeza){
	Palabra *nodAux = cabeza;

	while(nodAux != NULL){

		printf("\t%s\n", nodAux->palabra);
		nodAux = nodAux->sig;

	}
}


void ordenar_Lista(Palabra *cabeza, int N_Palabras){

	Palabra *nodAux = cabeza;
	char aux[MAX];
	
	for(int i = 0; i < N_Palabras; i++){

		while(nodAux != NULL && nodAux->sig != NULL){

			if(strcmp(nodAux->palabra, nodAux->sig->palabra)>0){

				strcpy(aux, nodAux->palabra);
				strcpy(nodAux->palabra,nodAux->sig->palabra);
				strcpy(nodAux->sig->palabra,aux);

			}

			nodAux = nodAux->sig;
		}

		nodAux = cabeza;
	}
}


int escribir_Lista(Palabra *cabeza, FILE *archivoSalida){

	Palabra *nodAux = cabeza;

	while(nodAux != NULL){
		fprintf(archivoSalida, "%s\n", nodAux->palabra);
		nodAux = nodAux->sig;
	}
	return 0;
}


void agregar_Palabra(Palabra **cabeza, char *word){

	Palabra* Nueva_Palabra = NULL, *nodAux = *cabeza;
	Nueva_Palabra = crear_Nodo(word);

	if(*cabeza == NULL){

		Nueva_Palabra->sig = *cabeza;
		*cabeza = Nueva_Palabra;

	} 
	else {

		if( Nueva_Palabra != NULL){

			while(nodAux->sig != NULL){

				nodAux = nodAux->sig;

			}
			
			nodAux->sig = Nueva_Palabra;
		}
	}
}
