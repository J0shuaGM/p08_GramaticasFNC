# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Computabilidad y Algoritmia
# Curso: 2º
# Practica 6: Diseño e implementación deun simulador de autómatas finitos
# Autor: Joshua Gomez Marrero
# Correo: alu0101477398@ull.edu.es
# Fecha: 17/10/2025
# Archivo: Makefile

# Nombre del archivo de salida
TARGET =  Grammar2CNF

# Lista de archivos fuente(.cc)
SOURCES = 

# Dependencias de los archivos fuente 
DEPENDENCIES = 

# Opciones de compilación
CXX = g++
CXXFLAGS = -std=c++11

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla por defecto
default: $(TARGET)