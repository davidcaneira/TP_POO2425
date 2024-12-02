#include "Elemento.h"
#include <iostream>
using namespace std;

Elemento::Elemento(int x, int y, char tipo): x(x), y(y), tipo(tipo) {}

int Elemento::getX() const {
    return x;
}

int Elemento::getY() const {
    return y;
}

char Elemento::getTipo() const {
    return tipo;
}

void Elemento::getInfo() const {
    std::cout << "Elemento do tipo '" << tipo << "' na posição (" << x << ", " << y << ").\n";
}
