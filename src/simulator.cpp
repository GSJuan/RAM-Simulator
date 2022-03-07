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
 * Execution: $ ./simulator ejemplosRAM/test7.ram ejemplosRAM/input_tape4.in output_tape.out
 *
 */
#include "include/alcu.h"

int main(int argc, char * argv[]) {
  string programFile(argv[1]);
  string inputTape(argv[2]);
  string outputTape(argv[3]);

  Alcu ram(programFile, inputTape, outputTape);
  ram.run();
  return 0;
}