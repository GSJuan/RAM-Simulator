/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a children class that represents
 * input unit tape
 *
 */

#ifndef INPUT_UNIT_CPP
#define INPUT_UNIT_CPP

#include "include/input_unit.h"

InTape::InTape() {
  fileName = "";
}

InTape::InTape(string input) {
  index = 0;
  fileName = input;
  load();
}

InTape::~InTape() {
  tape.clear();
  index = 0;
  fileName = "";
}

int InTape::getIndex() {
  return index;
}

int InTape::getIndex() const{
  return index;
}

int InTape::load() {
  ifstream inputFile;
  int value;
  inputFile.open(fileName);
  if(inputFile.is_open()) {
    while(!inputFile.eof()) {
      inputFile >> (int &) value;
      write(value);
    }
  }
  else {
    cerr << endl << "ERROR: unable to open file " << fileName << endl;
    return -1;
  }
  inputFile.close();
  return 0;
}

void InTape::write(int value) { 
  tape.push_back(value); 
}

int InTape::readTape() {
  return tape[index];
}

void InTape::moveHead() {
  index++;
}

ostream& operator<<(ostream& os, const InTape& inputUnit) {
  os << "[";
  copy(inputUnit.tape.begin(), inputUnit.tape.end(), ostream_iterator<int>(os, "|"));
  os << "] with head at position " <<  inputUnit.getIndex() << endl;
  return os;
}

#endif