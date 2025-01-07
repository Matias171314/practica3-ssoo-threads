#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_COCHES 8

// Variables globales para la clasificación
volatile int clasificacionFinal[NUM_COCHES];
volatile int finalCarrera = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Tipo de dato para representar un coche
typedef struct {
    int id;
    char *cadena;
} coche_t;

// Array de datos de tipo coche_t
coche_t Coches[NUM_COCHES];

// Función ejecutada por los hilos
void *funcion_coche(void *arg) {
    coche_t *pcoche = (coche_t *)arg; // Convertimos el argumento al tipo coche_t
    int aleatorio;
    unsigned int semilla = pcoche->id + pthread_self(); // Semilla para generación aleatoria

    printf("Salida de %s %d\n", pcoche->cadena, pcoche->id);
    fflush(stdout);

    // Generar número aleatorio con función reentrante rand_r()
    aleatorio = rand_r(&semilla) % 10;

    sleep(aleatorio); // Simula el tiempo que tarda el coche en completar la carrera

    printf("Llegada de %s %d\n", pcoche->cadena, pcoche->id);

    // Acceder a la sección crítica para almacenar la clasificación final
    pthread_mutex_lock(&mutex);
    clasificacionFinal[finalCarrera++] = pcoche->id;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(void) {
    pthread_t hilosCoches[NUM_COCHES]; // Identificadores de los hilos
    int i;

    printf("Se inicia proceso de creación de hilos...\n\n");
    printf("SALIDA DE COCHES\n");

    // Crear hilos para cada coche
    for (i = 0; i < NUM_COCHES; i++) {
        Coches[i].id = i;
        Coches[i].cadena = malloc(20 * sizeof(char)); // Asignar memoria para el nombre
        sprintf(Coches[i].cadena, "Coche_%d", i); // Asignar nombre al coche

        if (pthread_create(&hilosCoches[i], NULL, funcion_coche, &Coches[i]) != 0) {
            fprintf(stderr, "Error al crear el hilo %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("Proceso de creación de hilos terminado\n\n");

    // Esperar a que todos los hilos terminen
    for (i = 0; i < NUM_COCHES; i++) {
        if (pthread_join(hilosCoches[i], NULL) != 0) {
            fprintf(stderr, "Error al esperar al hilo %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("Todos los coches han LLEGADO A LA META\n");

    // Mostrar la clasificación final
    printf("CLASIFICACIÓN FINAL:\n");
    for (i = 0; i < NUM_COCHES; i++) {
        printf("Posición %d: Coche %d\n", i + 1, clasificacionFinal[i]);
    }

    // Liberar la memoria asignada a los nombres de los coches
    for (i = 0; i < NUM_COCHES; i++) {
        free(Coches[i].cadena);
    }

    return 0;
}