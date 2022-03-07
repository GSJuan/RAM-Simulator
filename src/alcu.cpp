/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a class that represents
 * the arithmetic, logic and control unit of a RAM
 */

#ifndef ALCU_CPP
#define ALCU_CPP

#include "include/alcu.h"


Alcu::Alcu() {
  program = Program("ejemplosRAM/test1.ram");
  inTape = InTape("input_tape.in");
  outTape = OutTape("output_tape.out");  
  currState = 0;
  pi = 0;
  currInst = program.getInstruction(pi);  
}

Alcu::Alcu(string programFile, string inputFile, string outputFile) {
  program = Program(programFile);
  inTape = InTape(inputFile);
  outTape = OutTape(outputFile);  
  currState = 0;
  pi = 0;
  currInst = program.getInstruction(pi);  
}

Alcu::~Alcu() {}

void Alcu::run() {
  while(currState != 1 && pi < program.getInstructionsSize()) {
    string operation = currInst.getOpcode();
    if(operation == "READ") read();
    else if(operation == "WRITE") write();
    else if(operation == "JUMP") jump();
    else if(operation == "JZERO") jzero();
    else if(operation == "LOAD") load();

    updateInstruction();
  }
  outTape.load();
}

void Alcu::printCurrentInstruction() {
  cout << program.getInstruction(pi);
}

void Alcu::printMemoryStatus() {
  cout << data;
}

void Alcu::printProgram() {
 cout << program;
}

void Alcu::printInputTape(){
  cout << inTape;
}

void Alcu::printOutputTape() {
  cout << outTape;
}


  void Alcu::load() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());

    if (mode == " ") {
      data.writeAccumulator(data.read(op));
    } 
    else if (mode == "=") {
      data.writeAccumulator(op);
    } 
    else if ( mode == "*") {
      data.writeAccumulator(data.read(data.read(op)));
    }
  }

  void Alcu::store() {

  }

  void Alcu::add() {

  }

  void Alcu::sub() {

  }

  void Alcu::mul() {

  }

  void Alcu::read() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());

    int value = inTape.readTape();
    inTape.moveHead();

    if (mode == " ") {
      data.write(value, op);
    } 
  }

  void Alcu::write() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());  

    if (mode == " ") {
      int value = data.read(op);
      outTape.write(value);
    } 
  }

  void Alcu::jump() {
    string tag = currInst.getOp();
    pi = program.getTagRelativePosition(tag);
    updateInstruction();
  }

  void Alcu::jzero() {
    if(data.readAccumulator() == 0) {
      jump();
    }

  }

  void Alcu::jgtz() {

  }
  
  void Alcu::halt() {
    currState = 1;
  }

#endif