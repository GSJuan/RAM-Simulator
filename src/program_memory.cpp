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
  int absLineNumber = -1;
  int relLineNumber = -1;
  string line; // linea del fichero
  file.open(fileName); //abrimos el fichero de nombre fileName

  if(file.is_open()) { //si se ha abierto correctamente
    while(getline(file, line)) { //mientras se lean lineas del fichero
      absLineNumber++; //aumentamos el indice de lineas del archivo de origen
      line = line.substr(0, line.find_first_of('#')); //eliminamos los comentarios

      if(!line.empty()) { // si lo sobrante no es una linea vacía
        relLineNumber++; //aumentamos el indice de lineas del programa

        string instruction  = parseTag(line, absLineNumber, relLineNumber);

        parseInstruction(instruction);
      } 
    }
  } 
  else {
    cout << "unable to open file" << endl;
    return -1;
  }
  file.close();
  return 0; 
}

string Program::parseTag(string line, int absLineNumber, int relLineNumber) {
  size_t found = line.find_first_of(":"); //buscamos una etiqueta

  if(found != string::npos) { //si la hay
    string tag = line.substr(0, found); //la almacenamos

    tag.erase(remove_if(tag.begin(), tag.end(), ::isspace), tag.end()); //eliminamos espacios en blanco

    tags.push_back(Tag(tag, absLineNumber, relLineNumber)); //la instanciamos como objeto y lo añadimos al vector
    
    line = line.substr(line.find_first_of(':') + 1); //eliminamos la tag de la linea para dejar el resto
  }
  return line;
}

void Program::parseInstruction(string instruction) {

  string mode = " ";

  size_t  lPos = instruction.find_first_not_of(" \n\r\t\f\v"); 
  instruction = instruction.substr(lPos != std::string::npos ? lPos : 0);

  string operation = instruction.substr(0, instruction.find_first_of(' '));
  for (auto & c: operation) c = toupper(c);

  string op = instruction.substr(instruction.find_first_of(' ') + 1);

  if(op[0] == '*' || op[0] == '='){
    mode = op[0];
    op = op.substr(1);
  }

  instructions.push_back(Instruction(operation, mode, op));
}