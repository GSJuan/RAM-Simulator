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
  program = Program("ejemplosRAM/test6.ram");
  inTape = InTape("ejemplosRAM/input_tape4.in");
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
    
    if(operation == "READ") {
      read();
      updateInstruction();
    } 
    else if(operation == "WRITE") {
      write();
      updateInstruction();
    } 
    else if(operation == "LOAD") {  
      load();
      updateInstruction();
    } 
    else if(operation == "STORE") {  
      store();
      updateInstruction();
    }
    else if(operation == "ADD") {  
      add();
      updateInstruction();
    }
    else if(operation == "SUB") {  
      sub();
      updateInstruction();
    }
    else if(operation == "MUL") {  
      mul();
      updateInstruction();
    }
    else if(operation == "DIV") {  
      div();
      updateInstruction();
    }  
    else if(operation == "JUMP") {
      jump();
    } 
    else if(operation == "JZERO") {
      jzero();
    } 
    else if(operation == "HALT") {  
      halt(); 
    }
    
    
  }
  outTape.load();
}

void Alcu::updateInstruction() {
  pi++;
  currInst = program.getInstruction(pi);
}

void Alcu::updateInstruction(int ip) {
  pi = ip;
  currInst = program.getInstruction(pi);
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
      int value = data.read(op);
      data.writeAccumulator(value);
      cout << "Loaded " << value << " from register R" << op << " into accumulator" << endl;
    } 
    else if (mode == "=") {
      data.writeAccumulator(op);
      cout << "Loaded " << op << " into accumulator" << endl;
    } 
    else if ( mode == "*") {
      int reg = data.read(op);
      int value = data.read(reg);
      data.writeAccumulator(data.read(reg));

      cout << "Loaded " << value << " from register R" << reg << " obtained from register R" << op << " into accumulator" << endl;

    }
  }

  void Alcu::store() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());
    if (mode == " ") {
      int value = data.readAccumulator();
      data.write(value, op);
      cout << "Loaded " << value << " from accumulator into register R" << op << endl;
    } 
    else if ( mode == "*") {
      int reg = data.read(op);
      int value = data.readAccumulator();

      data.write(value, reg);

      cout << "Loaded " << value << " from accumulator into R" << reg << " obtained from register R" << op << endl;

    }

  }

  void Alcu::add() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());

    if (mode == " ") {
      int value = data.readAccumulator();
      int value2 = data.read(op);
      data.writeAccumulator(value + value2);
      cout << "Loaded " << value << " + " << value2 << " into accumulator" << endl;
    } else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value + op);
      cout << "Loaded " << value << " + " << op << " into accumulator" << endl;
    } else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value + value2);
      cout << "Loaded " << value << " + " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }

  }

  void Alcu::sub() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());

    if (mode == " ") {
      int value = data.readAccumulator();
      int value2 = data.read(op);
      data.writeAccumulator(value - value2);
      cout << "Loaded " << value << " - " << value2 << " into accumulator" << endl;
    } else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value - op);
      cout << "Loaded " << value << " - " << op << " into accumulator" << endl;
    } else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value - value2);
      cout << "Loaded " << value << " - " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }
  }

  void Alcu::mul() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());

    if (mode == " ") {
      int value = data.readAccumulator();
      int value2 = data.read(op);
      data.writeAccumulator(value * value2);
      cout << "Loaded " << value << " * " << value2 << " into accumulator" << endl;
    } else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value * op);
      cout << "Loaded " << value << " * " << op << " into accumulator" << endl;
    } else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value * value2);
      cout << "Loaded " << value << " * " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }
  }

  void Alcu::div() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());

    if (mode == " ") {
      int value = data.readAccumulator();
      int value2 = data.read(op);
      data.writeAccumulator(value / value2);
      cout << "Loaded " << value << " / " << value2 << " into accumulator" << endl;
    } else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value / op);
      cout << "Loaded " << value << " / " << op << " into accumulator" << endl;
    } else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value / value2);
      cout << "Loaded " << value << " / " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }
  }

  void Alcu::read() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());

    int value = inTape.readTape();
    inTape.moveHead();

    if (mode == " ") {
      data.write(value, op);
      cout << "Reading value " << value << " from input tape to register R" << op << endl;
    } else if(mode == "*") {
      int reg = data.read(op);
      data.write(value, reg);
      cout << "Reading value " << value << " from input tape to register R" << reg << " found in register R" << op << endl;
    }
    
  }

  void Alcu::write() {
    string mode = currInst.getMode();
    int op = atoi(currInst.getOp().c_str());  
    
    
    if (mode == " ") {
      int value = data.read(op);
      outTape.write(value);
      cout << "Writing value " << value << " to output tape from register R" << op << endl;
    } 
    else if(mode == "=") {
      outTape.write(op);
      cout << "Writing value " << op << " to output tape" << endl;
    } 
    else if(mode == "*") {
      int reg = data.read(op);
      int value = data.read(reg);
      outTape.write(value);
      cout << "Writing value " << value << " to output tape" << " from register R" << reg << " found in register R" << op << endl;
    }

  }

  void Alcu::jump() {
    string tag = currInst.getOp();
    cout << "Jumped from line " << pi;
    updateInstruction(program.getTagRelativePosition(tag));
    cout << " to line " << pi << " with tag " << tag << endl; 
  }

  void Alcu::jzero() {
    if(data.readAccumulator() == 0) {
      jump();
    } else updateInstruction();
  }

  void Alcu::jgtz() {
    if(data.readAccumulator() > 0) {
      jump();
    } else updateInstruction();
  }
  
  void Alcu::halt() {
    cout << "Halt requested, stopping..." << endl;
    currState = 1;
  }

#endif