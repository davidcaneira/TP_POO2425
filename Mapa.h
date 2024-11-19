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

/*#ifndef MAPA_H
#define MAPA_H

#include <string>
#include "buffer.h" // Inclui a classe Buffer

class Mapa {
public:
Mapa();  // Construtor padrão
~Mapa();

bool carregarMapa(const std::string &nomeFicheiro); // Carrega o mapa do arquivo
void mostrarMapa(Buffer& buffer) const; // Exibe o mapa no console usando Buffer
int getColunas() const;
int getLinhas() const;
void atualizarBuffer(Buffer& buffer) const; // Atualiza o buffer com os dados do mapa
void imprimirBuffer(const Buffer& buffer) const; // Imprime o conteúdo do buffer


private:
int linhas;
int colunas;
char **layout; // Matriz bidimensional para armazenar o layout do mapa
};

#endif
*/
