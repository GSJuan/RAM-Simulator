#ifndef PROGRAM_MEMORY_H
#define PROGRAM_MEMORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "instruction.h"
#include "tag.h"

using namespace std;

class Program {
  private:
    string fileName;
    vector<Instruction> instructions;
    vector<Tag> tags;

  public:
  //default constructor
  Program();

  //constructor with program file name
  Program(string name);

  //destructor
  ~Program();

  //getter of file name
  string getFileName();
  
  //Loads content from the file into program memory. 
  //Returns 0 for succes, -1 for error.
  int loadContent();
  
  //Parses correctly a tag and appends it to the memory
  //Returns the parsed line without the tag
  string parseTag(string line, int, int);

  //Parses correctly the instruction of a line and appends it to the memory
  void parseInstruction(string line);
};
#endif