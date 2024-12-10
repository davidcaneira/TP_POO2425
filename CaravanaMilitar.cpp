#include "CaravanaMilitar.h"


CaravanaMilitar::CaravanaMilitar(int x, int y):Caravana(x, y, 'M', 40, 5, 400){

}

string CaravanaMilitar::getAsString() const
{
    return Caravana::getAsString();
}





