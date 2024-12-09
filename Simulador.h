#ifndef MENU_H
#define MENU_H

#include "configuracoes.h"
#include "mapa.h"
#include "buffer.h"
#include <sstream>
#include <fstream>

class Simulador {
private:
    Mapa* mapa;
public:
    Simulador();
    ~Simulador();
    void iniciaFase1();
    void exibirMenuFase1();
    bool iniciarSimulacao(const string &nomeFicheiro);
    void escolheComandoFase2();
    void exibirMenuFase2();
    bool verificaComando (const string &comando);
    bool executaComandosFicheiro(const string &comando);
    bool avancaTurnos (const string &comando);
    bool compraCaravana (const string &comando);
    bool listaPrecosMercadorias (const string &comando);
    bool listaInfoCidade (const string &comando);
    bool mostraInfoCaravana (const string &comando);
    bool compraMercadorias (const string &comando);
    bool vendeMercadoria (const string &comando);
    bool moveCaravana (const string &comando);
    bool autoCaravana (const string &comando);
    bool stopAutoCaravana (const string &comando);
    bool criaCaravanaBarbara (const string &comando);
    bool criaTempestade (const string &comando);
    bool adicionaMoedas (const string &comando);
    bool compraTripulantes (const string &comando);
    bool copiaBuffer (const string &comando);
    bool recuperaCopiaBuffer (const string &comando);
    bool listaCopias (const string &comando);
    bool eliminaCopiaBuffer (const string &comando);


};

#endif

