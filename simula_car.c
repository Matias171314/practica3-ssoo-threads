#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_COCHES 8

// Tipo de dato para representar un coche
typedef struct {
    int id;
    char *cadena;
} coche_t;

// Array de datos de tipo coche_t
coche_t Coches[NUM_COCHES];

// Función ejecutada por los hilos
void *funcion_coches(coche_t *pcoche) 
{
    int aleatorio;
    unsigned int semilla = (pcoche -> id) + pthread_self(); // Semilla generación num. aleatorio
    printf("Salida de %s %d\n", pcoche -> cadena, pcoche -> id);

    fflush(stdout);

    // Generar número aleatorio con función re-entrante rand_r()
    aleatorio = rand_r(&semilla) % 10;

    sleep(aleatorio);

    printf("Llegada de %s %d\n", pcoche -> cadena, pcoche -> id);

    // CODE 4
    // CODE 2
}

int main(void) 
{
    pthread_t hilosCoches [NUM_COCHES];	// Tabla con los identificadores de los hilos
    int i;

    printf("Se inicia proceso de creación de hilos\n\n");
    printf("SALIDA DE COCHES\n");

    for (i=0; i<NUM_COCHES; i++) 
    {
        // CODE 1
    }
    printf("Proceso de creación de hilos terminados\n\n");
    
    for (i=0, i<NUM_COCHES; i++) 
    {
        // CODE 3
    }
    
    printf("Todos los coches han LLEGADO A LA META \n");

    // CODE 5
    
    return 0;
}
