/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a class that represents
 * individual vectorized Registers that can be found in data memory
 *
 */

#ifndef VECTOR_REGISTER_CPP
#define VECTOR_REGISTER_CPP

#include "include/vector_register.h"

  VectorRegister::VectorRegister() { 
    value.resize(10, EMPTY);
  }
  
  VectorRegister::VectorRegister(int size) {  
    value.resize(size, EMPTY); 
  }

  VectorRegister::VectorRegister(int size, int newVal) {  
    value.resize(size, newVal); 
  }

  VectorRegister::~VectorRegister() {}

  int VectorRegister::getValue() {
    return value[0]; 
  }

  int VectorRegister::getValue() const{
    return value[0]; 
  }

  int VectorRegister::getValue(int position) {
    return value[position]; 
  }
  
  int VectorRegister::getValue(int position) const{
    return value[position]; 
  }

  void VectorRegister::setValue(int newVal) {
    value[0] = newVal; 
  }

  void VectorRegister::setValue(int position, int newVal) {
    value[position] = newVal; 
  }

  bool VectorRegister::isEmpty() const{
    if(!value.empty()) {
      for(int i = 0; i < value.size(); i++) {
        if(value[i] != EMPTY) return false;
      }
    }
    return true;  
  }

  void VectorRegister::print() const{
    if(isEmpty()) {
      cout << "EMPTY";
    } else {
      std::copy(value.begin(), value.end(),std::ostream_iterator<int>(std::cout, ", "));
    } 
  }
#endif
