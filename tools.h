// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Diseño e implementación deun simulador de autómatas finitos
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 17/10/2025

#include <iostream>

#include "alfabeto.h"

const std::string helptext = R"(El programa necesita dos ficheros para poder ser ejecutado: input.gra y output.gra que son los ficheros que especifican las gramaticas de entrada y salida respectivamente Los ficheros de especificacion de gramaticas son ficheros de texto plano con extension
.gra que contienen los elementos definitorios de la gramatica G ≡ (Σ, V, S, P) en este
orden: simbolos terminales, simbolos no terminales, simbolo de arranque y producciones.
El formato de cada uno de estos elementos en el fichero es el siguiente:
1. Simbolos terminales (alfabeto): una linea que contiene N, el numero de simbolos
en el alfabeto seguida de N lineas, cada una de las cuales contiene un simbolo del
alfabeto. Cada simbolo del alfabeto debe ser un unico caracter imprimible.
2. Simbolos no terminales: una linea que contiene V , el numero de simbolos no
terminales, seguida de V lineas, cada una de las cuales contiene una cadena alfanumerica sin espacios. Se asumira que el primero de los simbolos no terminales de
esta lista sera el simbolo de arranque.
3. Producciones: una linea que contiene P, el numero de producciones de la gramiatica, seguida por P lineas cada una de las cuales contiene una produccion en el formato:
A a
siendo a ∈ (Σ U V )* , es decir una secuencia de simbolos terminales y no terminales.
La cadena vacia, ϵ se representa mediante el caracter &.)";
void Usage(int argc, char* argv[]);