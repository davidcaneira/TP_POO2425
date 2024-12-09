#include <iostream>
#include "Cidade.h"
using namespace std;

Cidade::Cidade( int x, int y, char tipo)
    : Elemento(x, y, tipo) {}

int Cidade::getPrecoCompra() const {
    return precoCompra;
}

int Cidade::getPrecoVenda() const {
    return precoVenda;
}

void Cidade::exibirPrecos() const {
    std::cout << "Preços da cidade " << getNome() << " (Posicao: " << getX() << ", " << getY() << "):\n";
    std::cout << "Compra: " << precoCompra << " moedas por tonelada\n";
    std::cout << "Venda: " << precoVenda << " moedas por tonelada\n";
}

std::string Cidade::getNome() const {
    return nome;
}

