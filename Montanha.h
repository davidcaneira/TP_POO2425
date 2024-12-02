//
// Created by beatr on 24/11/2024.
//

#ifndef PROJETO_MONTANHA_H
#define PROJETO_MONTANHA_H

#include "Elemento.h"

class Montanha: public Elemento{
public:
    Montanha(int x, int y, char tipo);
    void getInfo();
};


#endif //PROJETO_MONTANHA_H
