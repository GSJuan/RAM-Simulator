/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: Main file
 * 
 * Execution: $ ./simulator ejemplosRAM/insercion.ram ejemplosRAM/input_tape4.in output_tape.out 1
 *
 */
#include "include/alcu.h"

int main(int argc, char * argv[]) {
  string programFile(argv[1]);
  string inputTape(argv[2]);
  string outputTape(argv[3]);
  int debug(stoi(argv[4]));
  cout << "Debug Mode: " << debug << endl;
  Alcu ram(programFile, inputTape, outputTape, debug);
  ram.run();

  return 0;
}