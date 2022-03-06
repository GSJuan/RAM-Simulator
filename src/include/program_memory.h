#ifndef PROGRAM_MEMORY_H
#define PROGRAM_MEMORY_H

#include <iostream>
#include <fstream>
#include <vector>

#include "instruction.h"
#include "tag.h"

using namespace std;

class Program {
  private:
    string fileName;
    vector<Instruction> instructions;
    vector<Tag> tags;

  public:
  Program();
  Program(string name);
  ~Program();

  string getFileName();

  int loadContent();

  
};
#endif