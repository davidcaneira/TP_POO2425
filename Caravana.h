//
// Created by anton on 13/11/2024.
//

#ifndef CARAVANA_H
#define CARAVANA_H
#include <iostream>


class Caravana {
    /*
protected:
    int id;                     // Identificador único da caravana
    int tripulantes;            // Número de tripulantes
    int capacidadeCarga;        // Capacidade máxima de carga (em toneladas)
    int capacidadeAgua;         // Capacidade máxima de água (em litros)
    int aguaAtual;              // Água disponível atualmente
    int cargaAtual;             // Carga transportada atualmente
    int posX, posY;             // Posição no mapa
    bool modoAutonomo;          // Indica se a caravana está em modo autonomo

public:
    // Construtor
    Caravana(int id, int tripulantes, int capacidadeCarga, int capacidadeAgua, int posX, int posY);

    virtual void mover(char direcao);        // Move a caravana em uma direção (D, E, C, B, CE, CD, BE, BD)
    virtual void exibirInfo() const;         // Exibe as informações da caravana
    virtual void atualizarEstado();          // Atualiza o estado da caravana (ex.: consumo de água)

    // Getters e setters
    int getId() const;
    int getTripulantes() const;
    void setTripulantes(int valor);
    int getAguaAtual() const;
    void setAguaAtual(int valor);
    int getCargaAtual() const;
    void setCargaAtual(int valor);

    virtual std::string getTipo() const = 0; // Retorna o tipo de caravana (Comércio, Militar, Secreta)
    virtual void comportamentoAutonomo();   // Comportamento específico no modo autônomo

    // Destrutor virtual
    virtual ~Caravana() = default;
    */
};



#endif //CARAVANA_H
