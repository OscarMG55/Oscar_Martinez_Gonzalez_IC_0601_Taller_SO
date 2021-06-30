#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 100
#define SA struct sockaddr

void sumar(int scket);

int main(int argc, char *argv[]){

	int scket, Aceptado, longCli, puerto;
	struct sockaddr_in direccion_Servidor, cli;
	
	if(argc !=2){

		printf("Debe indicar el puerto para la comunicación \n");
		exit(-1);
	}
	
	puerto = atoi(argv[1]);
	
	scket = socket(AF_INET, SOCK_STREAM, 0);
	if (scket == -1) {

		printf("No se pudo crear el socket...\n");
		exit(-1);
	} else {

		printf("Se creó el socket correctamente...\n");	
	}
		
	bzero(&direccion_Servidor, sizeof(direccion_Servidor));
	direccion_Servidor.sin_family = AF_INET;
	direccion_Servidor.sin_addr.s_addr = htonl(INADDR_ANY);
	direccion_Servidor.sin_port = htons(puerto);

	if ((bind(scket, (SA*)&direccion_Servidor, sizeof(direccion_Servidor))) != 0) {

		printf("El puerto [%i] no esta disponible:\n", puerto);
		exit(-1);
	}
	
	if ((listen(scket, 5)) != 0) {

		printf("La conexion fallo\n");
		exit(-1);
	} 

	else {

		printf("Servidor escuchando\n");
	}
		
	longCli = sizeof(cli);

	Aceptado = accept(scket, (SA*)&cli, &longCli);
	if (Aceptado < 0) {

		printf("No es un cliente valido\n");
		exit(0);
	} 

	else {

		printf("Conexion exitosa\n");
	}
	
	sumar(Aceptado);

	close(scket);
}

void sumar(int scket){

	char buff[MAX], num1[MAX], num2[MAX], res[MAX]={48};
	long tamNum1, tamNum2, tamMayor, tamRes;
	int j, k, a = 0, aux, N1, N2;
		
	read(scket, buff, sizeof(buff));
	strcpy(num1, buff);
	
	read(scket, buff, sizeof(buff));
	strcpy(num2, buff);
	
	tamNum1 = strlen(num1);
	tamNum2 = strlen(num2);
	
	if(tamNum1 >= tamNum2){
		tamMayor = tamNum1;
	} 

	else {
		
		tamMayor = tamNum2;
	}
	
	tamRes = tamMayor + 1;	
	
	j = tamNum1 - 1;
	k = tamNum2 - 1;

	for(int i = tamMayor - 1; i >= -1; i--, j--, k--){

		if (j >= 0){
			
			N1 = num1[j] - '0';
		} 

		else {
			
			N1 = 0;
		}
		
		if (k >= 0){
			
			N2 = num2[k] - '0';
		} 
		else 		{
			
			N2 = 0;
		}
		
		aux = N1 + N2 + a;
		printf("%i = %i + %i + %i\n", aux, N1, N2, a);
		
		if (aux >= 10){

			res[i+1] = (aux - 10) + '0';
			a = 1;
		} 

		else {

			res[i+1] = aux + '0';
			a = 0;
		}
	}
	
	strcpy(buff, res);
	write(scket, buff, sizeof(buff));

	printf("\nRespuesta enviada al cliente...\n");
}
