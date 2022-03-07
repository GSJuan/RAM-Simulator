/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents
 * the data memory structure of a RAM
 */

#ifndef DATA_MEMORY_CPP
#define DATA_MEMORY_CPP

#include "include/data_memory.h"

using namespace std;

Data::Data() {}

Data::Data(int size) {
  data.resize(size);
} 

Data::~Data() {
  data.clear();
}

int Data::read(int reg) {
  return data[reg]->getValue();
}

int Data::readAccumulator(){
  return data[0]->getValue();
}

void Data::write(int value, int reg){
  data[reg]->setValue(value);
}

void Data::writeAccumulator(int value){
  data[0]->setValue(value);
}

ostream& operator<<(ostream& os, const Data& memory) {
  for(int i = 0; i < memory.data.size(); i++){
    os << "R" << i << " = ";
    if(memory.data[i]->isEmpty()) {
      os << "EMPTY"; 
    }
    else os << memory.data[i]->getValue();
    os << endl;
  }
  return os;
}

#endif