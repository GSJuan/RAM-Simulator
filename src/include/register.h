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

#define EMPTY 999999;

using namespace std;

class Register {
    private:
      int value;
    
    public:
      Register() { value = EMPTY; }
      Register(int newVal) { value = newVal; }
      ~Register();

      int getValue() { return value; }
      void setValue(int newVal) { value = newVal; }
      bool isEmpty() {return value == EMPTY; }
};

#endif
