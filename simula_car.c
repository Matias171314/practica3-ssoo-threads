#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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
    coche_t *pcoche = (coche_t *)arg;
    int aleatorio;
    unsigned int semilla = (unsigned int)(pcoche->id + time(NULL)); // Mejor semilla

    printf("======================================\n");
    printf("🚗 Salida de %s (ID: %d)\n", pcoche->cadena, pcoche->id);
    printf("======================================\n");
    fflush(stdout);

    // Generar número aleatorio con función reentrante rand_r()
    aleatorio = rand_r(&semilla) % 10;

    sleep(aleatorio); // Simula el tiempo que tarda el coche en completar la carrera

    printf("--------------------------------------\n");
    printf("🏁 Llegada de %s (ID: %d)\n", pcoche->cadena, pcoche->id);
    printf("--------------------------------------\n");

    // Acceder a la sección crítica para almacenar la clasificación final
    pthread_mutex_lock(&mutex);
    clasificacionFinal[finalCarrera++] = pcoche->id;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(void) {
    pthread_t hilosCoches[NUM_COCHES];
    int i;

    // Mostrar el carrito con tu nombre
    printf("======================================\n");
    printf("🚗🚗🚗 Simulación de Carrera de Coches 🚗🚗🚗\n");
    printf("       Creado por: Matias Vásquez\n");
    printf("======================================\n");

    printf("\nSALIDA DE COCHES\n\n");

    // Crear hilos para cada coche
    for (i = 0; i < NUM_COCHES; i++) {
        Coches[i].id = i;
        Coches[i].cadena = malloc(20 * sizeof(char));
        sprintf(Coches[i].cadena, "Coche_%d", i);

        if (pthread_create(&hilosCoches[i], NULL, funcion_coche, &Coches[i]) != 0) {
            fprintf(stderr, "Error al crear el hilo %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("\nProceso de creación de hilos terminado\n\n");

    // Esperar a que todos los hilos terminen
    for (i = 0; i < NUM_COCHES; i++) {
        if (pthread_join(hilosCoches[i], NULL) != 0) {
            fprintf(stderr, "Error al esperar al hilo %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("\nTodos los coches han LLEGADO A LA META\n");

    // Mostrar la clasificación final
    printf("\nCLASIFICACIÓN FINAL:\n");
    printf("======================================\n");
    for (i = 0; i < NUM_COCHES; i++) {
        printf("Posición %d: %s (ID: %d)\n", i + 1, Coches[clasificacionFinal[i]].cadena, clasificacionFinal[i]);
    }
    printf("======================================\n");

    // Liberar la memoria asignada a los nombres de los coches
    for (i = 0; i < NUM_COCHES; i++) {
        free(Coches[i].cadena);
    }

    // Destruir el mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}