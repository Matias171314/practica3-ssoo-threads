# Makefile para la práctica 3: Simulación de carrera de coches

# Variables
CC = gcc
CFLAGS = -Wall -pthread
TARGET = simula_car

# Archivos fuente
SRC = simula_car.c

# Regla por defecto (compilar y ejecutar)
all: $(TARGET)
	./$(TARGET)

# Regla principal para compilar
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)