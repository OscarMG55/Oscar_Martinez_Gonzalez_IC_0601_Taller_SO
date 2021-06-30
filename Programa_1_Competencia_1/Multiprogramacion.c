#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

      // Se debe pasar el argumento 1, para inicalizar la ejecucion de los hilos, al momento de hacer la compilacion ./Multiprogramacion 1

void *thread_routine_1 (void *arg){
        printf("El hilo 1 comenzo a ejecutarse \n");
}
void *thread_routine_2 (void *arg){
        printf("El hilo 2 comenzo a ejecutarse \n");
}
void *thread_routine_3 (void *arg){
        printf("El hilo 3 comenzo a ejecutarse \n");
}
void *thread_routine_4 (void *arg){
        printf("El hilo 4 comenzo a ejecutarse \n");
}
void *thread_routine_5 (void *arg){
        printf("El hilo 5 comenzo a ejecutarse \n");
}
void *thread_routine_6 (void *arg){
        printf("El hilo 6 comenzo a ejecutarse \n");
}
void *thread_routine_7 (void *arg){
        printf("El hilo 7 comenzo a ejecutarse \n");
}
void *thread_routine_8 (void *arg){
        printf("El hilo 8 comenzo a ejecutarse \n");
}
void *thread_routine_9 (void *arg){
        printf("El hilo 9 comenzo a ejecutarse \n");
}

int main(int argc, char *argv[]){
    
        int value_1 = atoi(argv[1]);
        pthread_t hilo1;
        if(0 != pthread_create(&hilo1, NULL, thread_routine_1, &value_1))
                return -1;

        int value_2 = atoi(argv[1]);
        pthread_t hilo2;
        if(0 != pthread_create(&hilo2, NULL, thread_routine_2, &value_2))
                return -1;

        int value_3 = atoi(argv[1]);
        pthread_t hilo3;
        if(0 != pthread_create(&hilo3, NULL, thread_routine_3, &value_3))
                return -1;

        int value_4 = atoi(argv[1]);
        pthread_t hilo4;
        if(0 != pthread_create(&hilo4, NULL, thread_routine_4, &value_4))
                return -1;

        int value_5= atoi(argv[1]);
        pthread_t hilo5;
        if(0 != pthread_create(&hilo5, NULL, thread_routine_5, &value_5))
                return -1;

        int value_6 = atoi(argv[1]);
        pthread_t hilo6;
        if(0 != pthread_create(&hilo6, NULL, thread_routine_6, &value_6))
                return -1;

        int value_7 = atoi(argv[1]);
        pthread_t hilo7;
        if(0 != pthread_create(&hilo7, NULL, thread_routine_7, &value_7))
                return -1;

        int value_8 = atoi(argv[1]);
        pthread_t hilo8;
        if(0 != pthread_create(&hilo8, NULL, thread_routine_8, &value_8))
                return -1;


        int value_9 = atoi(argv[1]);
        pthread_t hilo9;
        if(0 != pthread_create(&hilo9, NULL, thread_routine_9, &value_9))
                return -1;

        pthread_join(hilo1, NULL);
        pthread_join(hilo2, NULL);
        pthread_join(hilo3, NULL);
        pthread_join(hilo4, NULL);
        pthread_join(hilo5, NULL);
        pthread_join(hilo6, NULL);
        pthread_join(hilo7, NULL);
        pthread_join(hilo8, NULL);
        pthread_join(hilo9, NULL);


    return 0;
}