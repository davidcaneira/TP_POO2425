#ifndef MENU_H
#define MENU_H

#include "configuracoes.h"
#include "mapa.h"
#include "buffer.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Menu {
public:
    Menu();
    ~Menu();

    // Funções para Fase 1
    void sair();

    // Funções para Fase 2
    bool iniciarSimulacao(const std::string& nomeFicheiro);
    void executarComandos(const string &nomeFicheiro);
    static void avancarTurnos(int n);
    void comprarCaravana(char cidade, char tipoCaravana);
    void listarPrecos();
    void listarCidade(char cidade);
    void mostrarCaravana(int caravanaId);
    void comprarMercadoria(int caravanaId, int quantidade);
    void venderMercadoria(int caravanaId);
    void moverCaravana(int caravanaId, const string &direcao);
    void colocarAuto(int caravanaId);
    void pararAuto(int caravanaId);
    void criarBarbaro(int linha, int coluna);
    void criarTempestade(int linha, int coluna, int raio);
    void adicionarMoedas(int quantidade);
    void comprarTripulantes(int caravanaId, int quantidade);
    void salvarEstado(const string &nome);
    void carregarEstado(const string &nome);
    void listarEstados();
    void deletarEstado(const string &nome);
    void terminarSimulacao();

    void iniciar();

private:
    Mapa* mapa;          // Ponteiro para o mapa

    // Funções auxiliares para processar comandos
    bool fase1 = true;
    void exibirMenuFase1();
    void exibirMenuFase2();
    void exibirEstado();
};

#endif

