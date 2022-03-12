/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a children class that represents
 * output unit tape
 *
 */

#ifndef OUTPUT_UNIT_CPP
#define OUTPUT_UNIT_CPP

#include "include/output_unit.h"

OutTape::OutTape() {
  fileName = "";
}

OutTape::OutTape(string input) {
  fileName = input;
}

OutTape::~OutTape() {
  tape.clear();
  fileName = "";
}

void OutTape::write(int value) { 
  tape.push_back(value); 
}

int OutTape::load() {
  ofstream outputFile;
  int value;
  outputFile.open(fileName);
  if(outputFile.is_open()) {
    for (int i = 0; i < tape.size(); i ++) {
        outputFile << tape[i] << endl;
    }
  }
  else {
    cerr << endl << "ERROR: unable to open file " << fileName << endl;
    return -1;
  }
  outputFile.close();
  return 0;
}

ostream& operator<<(ostream& os, const OutTape& outputUnit) {
  os << "[";
  copy(outputUnit.tape.begin(), outputUnit.tape.end(), ostream_iterator<int>(os, "|"));
  os << "]" << endl;
  return os;
}
#endif