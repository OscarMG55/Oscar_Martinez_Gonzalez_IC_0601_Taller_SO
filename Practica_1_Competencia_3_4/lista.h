#ifndef __LISTA_H
#define __LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

typedef struct nodo{
	char *palabra;
	struct nodo *sig;
} 

Palabra;

Palabra* crear_Nodo(char *word);
void imprimir_Lista(Palabra *cabeza);
void ordenar_Lista(Palabra *cabeza, int N_Palabras);
int escribir_Lista(Palabra *cabeza, FILE *archivoSalida);
void agregar_Palabra(Palabra **cabeza, char *word);

#endif
