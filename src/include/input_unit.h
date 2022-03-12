/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a children class that represents
 * input unit tape
 *
 */

#ifndef INPUT_UNIT_H
#define INPUT_UNIT_H

#include "io_unit.h"

using namespace std;

class InTape: public Tape {
  private:
    int index; //head

  public:
    InTape();
    InTape(string);
    ~InTape();

    int getIndex();
    int getIndex() const;

    //dumps the file contents into the tape
    //returns 0 if succesful, -1 otherwise
    int load();

    void write(int);

    int readTape();

    //moves forward the tape head
    void moveHead();

    friend ostream& operator<<(ostream& os, const InTape&);
};

#endif