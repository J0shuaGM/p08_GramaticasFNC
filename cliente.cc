// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramaticas en Forma Normal de Chomsky
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 28/10/2025

#include <iostream>
#include <map>
#include <fstream>

#include "noterminal.h"
#include "alfabeto.h"
#include "produccion.h"
#include "gramatica.h"
#include "tools.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string fichero = argv[1];
  Gramatica gramatica(fichero);
  std::cout << gramatica << std::endl;
  return 0;
}