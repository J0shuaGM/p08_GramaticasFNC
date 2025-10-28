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
#include <vector>

#include "noterminales.h"

NoTerminales::NoTerminales(int size, char simbolo) {
  size_ = size;
  noterminales_.push_back(simbolo);
}

void NoTerminales::setSimbolo(char simbolo) {
  noterminales_.push_back(simbolo); 
  ++size_;
}

std::istream& operator>>(std::istream& entrada, NoTerminales& simbolos) {
  int size; 
  char simbolo; 
  for(int i = 0; i < size; ++i) {
    entrada >> simbolo; 
    simbolos = NoTerminales(size, simbolo);
  }
  return entrada;
}

std::ostream& operator<<(std::ostream& salida, const NoTerminales& simbolos) {
  salida << "Simbolos No Terminales: ";
  for(char c : simbolos.getNoTerminales()) {
    salida << c << " ";
  }
  return salida;
}