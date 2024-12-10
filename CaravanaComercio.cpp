#include "CaravanaComercio.h"


CaravanaComercio::CaravanaComercio(int x, int y):Caravana(x, y, 'C', 20, 40, 200){

}

string CaravanaComercio::getAsString() const
{
    return Caravana::getAsString();
}
