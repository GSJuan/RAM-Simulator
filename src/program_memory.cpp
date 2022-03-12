/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: definition file of a class that represents
 * the program memory of a RAM
 *
 */

#ifndef PROGRAM_MEMORY_CPP
#define PROGRAM_MEMORY_CPP

#include "include/program_memory.h"
  
Program::Program() {
  fileName = "ejemplosRAM/test1.ram";
  loadProgram();  
  if(!validateProgram()) exit(-1);

}

Program::Program(string file) {
  fileName = file;
  loadProgram();
  if(!validateProgram()) exit(-1); 
}

Program::~Program() {
  fileName = "";
  tags.clear();
  instructions.clear();
}

string Program::getFileName() {
  return fileName;
}

Instruction Program::getInstruction(int i) {
  return instructions[i];
}

int Program::getInstructionsSize() {
  return instructions.size();
}

int Program::getTagRelativePosition(string tag) {
  for (int i = 0; i < tags.size(); i++) {
    if(tag == tags[i].getTag()) return tags[i].getRelLine();
  }
}

int Program::loadProgram() {

  ifstream file; 
  int absLineNumber = -1;
  int relLineNumber = -1;
  string line; // linea del fichero
  file.open(fileName); //abrimos el fichero de nombre fileName

  if(file.is_open()) { //si se ha abierto correctamente
    while(getline(file, line)) { //mientras se lean lineas del fichero
      absLineNumber++; //aumentamos el indice de lineas del archivo de origen
      line = line.substr(0, line.find_first_of('#')); //eliminamos los comentarios

      if(!line.empty() && (line.find_first_not_of(" \n\r\t\f\v") != string::npos) ) { // si lo sobrante no es una linea vacía
        relLineNumber++; //aumentamos el indice de lineas del programa

        string instruction  = parseTag(line, absLineNumber, relLineNumber); //parseamos la tag si existe y almacenamos la instrucción

        parseInstruction(instruction); //parseamos la instrucción y la almacenamos en el programa
      } 
    }
  } 
  else {
    cerr << endl << "ERROR: unable to open file " << fileName << endl;
    return -1;
  }
  file.close();
  return 0; 
}

string Program::parseTag(string line, int absLineNumber, int relLineNumber) {
  
  //buscamos una etiqueta
  size_t found = line.find_first_of(":"); 

  if(found != string::npos) { //si la hay
    string tag = line.substr(0, found); //la almacenamos

    //eliminamos espacios en blanco
    tag.erase(remove_if(tag.begin(), tag.end(), ::isspace), tag.end()); 

    //la instanciamos como objeto y la almacenamos si es válida
    Tag newTag(tag, absLineNumber, relLineNumber);
    if (uniqueTag(newTag)) tags.push_back(newTag); 
    else cerr << endl << "ERROR: Tag " << newTag.getTag() << " already defined!! Ignoring it..." << endl;
   
    //eliminamos la tag de la linea para dejar el resto
    line = line.substr(line.find_first_of(':') + 1); 
  }

  //devolemos la linea
  return line;
}

bool Program::uniqueTag(Tag tag) {
  //comprobamos que no haya sido definida previamente
  for (int i = 0; i < tags.size(); i++) {
    if(tag == tags[i]) return false;
  }
  return true;
}

bool Program::existingTag(string tag) {
  //comprobamos que no haya sido definida previamente
  for (int i = 0; i < tags.size(); i++) {
    if(tag == tags[i].getTag()) return true;
  }
  return false;
}


void Program::parseInstruction(string instruction) {

  string mode = " "; //modo directo por defecto
  
  //eliminamos todos los espacios a la izquierda de la instruccion
  size_t  lPos = instruction.find_first_not_of(" \n\r\t\f\v"); 
  instruction = instruction.substr(lPos != std::string::npos ? lPos : 0);

  //separamos la instruccion por partes y pasamos la operación a mayúsculas por convenio
  string operation = instruction.substr(0, instruction.find_first_of(' '));
  transform(operation.begin(), operation.end(), operation.begin(), ::toupper);

  // comprobamos que quede el modo y el operador, en caso contrario, los completa con una cadena vacia 
  string op = instruction.find_first_of(' ') != string::npos? instruction.substr(instruction.find_first_of(' ') + 1) : "";
  
  //si el primer caracter no es el propio operando, especificamos un medo que no sea el "directo"
  if(op[0] == '*' || op[0] == '=') { //modo indirecto o constante
    mode = op[0];
    op = op.substr(1);
  }

  string type = " ";
  if(operation == "JUMP" || operation == "JZERO" || operation == "JGTZ" ) {
    type = "JUMP";
  }
  else if(operation == "ADD" || operation == "SUB" || operation == "MUL" || operation == "DIV") {
    type = "MATH";
  }
  else type = operation;
    
  //almacenamos la instrucción
  instructions.push_back(Instruction(operation, mode, op, type));
}


bool Program::validateInstruction(Instruction instruction) {
  string operation = instruction.getOpcode();
  string mode = instruction.getMode();
  string op = instruction.getOp();
  if((operation == "STORE" || operation == "READ") && (mode == "=")) {
    cerr << endl << "ERROR: Operation " << operation << " does not support constant values" << endl;
    return false;
  }
  else if ((operation == "JUMP" || operation == "JZERO" || operation == "JGTZ") && (!existingTag(op))) {
    cerr << endl << "ERROR: Tag " << op  << "is not defined in the program" <<endl;
    return false;
  } 
  else if ((operation == "WRITE" || operation == "READ") && (mode == " ") && (op == "0")) {
    cerr << endl << "ERROR: operation " << operation << " does not suport direct access to R0 (acummulator)" <<endl;
    return false;
  } 
  else if((operation == "HALT") && (!op.empty())) {
    cerr << endl   << "ERROR: HALT must called alone" <<endl;
    return false;
  }
  else if(!existingOperation(operation)) {
    cerr << endl   << "ERROR: operation " << operation << "is not defined in the instructions set." << endl;
    return false;
  }
  else return true;
}

bool Program::existingOperation(string operation) {
  if((operation != "LOAD") && (operation != "STORE") && (operation != "READ") && (operation != "WRITE") &&
  (operation != "ADD") && (operation != "SUB") && (operation != "MUL") && (operation != "DIV") &&
  (operation != "JUMP") && (operation != "JZERO")&&(operation != "JGTZ") && (operation != "HALT")) {
    return false;
  }
  else return true;
}


bool Program::validateProgram() {
  for(int i = 0; i < instructions.size(); i++) {
    if(!validateInstruction(instructions[i])) return false;
  }
  return true;
}

ostream& operator<<(ostream& os, const Program& program) {
  os << "Program Information:" << endl;
  os << "Instructions: " << program.instructions.size() << endl;
  os << "Tags: " << program.tags.size() << endl;
  os << "Code: " << endl;
  int tagIndex = 0;
  for(int i = 0; i < program.instructions.size(); i++) {
    os << "\t";
    if(program.tags[tagIndex].getRelLine() == i) {
      os << program.tags[tagIndex] << ":";
      tagIndex++;
    }
    os << "\t" <<  program.instructions[i];
  } 
  return os;
}

#endif