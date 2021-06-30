#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 100
#define SA struct sockaddr

void enviar_Numeros(int Socket, char *n1, char *n2);

int main(int argc, char *argv[]){

	int Socket, puerto;
	struct sockaddr_in direccion_Servidor;
	
	if(argc != 4){

		printf("Ingrese el puerto de escucha y los numeros que desea enviar \n");
		exit(-1);
	
	}
	
	puerto = atoi(argv[1]);
	
	Socket = socket(AF_INET, SOCK_STREAM, 0);
	
	if (Socket == -1) {

		printf("No se pudo crear el socket\n");
		exit(-1);
	} 
	
	else {
		
		printf("Se creo creectamente el socket\n");	
	}
		
	bzero(&direccion_Servidor, sizeof(direccion_Servidor));

	direccion_Servidor.sin_family = AF_INET;
	direccion_Servidor.sin_addr.s_addr = inet_addr("127.0.0.1");
	direccion_Servidor.sin_port = htons(puerto);

	if (connect(Socket, (SA*)&direccion_Servidor, sizeof(direccion_Servidor)) != 0) {
		
		printf("No se pudo conectar con el servidor\n");
		exit(0);
	} 

	else {
		
		printf("Conexion Exitosa\n");
	}

	enviar_Numeros(Socket, argv[2], argv[3]);

	close(Socket);
}

void enviar_Numeros(int Socket, char *n1, char *n2){
	
	char buff[MAX], res[MAX]={'0'}, num1[strlen(n1)], num2[strlen(n2)];
	
	strcpy(num1, n1);
	strcpy(num2, n2);

	strcpy(buff, num1);
	write(Socket, buff, sizeof(buff));
	
	strcpy(buff, num2);
        write(Socket, buff, sizeof(buff));
        
	read(Socket, buff, sizeof(buff));
	strcpy(res, buff);

	printf("El resultado de la resa es: \t%s\n",res);
}