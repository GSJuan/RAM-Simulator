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

using namespace std;

#define NULL_VALUE "null";

class Instruction {

    private:
      string opcode;
      string mode;
      string op;
    
    public:
      Instruction();
      Instruction(string, string, string);
      ~Instruction();

      string getOpcode();
      string getMode();
      string getOp();

      void modify(Instruction new_instruction);
};

#endif