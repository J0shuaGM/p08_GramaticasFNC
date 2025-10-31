// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramaticas en Forma Normal de Chomsky
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 28/10/2025

#ifndef NOTERMINALES_H
#define NOTERMINALES_H

#include <iostream>
#include <vector>

class NoTerminal {
  public:
    //Constructor
    NoTerminal(void) { simbolo_ = 'S'; }
    NoTerminal(char simbolo); 

    //Getters y setters
    char getSimbolo(void) { return simbolo_; }
    char getSimbolo(void) const { return simbolo_; }

    //Sobrecarga E/S
    friend std::istream& operator>>(std::istream& entrada, NoTerminal& simbolos);
    friend std::ostream& operator<<(std::ostream& salida, const NoTerminal& simbolos);
    
    bool operator<(const NoTerminal& otro) const { return simbolo_ < otro.simbolo_; }

    //Metodos

  private: 
    char simbolo_;
};

#endif //NOTERMINALES_H