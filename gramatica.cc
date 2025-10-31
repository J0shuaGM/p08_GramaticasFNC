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
#include <sstream>

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
  for(int i = 0; i <= numero_alfabeto; ++i) {
    getline(input, linea);
    simbolos_terminales_.setSimbolos(linea);
  }
  input >> numero_noterminales;
  for(int i = 0; i <= numero_noterminales; ++i) {
    getline(input, linea);
    for(char c : linea) {
      simbolo_no_terminal = NoTerminal(c); 
      simbolos_no_terminales_.push_back(simbolo_no_terminal);
    }
  }
  input >> numero_producciones;
  for(int i = 0; i <= numero_producciones; ++i) {
    getline(input, linea);
    std::string noterminal, prod;
    std::istringstream flujo(linea);
    flujo >> noterminal >> prod;
    for(char c : noterminal) {
      simbolo_no_terminal = NoTerminal(c);
      Produccion producciones(simbolo_no_terminal, prod); 
      producciones_.insert({simbolo_no_terminal, producciones});
    }
  }
  input.close();
}

std::istream& operator>>(std::istream& entrada, Gramatica& gramatica) {
  std::string nombre_fichero;
  entrada >> nombre_fichero; 
  gramatica = Gramatica(nombre_fichero);
  return entrada;
}

std::ostream& operator<<(std::ostream& salida, const Gramatica& gramatica) {
  Alfabeto simbolos_terminales = gramatica.getSimbolosTerminales(); 
  std::vector<NoTerminal> simbolos_no_terminales = gramatica.getSimbolosNoTerminales(); 
  NoTerminal simbolo_arranque = gramatica.getSimboloArranque();
  std::multimap<NoTerminal, Produccion> producciones = gramatica.getProducciones();
  salida << "Alfabeto: " << simbolos_terminales << std::endl;
  salida << "Simbolos no terminales: "; 
  for(const auto& s : simbolos_no_terminales) salida << s << " "; 
  salida << std::endl;
  salida << "Simbolo de arranque: " << simbolo_arranque << std::endl;
  salida << "Producciones: " << std::endl;
  for(const auto& p : producciones) {
    salida << p.second;
  }
  return salida;
}

bool Gramatica::EsTerminal(const std::string& caracter) {
  for(const auto& t : simbolos_no_terminales_) {
    if(t.getSimbolo() == caracter[0]) return true;
  }
  return false;
}

bool Gramatica::ProduccionesVacias(void) {
  for(const auto& p : producciones_) {
    if(p.first.getSimbolo() != 'S' && (p.second.getProduccion().empty() || p.second.getProduccion() == "&")) return true;
  }
  return false;
}

bool Gramatica::ProduccionesUnitarias(void) {
  for(const auto& p : producciones_) {
    if(p.second.getProduccion().size() == 1 && EsTerminal(p.second.getProduccion())) return true;
  }
  return false;
}

Gramatica Gramatica::ConversorFNC(void) {
  Gramatica FNC = *this;
  if(ProduccionesVacias()) {
    std::cerr << "La gramatica base contiene producciones vacias con lo que no es posible convertirla" << std::endl;
    exit(EXIT_FAILURE);
  } else if(ProduccionesUnitarias()) {
    std::cerr << "La gramatica base contiene producciones unitarias con lo que no es posible convertirla" << std::endl;
    exit(EXIT_FAILURE);
  }
  // Paso 1: Reemplazar terminales en producciones largas (n >= 2)
  // Mapear terminal -> no terminal auxiliar (Ca)
  std::map<char, NoTerminal> terminal_to_nt;

  // Construir conjunto de símbolos usados para evitar colisiones
  std::set<char> usados;
  for (const auto &nt : FNC.simbolos_no_terminales_) usados.insert(nt.getSimbolo());

  // función lambda para conseguir un nuevo símbolo no terminal único
  auto siguiente_simbolo = [&usados]() {
    for (char c = 'A'; c <= 'Z'; ++c) {
      if (usados.count(c) == 0) { usados.insert(c); return c; }
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      if (usados.count(c) == 0) { usados.insert(c); return c; }
    }
    // Si se agotan, devolver un carácter arbitrario (poco probable)
    return (char)('Z' + 1);
  };

  // Recolectar producciones a procesar (trabajamos sobre copia para modificar multimap)
  std::vector<std::pair<NoTerminal, Produccion>> lista;
  for (const auto &p : FNC.producciones_) lista.push_back(p);

  for (const auto &entry : lista) {
    NoTerminal A = entry.first;
    Produccion prod = entry.second;
    std::string rhs = prod.getProduccion();

    if (rhs.size() >= 2) {
      bool modificado = false;
      for (size_t i = 0; i < rhs.size(); ++i) {
        char sym = rhs[i];
        // Si es un terminal (esta en el alfabeto de terminales)
        if (FNC.simbolos_terminales_.search(sym)) {
          // Si no hay NT auxiliar para este terminal, crear uno
          if (terminal_to_nt.find(sym) == terminal_to_nt.end()) {
            char nuevo = siguiente_simbolo();
            NoTerminal Ca(nuevo);
            terminal_to_nt[sym] = Ca;
            // añadir Ca a símbolos no terminales
            FNC.simbolos_no_terminales_.push_back(Ca);
            // añadir producción Ca -> a
            Produccion paux(Ca, std::string(1, sym));
            FNC.producciones_.insert({Ca, paux});
          }
          // reemplazar terminal por el símbolo auxiliar
          rhs[i] = terminal_to_nt[sym].getSimbolo();
          modificado = true;
        }
      }
      if (modificado) {
        // eliminar la producción original (una de las claves iguales) y añadir la nueva
        auto range = FNC.producciones_.equal_range(A);
        for (auto it = range.first; it != range.second; ++it) {
          if (it->second.getProduccion() == prod.getProduccion()) { FNC.producciones_.erase(it); break; }
        }
        Produccion nueva(A, rhs);
        FNC.producciones_.insert({A, nueva});
      }
    }
  }

  // Paso 2: Descomponer producciones con m >= 3 en binarias
  // Recolectar de nuevo la lista de producciones (porque añadimos nuevas)
  lista.clear();
  for (const auto &p : FNC.producciones_) lista.push_back(p);

  for (const auto &entry : lista) {
    NoTerminal A = entry.first;
    Produccion prod = entry.second;
    std::string rhs = prod.getProduccion();
    size_t m = rhs.size();
    if (m >= 3) {
      // Crear m-2 nuevos no terminales D1..Dm-2
      std::vector<NoTerminal> Ds;
      for (size_t k = 0; k < m - 2; ++k) {
        char nuevo = siguiente_simbolo();
        NoTerminal D(nuevo);
        Ds.push_back(D);
        FNC.simbolos_no_terminales_.push_back(D);
      }
      // Eliminar la producción original
      auto range = FNC.producciones_.equal_range(A);
      for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getProduccion() == prod.getProduccion()) { FNC.producciones_.erase(it); break; }
      }
      // Añadir A -> B1 D1
      std::string rhs1;
      rhs1.push_back(rhs[0]);
      rhs1.push_back(Ds[0].getSimbolo());
      FNC.producciones_.insert({A, Produccion(A, rhs1)});
      // Añadir las producciones intermedias Dk -> B{k+1} D{k+1}
      for (size_t k = 0; k < Ds.size() - 1; ++k) {
        std::string r;
        r.push_back(rhs[k+1]);
        r.push_back(Ds[k+1].getSimbolo());
        FNC.producciones_.insert({Ds[k], Produccion(Ds[k], r)});
      }
      // Añadir Dm-2 -> Bm-1 Bm
      std::string rfinal;
      rfinal.push_back(rhs[m-2]);
      rfinal.push_back(rhs[m-1]);
      FNC.producciones_.insert({Ds.back(), Produccion(Ds.back(), rfinal)});
    }
  }

  return FNC;
}