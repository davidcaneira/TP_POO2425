#ifndef CARAVANAMILITAR_H
#define CARAVANAMILITAR_H

#include "Caravana.h"


class CaravanaMilitar : public Caravana {

public:
    CaravanaMilitar(int x, int y);  // Construtor

    // Sobrescreve os métodos de Caravana
    void mover(int dx, int dy) override;   // Movimentação específica para Caravana Militar
    void getInfo() const override;          // Exibe informações específicas da Caravana Militar
    void atacar();                          // Comportamento específico de ataque (exemplo)

};



#endif //CARAVANAMILITAR_H
