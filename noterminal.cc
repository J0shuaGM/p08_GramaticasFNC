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



/**
 * @brief Constructor de la clae NoTerminal
 * @param simbolo caracter que contiene el simbolo no Terminal 
*/
NoTerminal::NoTerminal(char simbolo) {
  simbolo_  = simbolo;
}



/**
 * @brief Sobrecarga del operador de entrada de la clase NoTerminal
 * @param entrada Variable para recibir la entrada de datos
 * @param simbolos Objeto NoTerminal a ser sobreescrito
 * @return entrada Retornamos el nuevo valor  
*/
std::istream& operator>>(std::istream& entrada, NoTerminal& simbolos) {
  char simbolo; 
  entrada >> simbolo; 
  simbolos = NoTerminal(simbolo); 
  return entrada;
}



/**
 * @brief Sobrecarga del operador de salida de la clase NoTerminal
 * @param entrada Variable para recibir la salida de datos
 * @param simbolos Objeto NoTerminal a ser escrito
 * @return entrada Retornamos el nuevo valor  
*/
std::ostream& operator<<(std::ostream& salida, const NoTerminal& simbolos) {
  salida << simbolos.getSimbolo();
  return salida;
}