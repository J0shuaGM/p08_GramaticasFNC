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

Gramatica::Gramatica(const std::string& fichero) {
  std::ifstream input(fichero); 
  if(!input.is_open()) {
    std::cerr << "El fichero de lectura no se ha podido abrir" << std::endl;
    exit(EXIT_FAILURE);
  }
  int numero_alfabeto, numero_noterminales, numero_producciones;
  std::string linea;
  NoTerminal simbolo_no_terminal;
  input >> numero_alfabeto;
  for(int i = 0; i < numero_alfabeto; ++i) {
    getline(input, linea);
    simbolos_terminales_ = Alfabeto(linea);
  }
  input >> numero_noterminales;
  for(int i = 0; i < numero_noterminales; ++i) {
    getline(input, linea);
    for(char c : linea) {
      simbolo_no_terminal = NoTerminal(c); 
      simbolos_no_terminales_.push_back(simbolo_no_terminal);
    }
  }
  input >> numero_producciones;
  for(int i = 0; i < numero_producciones; ++i) {
    getline(input, linea);
    
  }
}