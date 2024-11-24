#include <iostream>
#include "Cidade.h"

Cidade::Cidade(int x, int y, char tipo): Elemento(x, y, tipo) {

}

void Cidade::getInfo() {
    std::cout << "Estou na posicao: " << x <<"," << y;
}

