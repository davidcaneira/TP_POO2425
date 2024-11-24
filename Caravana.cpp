//
// Created by anton on 13/11/2024.
//

#include "Caravana.h"

int Caravana::nextId = 1;
std::vector<Caravana*> Caravana::caravanas;


//Caravana::Caravana(int id, int tripulantes, int capacidadeCarga, int capacidadeAgua, int posX, int posY)
//    : id(id), tripulantes(tripulantes), capacidadeCarga(capacidadeCarga), capacidadeAgua(capacidadeAgua),
//      aguaAtual(capacidadeAgua), cargaAtual(0), posX(posX), posY(posY), modoAutonomo(false) {}

Caravana::Caravana(int x, int y, char tipo, int tripulantes, int capacidadeCarga, int capacidadeAgua): Elemento(x,y,tipo),
tripulantes(tripulantes),capacidadeCarga(capacidadeCarga),capacidadeAgua(capacidadeAgua),id(nextId++) {
    caravanas.push_back(this);
}

void Caravana::atualizarEstado() {
    if (aguaAtual > 0) {
        aguaAtual -= tripulantes; // Consome água com base no número de tripulantes
    } else if (tripulantes > 0) {
        tripulantes--; // Perde tripulantes se ficar sem água
    }
}
void Caravana::getInfo() {
    std::cout << "Caravana ID: " << id << ", Tipo: " << tipo
              << ", Pos: (" << x << ", " << y << ")"
              << ", Tripulantes: " << tripulantes
              << ", Carga: " << capacidadeCarga
              << ", Água: " << capacidadeAgua << '\n';
}

Caravana* Caravana::getCaravana(int id) {
    for(auto* caravana: caravanas){
        if(caravana->id == id){
            return caravana;
        }
    }
    return nullptr;
}


int Caravana::getId() const { return id; }
int Caravana::getTripulantes() const { return tripulantes; }
void Caravana::setTripulantes(int valor) { tripulantes = valor; }
int Caravana::getAguaAtual() const { return aguaAtual; }
void Caravana::setAguaAtual(int valor) { aguaAtual = valor; }
int Caravana::getCargaAtual() const { return cargaAtual; }
void Caravana::setCargaAtual(int valor) { cargaAtual = valor; }

void Caravana::comportamentoAutonomo() {

}







