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

#include "include/tag.h"

using namespace std;

Tag::Tag() {
  tag = "";
  absLine = 0;
  relLine = 0;
}

Tag::Tag(string tag_, int absLine_, int relLine_) {
  tag = tag_;
  absLine = absLine_;
  relLine = relLine_;
}

Tag::~Tag() {}

string Tag::getTag() {
  return tag;
}

int Tag::getAbsLine() {
  return absLine;
}

int Tag::getRelLine() {
  return relLine;
}

string Tag::getTag() const {
  return tag;
}

int Tag::getAbsLine() const {
  return absLine;
}

int Tag::getRelLine() const {
  return relLine;
}

void Tag::modify(Tag new_tag) {
  tag = new_tag.getTag();
  absLine = new_tag.getAbsLine();
  relLine = new_tag.getRelLine();
}

bool Tag::operator == (Tag& o) {
  return ((getTag() == o.getTag()) && (getAbsLine() == o.getAbsLine()));
}

ostream& operator<<(ostream& os, const Tag& tag) {
  os << tag.getTag();
  return os;
}

#endif