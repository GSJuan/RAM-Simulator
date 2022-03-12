
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

Tape::Tape(){
  fileName = "";
};

Tape::Tape(string file) {
  fileName = file;
}

Tape::~Tape(){};


int Tape::getTapeSize() { 
  return tape.size(); 
}

string Tape::getFileName() { 
  return fileName; 
}
#endif