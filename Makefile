# Makefile para la práctica 3: Simulación de carrera de coches

# Variables
CC = gcc
CFLAGS = -Wall -pthread
TARGET = simula_car

# Archivos fuente y objeto
SRC = simula_car.c
OBJ = $(SRC:.c=.o)

# Regla principal
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)


fun es_rama(ab:a_bin):: bool
	si vacio?(ab) entonces
		devolver Falso
	sino si vacio?(izq(ab)) y !vacio?(der(ab)) entonces
		while !vacio?(der(ab)) hacer
			es_rama(der(ab))
		fwhile
		devolver True

	sino si vacio?(der(ab)) y !vacio?(izq(ab)) entonces
		while !vacio?(izq(ab)) hacer
			es_rama(izq(ab))
		fwhile
		devolver True
	fsi
ffun