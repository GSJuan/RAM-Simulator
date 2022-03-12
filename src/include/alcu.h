/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents
 * the arithmetic, logic and control unit of a RAM
 */

#ifndef ALCU_H
#define ALCU_H

#include "program_memory.h"
#include "data_memory.h"
#include "input_unit.h"
#include "output_unit.h"

class Alcu {
  private:
    Program program;
    Data data;
    InTape inTape;
    OutTape outTape;
    int currState; //0 halt, 1 working, 2 error
    Instruction currInst;
    int pi; //curren intstruction index
    int debugState;
    int executedInstructions;
  
  public:
    Alcu();
    Alcu(string programFile, string inputFile, string outputFile, int debug);
    ~Alcu();

    Program getProgram() { return program; }
    Data getData() { return data; }
    InTape getInTape() { return inTape; }
    OutTape getOutTape() { return outTape; }
    Instruction getCurrInstruction() { return currInst; }
    int getExecutedInstructions() {return executedInstructions; }

    Program getProgram() const{ return program; }
    Data getData() const{ return data; }
    InTape getInTape() const{ return inTape; }
    OutTape getOutTape() const{ return outTape; }
    Instruction getCurrInstruction() const{ return currInst; }
    int getExecutedInstructions() const{ return executedInstructions; }

    void updateInstruction();
    void updateInstruction(int ip);

    void run();
    void printCurrentInstruction();
    void printMemoryStatus();
    void printProgram();
    void printInputTape();
    void printOutputTape();

    void load();
    void store();
    void add();
    void sub();
    void mul();
    void div();
    void read();
    void write();
    void jump();
    void jzero();
    void jgtz();
    void halt();

    void mathFramework();
    void jumpFramework();

  friend ostream& operator<<(ostream& os, const Alcu& dt);
};
#endif