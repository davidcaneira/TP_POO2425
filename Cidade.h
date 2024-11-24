#ifndef CIDADE_H
#define CIDADE_H


#include "Elemento.h"

class Cidade : public Elemento{
public:
    Cidade(int x, int y, char tipo);
    void getInfo() override;
};



#endif //CIDADE_H
