/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents
 * individual int Registers that can be found in data memory
 *
 */

#ifndef INT_REGISTER_H
#define INT_REGISTER_H

#include "register.h"

using namespace std;

class IntRegister: public Register {
    private:
      int value;

    public:
      IntRegister();
      IntRegister(int newVal);
      ~IntRegister();

      int getValue();
      void setValue(int newVal);
      bool isEmpty();

      int getValue() const;
      bool isEmpty() const;
      void print();
};

#endif