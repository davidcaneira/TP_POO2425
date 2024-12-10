#ifndef CARAVANACOMERCIO_H
#define CARAVANACOMERCIO_H

#include "Caravana.h"
#include <string>
using namespace std;

class CaravanaComercio: public Caravana{

public:
    CaravanaComercio(int x, int y);

    string getAsString() const override;
};



#endif //CARAVANACOMERCIO_H
