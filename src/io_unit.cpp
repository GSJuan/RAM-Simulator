
/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a parent class that represents
 * input output unit
 *
 */

#ifndef IO_UNIT_CPP
#define IO_UNIT_CPP

#include "include/io_unit.h"

Tape::Tape(){};

Tape::~Tape(){};


int Tape::getTapeSize() { 
  return tape.size(); 
}

string Tape::getFileName() { 
  return fileName; 
}

//writes the value in the tape
void Tape::write(int value) { 
  tape.push_back(value); 
}

ostream& operator<<(ostream& os, const Tape& inputUnit) {
  os << "[";
  for(int i = 0; i < inputUnit.tape.size(); i++) {
    os << inputUnit.tape[i] << "|";
  }
  os << "]" << endl;
  return os;
}
#endif