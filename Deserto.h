
#ifndef PROJETO_DESERTO_H
#define PROJETO_DESERTO_H

#include "Elemento.h"

class Deserto: public Elemento{
public:
    Deserto(int x, int y, char tipo);
    void getInfo();
};


#endif //PROJETO_DESERTO_H
