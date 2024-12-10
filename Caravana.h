#ifndef CARAVANA_H
#define CARAVANA_H


#include "Elemento.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Caravana: public Elemento{
protected:
    int id;
    static int nextID;
    int tripulantes;
    int capacidadeCarga;
    int capacidadeAgua;
    static vector<Caravana*> caravanas;

public:
    Caravana(int x, int y, char tipo, int tripulantes, int capacidadeCarga, int capacidadeAgua);
    string getAsString() const override; //override de elemento
    static const vector<Caravana*> &getCaravanas();

    //getters
    int getID () const;
};



#endif //CARAVANA_H
