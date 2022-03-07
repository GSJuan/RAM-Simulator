/*
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y análisis de algoritmos
 *
 * author: Juan García Santos
 * date: 05/03/2022
 * description: header file of a class that represents
 * individual tags that can be found in ram programs
 *
 */

#ifndef TAG_H
#define TAG_H

#include <string>
#include <iostream>

using namespace std;

class Tag {
    private:
      string tag;
      int absLine;
      int relLine;
    
    public:
      Tag();
      Tag(string, int, int);
      ~Tag();

      string getTag();
      int getAbsLine();
      int getRelLine();

      string getTag() const;
      int getAbsLine() const;
      int getRelLine() const;

      void modify(Tag new_tag);
      
      bool operator == (Tag&);

      friend ostream& operator<<(ostream& os, const Tag& dt);
};

#endif