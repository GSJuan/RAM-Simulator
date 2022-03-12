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

#ifndef DATA_MEMORY_H
#define DATA_MEMORY_H


#include "int_register.h"
#include "vector_register.h"

using namespace std;


class Data {
  private:
    vector<Register*> data;
    
  public:
    Data();
    Data(int size);
    ~Data();

    int read(int reg);
    int readAccumulator();

    void write(int value, int reg);
    void writeAccumulator(int value);

    void allocate (int);

    friend ostream& operator<<(ostream& os, const Data& dt);
};
#endif