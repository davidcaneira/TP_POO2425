//
// Created by anton on 13/11/2024.
//

#ifndef CARAVANA_H
#define CARAVANA_H
#include <iostream>
#include <vector>

#include "Elemento.h"

class Caravana: public Elemento{

protected:
    int id;                     // Identificador único da caravana
    static int nextId;
    static std::vector<Caravana*> caravanas;
    int tripulantes;            // Número de tripulantes
    int capacidadeCarga;        // Capacidade máxima de carga (em toneladas)
    int capacidadeAgua;         // Capacidade máxima de água (em litros)
    int aguaAtual;              // Água disponível atualmente
    int cargaAtual;             // Carga transportada atualmente
    int posX, posY;             // Posição no mapa
    bool modoAutonomo;          // Indica se a caravana está em modo autonomo

public:
    // Construtor
  //  Caravana(int id, int tripulantes, int capacidadeCarga, int capacidadeAgua, int posX, int posY);
    Caravana(int x, int y, char tipo, int tripulantes, int capacidadeCarga, int capacidadeAgua);
    static Caravana* getCaravana(int id);
    void getInfo() override;


    virtual void atualizarEstado();          // Atualiza o estado da caravana (ex.: consumo de água)

    // Getters e setters
    int getId() const;
    int getTripulantes() const;
    void setTripulantes(int valor);
    int getAguaAtual() const;
    void setAguaAtual(int valor);
    int getCargaAtual() const;
    void setCargaAtual(int valor);

    //virtual std::string getTipo() const = 0; // Retorna o tipo de caravana (Comércio, Militar, Secreta)
    virtual void comportamentoAutonomo();   // Comportamento específico no modo autônomo

    // Destrutor virtual
    virtual ~Caravana() = default;

};



#endif //CARAVANA_H
