#ifndef CIDADE_H
#define CIDADE_H

#include <string>
using namespace std;
#include "Elemento.h"

class Cidade : public Elemento{
private:
    int precoCompra;     // Preço de compra da mercadoria por tonelada
    int precoVenda;      // Preço de venda da mercadoria por tonelada
    string nome;    // Nome da cidade

public:
    // Construtor da Cidade
    Cidade(int x, int y, char tipo);

    // Metodo para acessar o nome da cidade
    string getAsString() const override;
};

#endif //CIDADE_H
