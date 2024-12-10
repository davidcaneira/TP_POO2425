#ifndef CARAVANAMILITAR_H
#define CARAVANAMILITAR_H

#include "Caravana.h"


class CaravanaMilitar : public Caravana {
    public:
    CaravanaMilitar(int x, int y);
    string getAsString() const override;
};



#endif //CARAVANAMILITAR_H
