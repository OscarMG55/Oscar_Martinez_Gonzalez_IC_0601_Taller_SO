#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_STRING				100
#define MAX_PROCESOS			100

#define UN_SEGUNDO				1
#define DOS_SEGUNDOS			2
#define TRES_SEGUNDOS			3
#define CUATRO_SEGUNDOS			4
	
#define ACTIVO 					1
#define NO_ACTIVO				0

int cont_procesos;

typedef struct PROCESS process;
typedef struct ARRAY_PROCESS array_procesos;

// Definición de la estructura PROCESS
struct PROCESS{
	int id;
	int delay;
	char nombrePROCESO[MAX_STRING];
	char accion[MAX_STRING];
	pthread_t hilo;
	int estado;
};

struct ARRAY_PROCESS{
	process proceso;
	int empty;
};

process *crear_Proceso(int _id, int _delay, char *_nombreProceso, pthread_t _hilo, char *_accion, int _estado);
void agregar_Proceso(array_procesos *_array, process _p);
void ejecutar_Procesos(array_procesos *_array);
void *thread_accion(void *arg);

array_procesos *crear_ArrayProcesos(void);
int main(int argc, char const *argv[]){
	pthread_t hilos[9];
	
	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", hilos[0], "Reproduciendo música...", ACTIVO);
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_1", hilos[1], "Abriendo YouTube...", NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_2", hilos[2], "Escribiendo texto en Word...", ACTIVO);
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_3", hilos[3], "Descargando archivo...", ACTIVO);
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_4", hilos[4], "subiendo archivo...", ACTIVO);
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_5", hilos[5], "Compilando programa...", NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_6", hilos[6], "Ejecutando programa...", ACTIVO);
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_7", hilos[7], "Usando terminal...", ACTIVO);
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_8", hilos[8], "Usando terminal...", NO_ACTIVO);

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}
static int buscarIndex_empty(array_procesos *_array);
static void initArray(array_procesos *_array);
static bool isOk_ID_Process(array_procesos *_array, process _t);

process *crear_Proceso(int _id, int _delay, char *_nombreProceso, pthread_t _hilo, char *_accion, int _estado){
	process *_p = (process *)malloc(sizeof(process));
	_p->id = _id;
	_p->delay = _delay;
	strcpy(_p->nombrePROCESO, _nombreProceso);
	_p->hilo = _hilo;
	strcpy(_p->accion, _accion);
	_p->estado = _estado;
	return _p;
}

void agregar_Proceso(array_procesos *_array, process _p){
	int _index = buscarIndex_empty(_array);
	bool id_ok = isOk_ID_Process(_array, _p);
	if(_index != -1){
		if(id_ok != false){
			_array[_index].proceso = _p;
			_array[_index].empty = false;
			printf("Se agrego a [_array] el proceso [%s] con id [%d] <---- OK\n", _array[_index].proceso.nombrePROCESO, _array[_index].proceso.id);
			cont_procesos++;
		}
		else{
			printf("El ID [%d] ya se encuentra asociado a un Proceso...\n", _p.id);
		}
	}
	else{
		printf("NO hay index disponible...\n");
	}
}

void ejecutar_Procesos(array_procesos *_array){
	printf("-----> Procesos = [%d]\n", cont_procesos);
	for(int i = 0; i < cont_procesos; i++){
		if(_array[i].proceso.estado == ACTIVO){
			printf("<=================================================================================>\n");
			printf("\tEl proceso de nombre [%s], con ID [%d], se encuentra realizando su [PROCESO], con un delay de [%d] segundo(s)\n", _array[i].proceso.nombrePROCESO, _array[i].proceso.id, _array[i].proceso.delay);
			pthread_create(&_array[i].proceso.hilo, NULL, (void*)thread_accion, &_array[i].proceso.accion);
			pthread_join(_array[i].proceso.hilo, NULL);
			for(int j = 0; j < _array[i].proceso.delay; j++){
				sleep(1);
			}
		}
		else if(_array[i].proceso.estado == NO_ACTIVO){
			printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
			printf("\tEl proceso de nombre [%s], con ID [%d], SE ENCUENTRA EN ESTADO NO ACTIVO\n", _array[i].proceso.nombrePROCESO, _array[i].proceso.id);
			printf("<+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++>\n");
		}
		else{
			;
		}
	}
}

void *thread_accion(void *arg){
	char acc[MAX_STRING] = "";
	strcpy(acc, (char *) arg);
	printf("%s\n", acc);
	printf("<=================================================================================>\n");
	return NULL;
}

array_procesos *crear_ArrayProcesos(void){
	array_procesos *array = (array_procesos *)malloc(sizeof(array_procesos)*MAX_PROCESOS);
	initArray(array);
	return array;
}

/* PRIVATE FUNCTIONS */

static bool isOk_ID_Process(array_procesos *_array, process _p){
	bool id_Ok = true;
	for(int i = 0; i < MAX_PROCESOS; i++){
		if(_array[i].proceso.id == _p.id){
			id_Ok = false;
			break;
		}
	}
	return id_Ok;
}

static void initArray(array_procesos *_array){
	for(int i = 0; i < MAX_PROCESOS; i++){
		_array[i].proceso.id = -1;
		_array[i].empty = true;
	}
}

static int buscarIndex_empty(array_procesos *_array){
	int _index_empty = -1;
	for(int i = 0; i < MAX_PROCESOS; i++){
		if(_array[i].empty == true){
			_index_empty = i;
			break;
		}
	}
	return _index_empty;
}