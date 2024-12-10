#include <iostream>
#include "Cidade.h"

#include <sstream>

Cidade::Cidade( int x, int y, char tipo)
    : Elemento(x, y, tipo) {}


string Cidade::getAsString() const
{
    ostringstream os;
    os << "Nome: " << tipo <<endl;
    os << "Coordenadas: " << x << ", " << y << endl;

    return os.str();
}
