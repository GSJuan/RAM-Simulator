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
  debugState = 0;
  executedInstructions = 1;
}

Alcu::Alcu(string programFile, string inputFile, string outputFile, int debug) {
  program = Program(programFile);
  inTape = InTape(inputFile);
  outTape = OutTape(outputFile);  
  currState = 0;
  pi = 0;
  currInst = program.getInstruction(pi);  
  debugState = debug;
  executedInstructions = 1;
}

Alcu::~Alcu() {}

void Alcu::print() {
  cout << endl << "Step " << getExecutedInstructions() << endl;
  cout << "Instruction: " << getCurrInstruction();
  cout << "Data Memory: \n" << getData();
  cout << "Input Tape: " << getInTape();
  cout << "Output Tape: " << getOutTape();
  cout << "Description: ";
}

void Alcu::run() {
  try {
    while(currState != 1 && pi < program.getInstructionsSize()) {
      
      if(debugState == 2) {
        print();
      }

      string type = currInst.getType();
      
      if(type == "READ") {
        read();
        updateInstruction();
      } 
      else if(type == "WRITE") {
        write();
        updateInstruction();
      } 
      else if(type == "LOAD") {  
        load();
        updateInstruction();
      } 
      else if(type== "STORE") {  
        store();
        updateInstruction();
      }
      else if(type == "MATH") {  
        mathFramework();
      }
      else if(type == "JUMP") {
        jumpFramework();
      }
      else if(type == "HALT") {  
        halt(); 
      }
    }
    outTape.load();
  } catch(...) {
    outTape.load();
    cerr << "Fatal Error: some value was illegal. Curr state of the machine: " << endl;
    print();
    exit(2);
  }
}

void Alcu::updateInstruction() {
  pi++;
  currInst = program.getInstruction(pi);
  executedInstructions++;
}

void Alcu::updateInstruction(int ip) {
  pi = ip;
  currInst = program.getInstruction(pi);
  executedInstructions++;
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
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;


    if (mode == " ") {
      if(right.find('[') != std::string::npos) {
        if(right[2] != '=') {
          int reg = right[2];
          reg -= 48;
          int pos = data.read(reg);
          int value = data.read(op, pos);
          data.writeAccumulator(value);
          cout << "Loaded " << value << " from register R" << op << " at position " << pos << " found in R" << reg << " into accumulator" << endl;
        }
        else  {
          int pos = right[3];
          pos -= 48;
          int value = data.read(op, pos);
          data.writeAccumulator(value);
          cout << "Loaded " << value << " from register R" << op << " at position " << pos << " into accumulator" << endl;
        }
      }
      else {
        int value = data.read(op);
        data.writeAccumulator(value);
        cout << "Loaded " << value << " from register R" << op << " into accumulator" << endl;
      }
      
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
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;

    if (mode == " ") {
      if(right.find('[') != std::string::npos) {
        if(right[2] != '=') {
          int reg = right[2];
          reg -= 48;
          int pos = data.read(reg);
          int value = data.readAccumulator();
          data.write(value, op, pos);
          cout << "Loaded " << value << " from accumulator into register R" << op << " at position " << pos << " found in R" << reg << endl;
        }
        else {
          int pos = right[3];
          pos -= 48;
          int value = data.readAccumulator();
          data.write(value, op, pos);
          cout << "Loaded " << value << " from accumulator into register R" << op << " at position " << pos << endl;
        }
      }
      else {
       int value = data.readAccumulator();
        data.write(value, op);
        cout << "Loaded " << value << " from accumulator into register R" << op << endl; 
      }
    } 
    else if ( mode == "*") {
      int reg = data.read(op);
      int value = data.readAccumulator();
      data.write(value, reg);
      cout << "Loaded " << value << " from accumulator into R" << reg << " obtained from register R" << op << endl;
    }
  }

  void Alcu::mathFramework() {
    string operation = currInst.getOpcode();
    if(operation == "ADD") {  
      add();
    }
    else if(operation == "SUB") {  
      sub();
    }
    else if(operation == "MUL") {  
      mul();
    }
    else if(operation == "DIV") {  
      div();
    }  
    updateInstruction();
  }

  void Alcu::add() {
    string mode = currInst.getMode();
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;


    if (mode == " ") {
      if(right.find('[') != std::string::npos) {
        if(right[2] != '=') {
          int reg = right[2];
          reg -= 48;
          int pos = data.read(reg);
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value + value2);
          cout << "Loaded " << value << " + " << value2 << " into accumulator" << " from R" << op << " at position " << pos << " found in R" << reg << endl;
        }
        else {
          int pos = right[3];
          pos -= 48;
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value + value2);
          cout << "Loaded " << value << " + " << value2 << " into accumulator" << " from R" << op << " at position " << pos << endl;
        }
      }
      else{
        int value = data.readAccumulator();
        int value2 = data.read(op);
        data.writeAccumulator(value + value2);
        cout << "Loaded " << value << " + " << value2 << " into accumulator" << endl;
      }
    }
    else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value + op);
      cout << "Loaded " << value << " + " << op << " into accumulator" << endl;
    } 
    else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value + value2);
      cout << "Loaded " << value << " + " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }
  }

  void Alcu::sub() {
    string mode = currInst.getMode();
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;


    if (mode == " ") {
      if(right.find('[') != std::string::npos) {
        if(right[2] != '=') {
          int reg = right[2];
          reg -= 48;
          int pos = data.read(reg);
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value - value2);
          cout << "Loaded " << value << " - " << value2 << " into accumulator" << " from R" << op << " at position " << pos << " found in R" << reg << endl;
        }
        else {
          int pos = right[3];
          pos -= 48;
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value - value2);
          cout << "Loaded " << value << " - " << value2 << " into accumulator" << " from R" << op << " at position " << pos << endl;
        }
      }
      else {
        int value = data.readAccumulator();
        int value2 = data.read(op);
        data.writeAccumulator(value - value2);
        cout << "Loaded " << value << " - " << value2 << " into accumulator" << endl;
      }
    } 
    else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value - op);
      cout << "Loaded " << value << " - " << op << " into accumulator" << endl;
    } 
    else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value - value2);
      cout << "Loaded " << value << " - " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }
  }

  void Alcu::mul() {
    string mode = currInst.getMode();
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;


    if (mode == " ") {
      if(right.find('[') != std::string::npos) {
        if(right[2] != '=') {
          int reg = right[2];
          reg -= 48;
          int pos = data.read(reg);
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value * value2);
          cout << "Loaded " << value << " * " << value2 << " into accumulator" << " from R" << op << " at position " << pos << " found in R" << reg << endl;
        }
        else {
          int pos = right[3];
          pos -= 48;
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value * value2);
          cout << "Loaded " << value << " * " << value2 << " into accumulator" << " from R" << op << " at position " << pos << endl;
        }
      }
      else {
        int value = data.readAccumulator();
        int value2 = data.read(op);
        data.writeAccumulator(value * value2);
        cout << "Loaded " << value << " * " << value2 << " into accumulator" << endl;
      }
    }  
    else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value * op);
      cout << "Loaded " << value << " * " << op << " into accumulator" << endl;
    } 
    else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value * value2);
      cout << "Loaded " << value << " * " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }
  }

  void Alcu::div() {
    string mode = currInst.getMode();
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;


    if (mode == " ") {
      if(right.find('[') != std::string::npos) {
        if(right[2] != '=') {
          int reg = right[2];
          reg -= 48;
          int pos = data.read(reg);
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value / value2);
          cout << "Loaded " << value << " / " << value2 << " into accumulator" << " from R" << op << " at position " << pos << " found in R" << reg << endl;
        }
        else {
          int pos = right[3];
          pos -= 48;
          int value = data.readAccumulator();
          int value2 = data.read(op, pos);
          data.writeAccumulator(value / value2);
          cout << "Loaded " << value << " / " << value2 << " into accumulator" << " from R" << op << " at position " << pos << endl;
        }
      }
      else {
        int value = data.readAccumulator();
        int value2 = data.read(op);
        data.writeAccumulator(value / value2);
        cout << "Loaded " << value << " / " << value2 << " into accumulator" << endl;
      }
    }
    else if( mode == "=") {
      int value = data.readAccumulator();
      data.writeAccumulator(value / op);
      cout << "Loaded " << value << " / " << op << " into accumulator" << endl;
    } 
    else if(mode == "*") {
      int value = data.readAccumulator();
      int reg = data.read(op);
      int value2 = data.read(reg);
      data.writeAccumulator(value / value2);
      cout << "Loaded " << value << " / " << value2 << " from register R" << reg <<  " into accumulator" << endl;
    }
  }

  void Alcu::read() {
    string mode = currInst.getMode();
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;

    int value = inTape.readTape();
    inTape.moveHead();

    if (mode == " ") {
      if(right.find('[') != std::string::npos && right[2] != '=') {
        int pos = right[2];
        pos -= 48;
        data.write(value, op, pos);
        cout << "Reading value " << value << " from input tape to register R" << op << " at position " << pos << endl;
      }
      else {
        data.write(value, op);
        cout << "Reading value " << value << " from input tape to register R " << op << endl;
      }
    } 
    else if(mode == "*") {
      int reg = data.read(op);
      data.write(value, reg);
      cout << "Reading value " << value << " from input tape to register R" << reg << " found in register R" << op << endl;
    }
    
  }

  void Alcu::write() {
    string mode = currInst.getMode();
    string right = currInst.getOp();
    int op = right[0];
    op -= 48;
    
    if (mode == " ") {
      if(right.find('[') != std::string::npos) {
        if(right[2] != '=') {
          int pos = right[2];
          pos -= 48;
          int value = data.read(op, pos);
          outTape.write(value);
          cout << "Writing value " << value << " to output tape from register R" << op << " at position " << pos << endl;
        }
        else {
          int pos = right[3];
          pos -= 48;
          int reg = data.read(op, pos);
          int value = data.read(reg);
          outTape.write(value);
          cout << "Writing value " << value << " to output tape from register R" << reg << " found in R " << op << " at position " << pos << endl;
        } 
      }
      else {
        int value = data.read(op);
        outTape.write(value);
        cout << "Writing value " << value << " to output tape from register R" << op << endl;
      }
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

  void Alcu::jumpFramework() {
    string operation = currInst.getOpcode();
    if(operation == "JUMP") {
      jump();
    } 
    else if(operation == "JZERO") {
      jzero();
    }
    else if(operation == "JGTZ") {
      jgtz();
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
    if(debugState > 0) {
      cout << endl << "Total executed instructions: " << executedInstructions << endl; 
    }
    currState = 1;
  }

ostream& operator<<(ostream& os, const Alcu& dt) {
  os << "Step " << dt.getExecutedInstructions() << endl;
  os << "Instruction: " << dt.getCurrInstruction() << endl;
  os << "Data Memory: " << dt.getData() << endl;
  os << "Input Tape: " << dt.getInTape();
  os << "Output Tape: " << dt.getOutTape();
  return os;
}

#endif