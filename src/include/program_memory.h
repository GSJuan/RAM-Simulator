/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents
 * the program memory of a RAM
 *
 */

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
  
  //returns a certain instruction
  Instruction getInstruction(int);
  
  //return number of instructions
  int getInstructionsSize();

  int getTagRelativePosition(string);

  //Loads content from the file into program memory. 
  //Returns 0 for succes, -1 for error.
  int loadProgram();
  
  //Parses correctly a tag and appends it to the memory
  //Returns the parsed line without the tag
  string parseTag(string line, int absLineNumber, int relLineNumber);

  //checks if a certain Tag is unique by checking if it has already been defined
  //return true if it has not been defined yet, false otherwise
  bool uniqueTag(Tag);

  //checks if a tag is valid to be called (has been declared earlier)
  //returns true if it has been defined earlier
  bool existingTag(string);

  //Parses correctly the instruction of a line and appends it to the memory
  void parseInstruction(string line);
  
  //validates a certain instruction by checking if it is "legal"
  //return true if valid, false otherwise
  bool validateInstruction(Instruction);

  //validates all the instructions that compose the program
  //return true if valid, false otherwise
  bool validateProgram();

  friend ostream& operator<<(ostream& os, const Program& dt);
};
#endif