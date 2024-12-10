#include "Caravana.h"

vector<Caravana *> Caravana::caravanas;

int Caravana::nextID = 1;

Caravana::Caravana(int x, int y, char tipo, int tripulantes, int capacidadeCarga, int capacidadeAgua):Elemento(x,y,tipo)
, tripulantes(tripulantes), capacidadeCarga(capacidadeCarga), capacidadeAgua(capacidadeAgua), id(nextID++)
{
    caravanas.push_back(this);
}

string Caravana::getAsString() const
{
    ostringstream oss;
    oss << "Caravana [" << tipo << "] na posicao (" << x << ", " << y << ")" << endl
    << " - Tripulantes: " << tripulantes << endl
    << " - Capacidade de Carga: " << capacidadeCarga << " toneladas" << endl
    << " - Capacidade de Agua: " << capacidadeAgua << " litros" << endl;

    return oss.str();
}

int Caravana::getID() const
{
    return id;
}

const vector<Caravana*>& Caravana::getCaravanas()
{
    return caravanas;
}


