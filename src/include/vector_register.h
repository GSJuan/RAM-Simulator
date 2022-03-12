/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents
 * individual vectorized Registers that can be found in data memory
 *
 */

#ifndef VECTOR_REGISTER_H
#define VECTOR_REGISTER_H

#include "register.h"
#include <vector>
#include <iterator>

using namespace std;

class VectorRegister: public Register {
    private:
      vector<int> value;

    public:
      VectorRegister();
      VectorRegister(int size);
      VectorRegister(int size, int newVal);

      ~VectorRegister();

      int getValue();
      int getValue() const;
      int getValue(int);
      int getValue(int) const;

      void setValue(int newVal);
      void setValue(int position, int newValue);

      bool isEmpty() const;
      void print() const;
};

#endif