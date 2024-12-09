#ifndef CIDADE_H
#define CIDADE_H

#include <string>
#include "Elemento.h"

class Cidade : public Elemento{
private:
    int precoCompra;     // Preço de compra da mercadoria por tonelada
    int precoVenda;      // Preço de venda da mercadoria por tonelada
    std::string nome;    // Nome da cidade

public:
    // Construtor da Cidade
    Cidade(int x, int y, char tipo);

    // Métodos para acessar os preços
    int getPrecoCompra() const;
    int getPrecoVenda() const;

    // Metodo para exibir os preços
    void exibirPrecos() const;

    // Metodo para acessar o nome da cidade
    std::string getNome() const;
};



#endif //CIDADE_H
