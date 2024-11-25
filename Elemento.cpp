#include "Elemento.h"
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

void Elemento::getInfo() {

}
