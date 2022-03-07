/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents individual instructions
 *
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <iostream>

using namespace std;

#define NULL_VALUE "null";

class Instruction {
    private:
      string opcode; // LOAD || ...
      string mode; // * || = || " "
      string op; // [0-9]+ 
    
    public:
      Instruction();
      Instruction(string opcode, string mode, string op);
      ~Instruction();

      string getOpcode();
      string getMode();
      string getOp();

      string getOpcode() const;
      string getMode() const;
      string getOp() const;

      void modify(Instruction new_instruction);

      friend ostream& operator<<(ostream& os, const Instruction& dt);
};

#endif