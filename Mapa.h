#ifndef MAPA_H
#define MAPA_H

#include <string>
#include <vector>

class Mapa {
public:
    Mapa();  // Construtor padrão
    ~Mapa();

    bool carregarMapa(const std::string &nomeFicheiro); // Carrega o mapa do arquivo
    void mostrarMapa() const; // Exibe o mapa no console
    int getColunas() const;
    int getLinhas() const;


private:
    int linhas;
    int colunas;
    char **layout; // Matriz bidimensional para armazenar o layout do mapa
};

#endif
