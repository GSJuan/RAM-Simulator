#ifndef PROGRAM_MEMORY_H
#define PROGRAM_MEMORY_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Program {

  public:
  Program();
  Program(string name);
  ~Program();

  private:
  ifstream program;
  vector<string> instructions;
};
#endif