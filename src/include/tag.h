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

      void modify(Tag new_tag);
      
      bool operator == (Tag&);
};

#endif