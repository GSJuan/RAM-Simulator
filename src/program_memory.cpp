#include "include/program_memory.h"
  
Program::Program() {
  fileName = "ejemplosRAM/test1.ram";
  loadContent();  
}

Program::Program(string file) {
  fileName = file;
  loadContent();  
}

Program::~Program() {
  fileName = "";
  tags.clear();
  instructions.clear();
}

string Program::getFileName() {
  return fileName;
}

int Program::loadContent() {

  ifstream file; //fichero
  string line; // linea del fichero
  file.open(fileName); //abrimos el fichero de nombre fileName

  if(file.is_open()) { //si se ha abierto correctamente
    while(getline(file, line)) { //mientras se lean lineas del fichero

      line = line.substr(0, line.find_first_of('#')); //eliminamos los comentarios
      if(!line.empty()) {// si lo sobrante no es una linea vacía
        cout << line << endl; 
      } 
    }
    file.close();
  } 
  else {
    cout << "unable to open file" << endl;
    return -1;
  }

  return 0; 
}