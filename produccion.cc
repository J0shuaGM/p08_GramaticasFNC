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

#include "noterminal.h"
#include "produccion.h"

Produccion::Produccion(NoTerminal simbolo, const std::string& produccion) {
  simbolo_ = simbolo;
  produccion_ = produccion;
}

std::istream& operator>>(std::istream& entrada, Produccion& simbolos) {
  char simbolo;
  std::string produccion; 
  entrada >> simbolo >> produccion; 
  NoTerminal noterminal(simbolo);
  simbolos = Produccion(noterminal, produccion);
  return entrada;
}

std::ostream& operator<<(std::ostream& salida, const Produccion& simbolos) {
  salida << simbolos.getSimbolo() << " -> " << simbolos.getProduccion() << std::endl;
  return salida;
}