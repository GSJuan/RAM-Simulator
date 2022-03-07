/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a children class that represents
 * output unit tape
 *
 */

#ifndef OUTPUT_UNIT_H
#define OUTPUT_UNIT_H

#include "io_unit.h"

using namespace std;

class OutTape: public Tape {
  public:
    OutTape();
    OutTape(string);
    ~OutTape();

    void write(int);

    //dumps the tape contents into the file
    int load();
};

#endif