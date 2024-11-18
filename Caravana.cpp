//
// Created by anton on 13/11/2024.
//

#include "Caravana.h"
/*
Caravana::Caravana(int id, int tripulantes, int capacidadeCarga, int capacidadeAgua, int posX, int posY)
    : id(id), tripulantes(tripulantes), capacidadeCarga(capacidadeCarga), capacidadeAgua(capacidadeAgua),
      aguaAtual(capacidadeAgua), cargaAtual(0), posX(posX), posY(posY), modoAutonomo(false) {}

void Caravana::mover(char direcao) {
    switch (direcao) {
    case 'D': posX++; break; // Direita
    case 'E': posX--; break; // Esquerda
    case 'C': posY--; break; // Cima
    case 'B': posY++; break; // Baixo
    case 'CE': posX--; posY--; break; // Cima-Esquerda
    case 'CD': posX++; posY--; break; // Cima-Direita
    case 'BE': posX--; posY++; break; // Baixo-Esquerda
    case 'BD': posX++; posY++; break; // Baixo-Direita
    default:
        std::cout << "Direção inválida!\n";
    }
}

void Caravana::exibirInfo() const {
    std::cout << "Caravana ID: " << id << "\n"
              << "Tipo: " << getTipo() << "\n"
              << "Tripulantes: " << tripulantes << "\n"
              << "Carga Atual: " << cargaAtual << " toneladas\n"
              << "Água Atual: " << aguaAtual << " litros\n"
              << "Posição: (" << posX << ", " << posY << ")\n";
}

void Caravana::atualizarEstado() {
    if (aguaAtual > 0) {
        aguaAtual -= tripulantes; // Consome água com base no número de tripulantes
    } else if (tripulantes > 0) {
        tripulantes--; // Perde tripulantes se ficar sem água
    }
}

int Caravana::getId() const { return id; }
int Caravana::getTripulantes() const { return tripulantes; }
void Caravana::setTripulantes(int valor) { tripulantes = valor; }
int Caravana::getAguaAtual() const { return aguaAtual; }
void Caravana::setAguaAtual(int valor) { aguaAtual = valor; }
int Caravana::getCargaAtual() const { return cargaAtual; }
void Caravana::setCargaAtual(int valor) { cargaAtual = valor; }

*/