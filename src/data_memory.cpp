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

Data::Data() {
  for(int i = 0; i <10; i++) {
    data.push_back(new VectorRegister());
  }
}

Data::Data(int size) {
  for(int i = 0; i < size; i++) {
    data.push_back(new VectorRegister());
  }
} 

Data::~Data() {
  data.clear();
}

int Data::read(int reg) {
  allocate(reg);
  return data[reg]->getValue();
}

int Data::read(int reg, int pos) {
  allocate(reg);
  return data[reg]->getValue(pos);
}

int Data::readAccumulator(){
  return data[0]->getValue();
}

int Data::readRegSize(int reg) {
  allocate(reg);
  return data[reg]->getSize();
}

void Data::write(int value, int reg){
  allocate(reg);
  data[reg]->setValue(value);
}

void Data::write(int value, int reg, int pos){
  allocate(reg);
  data[reg]->setValue(pos, value);
}

void Data::writeAccumulator(int value){
  data[0]->setValue(value);
}

void Data::allocate(int value) {
  if(data.size() - 1 < value) {
    for(int i = data.size() - 1; i <= value; i++) {
      data.push_back(new VectorRegister());
    }
  }
}

ostream& operator<<(ostream& os, const Data& memory) {
  for(int i = 0; i < memory.data.size(); i++){
    os << "\tR" << i << " = ";
    memory.data[i]->print();
    os << endl;
  }
  return os;
}

#endif