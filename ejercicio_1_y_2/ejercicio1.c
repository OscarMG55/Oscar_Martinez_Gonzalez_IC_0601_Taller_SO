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

	x+=1;

	printf("\nEl valor del segundo puntero p es: %i",*p);

	x+=2;

	printf("\nEl valor del tercer puntero p es: %i",*p);

	y = 20;

	puntero = &y;

	printf("\nEl valor del puntero puntero es: %i\n",*puntero);

	// EJERCICIO 2

	//ejercicio_2();

	return 0;
}
/*
void ejercicio_2(){

	int arrayInt[5] = {0,1,2,3,4};
	int contador = 0;

	for (contador=0;contador<=4;contador++){
		
	}


	int *punteroInt;
	punteroInt = &arrayInt;

	int *punteroIntDos;
	punteroIntDos = &arrayInt[contador];

	printf("Primer elemento del array: ");
	printf("Segundo elemento del array: ");
	printf("Tercer elemento del array: ");
	printf("Cuarto elemento del array: ");
	printf("Quinto elemento del array: %i",*punteroInt);

	return 0;
	
}*/