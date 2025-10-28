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

class NoTerminales {
  public:
    //Constructor
    NoTerminales(int size, char simbolo); 

    //Getters y setters
    void setSimbolo(char simbolo);
    std::vector<char> getNoTerminales(void) { return noterminales_; }
    std::vector<char> getNoTerminales(void) const { return noterminales_; }
    int getSize(void) { return size_; }

    //Sobrecarga E/S
    friend std::istream& operator>>(std::istream& entrada, NoTerminales simbolos);
    friend std::ostream& operator<<(std::ostream& salida, const NoTerminales& simbolos);
    
    //Metodos

  private: 
    int size_;
    std::vector<char> noterminales_;
};

#endif //NOTERMINALES_H