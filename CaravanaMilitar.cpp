#include "CaravanaMilitar.h"
#include <iostream>
using namespace std;

// Construtor da Caravana Militar
CaravanaMilitar::CaravanaMilitar(int x, int y)
    : Caravana(x, y, 'M', 40, 5, 400) {  // Tipo 'M' para Caravana Militar
    // Inicialização específica, se necessário
}

//Metodo sobrescrito para mover a caravana militar
void CaravanaMilitar::mover(int dx, int dy) {
    x += dx;  // Atualiza a coordenada X
    y += dy;  // Atualiza a coordenada Y

    std::cout << "Caravana Militar " << id << " movida para a posição (" << x << ", " << y << ").\n";
}

// Metodo sobrescrito para exibir as informações da Caravana Militar
void CaravanaMilitar::getInfo() const {
    std::cout << "Caravana Militar " << id << " na posição (" << x << ", " << y << ").\n"
              << "Tripulantes: " << tripulantes << "/" << maxTripulantes << "\n"
              << "Carga: " << carga << "/" << maxCarga << "\n"
              << "Água: " << agua << "/" << maxAgua << "\n"
              << "Capacidade de ataque: Alta (militar)\n"; // Exemplo de informação adicional
}

// Metodo específico para a Caravana Militar: Atacar
void CaravanaMilitar::atacar() {
    std::cout << "Caravana Militar " << id << " está atacando!\n";
    // Lógica de ataque pode ser adicionada aqui (exemplo de combate com bárbaros)
}
