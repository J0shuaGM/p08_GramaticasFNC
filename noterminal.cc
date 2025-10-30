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

#include "noterminal.h"

NoTerminal::NoTerminal(char simbolo) {
  simbolo_  = simbolo;
}

std::istream& operator>>(std::istream& entrada, NoTerminal& simbolos) {
  char simbolo; 
  entrada >> simbolo; 
  simbolos = NoTerminal(simbolo); 
  return entrada;
}

std::ostream& operator<<(std::ostream& salida, const NoTerminal& simbolos) {
  salida << simbolos.getSimbolo() << std::endl;
  return salida;
}