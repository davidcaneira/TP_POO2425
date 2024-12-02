#include "Caravana.h"
#include <iostream>
#include <algorithm>  // Para usar std::find
using namespace std;

// Inicialização dos membros estáticos
int Caravana::nextId = 1;                  // Inicializa o próximo ID
std::vector<Caravana*> Caravana::caravanas; // Lista de todas as caravanas

// Construtor da classe Caravana
Caravana::Caravana(int x, int y, char tipo, int maxTripulantes, int maxCarga, int maxAgua)
    : Elemento(x, y, tipo), id(nextId++), tripulantes(maxTripulantes), maxTripulantes(maxTripulantes),
      carga(0), maxCarga(maxCarga), agua(maxAgua), maxAgua(maxAgua) {
    caravanas.push_back(this); // Adiciona a caravana à lista estática de caravanas
}

// Destrutor da classe Caravana
Caravana::~Caravana() {
    // Remove a caravana da lista estática quando for destruída
    auto it = std::find(caravanas.begin(), caravanas.end(), this);
    if (it != caravanas.end()) {
        caravanas.erase(it);
    }
}

//Metodo para mover a caravana
void Caravana::mover(int dx, int dy) {
    x += dx;  // Atualiza a coordenada X
    y += dy;  // Atualiza a coordenada Y

    std::cout << "Caravana " << id << " movida para a posição (" << x << ", " << y << ").\n";
}

//Metodo para exibir as informações da caravana
void Caravana::getInfo() const {
    std::cout << "Caravana " << id << " (tipo '" << tipo << "') na posição (" << x << ", " << y << ").\n"
              << "Tripulantes: " << tripulantes << "/" << maxTripulantes << "\n"
              << "Carga: " << carga << "/" << maxCarga << "\n"
              << "Água: " << agua << "/" << maxAgua << "\n";
}

//Metodo para obter o ID da caravana
int Caravana::getId() const {
    return id;
}

//Metodo estático para obter todas as caravanas
const std::vector<Caravana*>& Caravana::getCaravanas() {
    return caravanas;
}

/*
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
*/








