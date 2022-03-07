/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a class that represents
 * individual Registers that can be found in data memory
 *
 */

#ifndef REGISTER_CPP
#define REGISTER_CPP

#include "include/register.h"

  Register::Register() { 
    value = EMPTY; 
  }
  
  Register::Register(int newVal) {  
    value = newVal; 
  }

  Register::~Register() {}

  int Register::getValue() {
    return value; 
   }
  void Register::setValue(int newVal) {
    value = newVal; 
  }
  bool Register::isEmpty() {
    return value == EMPTY; 
  }

  int Register::getValue() const{
    return value; 
  }
  
  bool Register::isEmpty() const{
    return value == EMPTY; 
  }


#endif
