/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a class that represents
 * individual Int Registers that can be found in data memory
 *
 */

#ifndef INT_REGISTER_CPP
#define INT_REGISTER_CPP

#include "include/int_register.h"

  IntRegister::IntRegister() { 
    value = EMPTY; 
  }
  
  IntRegister::IntRegister(int newVal) {  
    value = newVal; 
  }

  IntRegister::~IntRegister() {}

  int IntRegister::getValue() {
    return value; 
  }

  void IntRegister::setValue(int newVal) {
    value = newVal; 
  }
  
  bool IntRegister::isEmpty() {
    return value == EMPTY; 
  }

  int IntRegister::getValue() const{
    return value; 
  }
  
  bool IntRegister::isEmpty() const{
    return value == EMPTY; 
  }

  void IntRegister::print() const{
    if(isEmpty()) {
      cout << "EMPTY";
    } else cout << getValue(); 
  }
#endif
