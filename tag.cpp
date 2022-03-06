/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos alu0101325583@ull.edu.es
 * date: 05/03/2022
 * description: definition a class that represents individual Tags
 * that can be found in ram programs
 *
 */
#ifndef TAG_CPP
#define TAG_CPP

#include "headers/tag.h"

using namespace std;

Tag::Tag() {
  tag = "";
  line = 0;
  column = 0;
}

Tag::Tag(string tag_, int line_, int column_) {
  tag = tag_;
  line = line_;
  column = column_;
}

Tag::~Tag() {}

string Tag::getTag() {
  return tag;
}

int Tag::getLine() {
  return line;
}

int Tag::getColumn() {
  return column;
}

void Tag::modify(Tag new_tag) {
  tag = new_tag.getTag();
  line = new_tag.getLine();
  column = new_tag.getColumn();
}

bool Tag::operator == (Tag& o) {
  return ((getTag() == o.getTag()) && (getLine() == o.getLine()));
}

#endif