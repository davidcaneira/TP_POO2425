#ifndef MAPA_H
#define MAPA_H

#include <string>
#include <vector>

#include "Buffer.h"
#include "Cidade.h"
#include "Deserto.h"
#include "Montanha.h"
#include "Caravana.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"


class Mapa{
    int linhas;
    int colunas;
    Buffer buffer;
    char** mapaLogico;
    vector<Elemento*> elementos; // Vetor de elementos (privado)
    std::vector<Cidade> cidades; // Lista de cidades
public:
    Mapa();
    ~Mapa();  // Destrutor
    bool carregarMapa(const string &nomeFicheiro);
    void mostrarMapa();
    void criaElementos();
    const std::vector<Cidade>& getCidades() const; // // Metodo que retorna todas as cidades
    std::vector<Elemento*>& getElementos(); // Retorna o vetor de elementos

};

#endif
