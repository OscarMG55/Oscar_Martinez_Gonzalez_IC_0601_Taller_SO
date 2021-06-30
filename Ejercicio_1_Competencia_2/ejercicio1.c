#include <stdio.h>
#include <stdlib.h>

void ejercicio_2();

int main(){
		// EJERCICIO 1
	int x, *p;
	int y, *puntero;

	x = 10;

	p = &x;

	printf("\nEl valor del puntero p: %i",*p);

	*p= *p+1;

	printf("\nEl valor del segundo puntero p es: %i",*p);

	*p= *p+2;

	printf("\nEl valor del tercer puntero p es: %i",*p);

	y = 20;

	puntero = &y;

	printf("\nEl valor del puntero puntero es: %i\n",*puntero);

		//EJERCICIO 2

	ejercicio_2();
}
void ejercicio_2(){

	int arrayInt[5];
	int cont;

	for (cont=0; cont<5; cont++){
		arrayInt[cont] = cont;
	}

	int *punteroInt = arrayInt;
	int *punteroIntDos = arrayInt;

	printf("Contenido de arrayInt[0]: %i\n", arrayInt[0]);
	printf("Contenido de punteroInt[0]: %i\n", punteroInt[0]);
	printf("Contenido de arrayIntDos[0]: %i\n", punteroIntDos[0]);
	printf("Contenido de arrayInt[4]: %i\n", arrayInt[4]);
	printf("Contenido de punteroInt[4]: %i\n", *(punteroInt + 4));
	printf("Contenido de punteroIntDos[4]: %i\n", *(punteroIntDos + 4));
	printf("Contenido de punteroInt: \n");

	for(cont=0; cont<5; cont++){
		printf("punteroIntDos(%i): %i\n", cont, *(punteroIntDos + cont));
	}

	printf(" Contenido de punteroIntDos: \n");
	for(cont=0; cont<5; cont++){
		printf("punteroIntDos(%i): %i\n", cont, *(punteroIntDos + cont));
	}
	
}
