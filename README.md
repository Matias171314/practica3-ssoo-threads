# Simulación de Carrera de Coches con Hilos POSIX

Este proyecto es una implementación de una simulación de carrera de coches utilizando hilos POSIX en lenguaje C. Forma parte de la práctica 3 de la asignatura Sistemas Operativos.

## Descripción

El programa simula una carrera en la que cada coche es representado por un hilo. Los coches compiten en paralelo y su orden de llegada se determina de forma aleatoria. Los resultados se sincronizan mediante mecanismos de exclusión mutua para evitar condiciones de carrera.

## Características

- Creación de hilos utilizando pthread_create.
- Sincronización de acceso a recursos compartidos con pthread_mutex.
- Simulación de tiempos de llegada aleatorios mediante rand_r.
- Clasificación final almacenada de manera segura.

# Estructura del Proyecto

- simula_car.c: Código fuente principal del programa.
- Makefile: Archivo para la compilación y ejecución del programa.

# Requisitos

- Compilador gcc.
- Biblioteca de hilos POSIX (pthread).
- Sistema operativo Linux (compatible con POSIX).

# Uso

## Compilación
Para compilar el programa, ejecuta el siguiente comando en la terminal:
- make
Esto generará un archivo ejecutable llamado simula_car.

## Ejecución
Para ejecutar el programa, utiliza:
- make run

## Limpieza
Para eliminar los archivos generados (ejecutable y objetos), usa:
- make clean

# Funcionamiento

El programa crea un hilo para cada coche.
Cada hilo simula la salida y llegada de un coche.
Los tiempos de llegada son aleatorios.
El hilo principal espera a que todos los coches terminen y muestra la clasificación final.

# Autores

Matias Nicolas Vásquez Herbozo - Y4507803R
Desarrollado para la Práctica 3 de la asignatura Sistemas Operativos de la Universidad de Alcalá.

# Invitación:
https://github.com/Matias171314/practica3-ssoo-threads/invitations