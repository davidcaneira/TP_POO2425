#include <iostream>
#include "Cidade.h"
using namespace std;

Cidade::Cidade(std::string nome, int x, int y, int precoCompra, int precoVenda)
    : Elemento(x, y, 'C'), precoCompra(precoCompra), precoVenda(precoVenda), nome(nome) {}

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

