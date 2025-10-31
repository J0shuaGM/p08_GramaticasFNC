// Universidad de La Laguna
// Escuela Superior de Ingenierıa y Tecnologıa
// Grado en Ingenierıa Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 7: Gramaticas en Forma Normal de Chomsky
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 28/10/2025

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include <iostream>
#include <map>

#include "noterminal.h"
#include "alfabeto.h"
#include "produccion.h"

class Gramatica {
  public: 
    //Constructor
    Gramatica(const std::string& fichero);
    Gramatica() = default;

    //Getters
    Alfabeto getSimbolosTerminales(void) { return simbolos_terminales_; }
    std::vector<NoTerminal> getSimbolosNoTerminales(void) { return simbolos_no_terminales_; }
    NoTerminal getSimboloArranque(void) { return simbolo_arranque_; }
    std::multimap<NoTerminal, Produccion> getProducciones(void) { return producciones_; }

    //Getters constantes
    Alfabeto getSimbolosTerminales(void) const  { return simbolos_terminales_; }
    std::vector<NoTerminal> getSimbolosNoTerminales(void) const { return simbolos_no_terminales_; }
    NoTerminal getSimboloArranque(void) const { return simbolo_arranque_; }
    std::multimap<NoTerminal, Produccion> getProducciones(void) const { return producciones_; }

    //Sobrecarga de operadores E/S
    friend std::istream& operator>>(std::istream& entrada, Gramatica& gramatica);
    friend std::ostream& operator<<(std::ostream& salida, const Gramatica& gramatica);

    //Metodos
    bool ProduccionesVacias(void); 
    bool ProduccionesUnitarias(void);
    bool EsTerminal(const std::string& caracter);
    Gramatica ConversorFNC(void);

  private:
    Alfabeto simbolos_terminales_;
    std::vector<NoTerminal> simbolos_no_terminales_; 
    NoTerminal simbolo_arranque_;
    std::multimap<NoTerminal, Produccion> producciones_; //NoTerminal(char) que actua de ID -> Producciones
};

#endif //GRAMATICA_H