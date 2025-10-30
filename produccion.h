// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramaticas en Forma Normal de Chomsky
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 28/10/2025

#ifndef PRODUCCIONES_H
#define PRODUCCIONES_H

#include <iostream>

#include "noterminal.h"

class Produccion {
  public:
    //Constructor
    Produccion(NoTerminal simbolo, const std::string& produccion);

    //Getters y Setters
    NoTerminal getSimbolo(void) { return simbolo_; }
    std::string getProduccion(void) { return produccion_; }
    NoTerminal getSimbolo(void) const { return simbolo_; }
    std::string getProduccion(void) const { return produccion_; }
    void setSimbolo(NoTerminal simbolo) { simbolo_ = simbolo; }
    void setProduccion(const std::string produccion) { produccion_ = produccion; }

    //Sobrecarga de E/S
    friend std::istream& operator>>(std::istream& entrada, Produccion& simbolos);
    friend std::ostream& operator<<(std::ostream& salida, const Produccion& simbolos);

  private:
    NoTerminal simbolo_;
    std::string produccion_; //conjunto de Terminales y no Terminales
}; 

#endif //PRODUCCIONES_H