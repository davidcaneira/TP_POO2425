#ifndef MAPA_H
#define MAPA_H

#include <string>
#include <vector>
#include "Cidade.h"
#include "Deserto.h"
#include "Montanha.h"
#include "Caravana.h"
#include "CaravanaComercio.h"
#include "CaravanaMilitar.h"
#include "CaravanaSecreta.h"


class Mapa {
public:
    Mapa();  // Construtor padrão
    ~Mapa();
    bool carregarMapa(const std::string &nomeFicheiro); // Carrega o mapa do arquivo
    void mostrarMapa() const; // Exibe o mapa no console
    int getColunas() const;
    int getLinhas() const;
    void criaElementosMapa();
    const std::vector<Elemento *> &getElementos() const;
    Elemento * getCidade(char letra);
    void criaCaravana(int x, int y, char num);
    Caravana* getCaravana(int id);

private:
    std::vector<Elemento*> elementos; //todos os elementos do mapa

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
