/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents
 * individual Registers that can be found in data memory
 *
 */

#ifndef REGISTER_H
#define REGISTER_H

#define EMPTY 999999

#include <iostream>

using namespace std;

class Register {
    public:
      Register();
      ~Register();
      virtual int getValue() = 0;
      virtual void setValue(int newVal) = 0;
      void setValue(int pos, int val);
      virtual bool isEmpty() = 0;

      virtual int getValue() const = 0;
      int getValue(int pos);
      virtual bool isEmpty() const = 0;
      virtual void print() const = 0;
};

#endif
