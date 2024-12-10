#include "CaravanaSecreta.h"


CaravanaSecreta::CaravanaSecreta(int x, int y):Caravana(x, y, 'S', 20, 40, 200){

}

string CaravanaSecreta::getAsString() const
{
    return Caravana::getAsString();
}
