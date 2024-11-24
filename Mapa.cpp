#include "mapa.h"
#include <fstream>
#include <sstream>
#include <iostream>

Mapa::Mapa() : linhas(0), colunas(0), layout(nullptr) {

}

Mapa::~Mapa() {
    // Libera a memória alocada para o layout
    if (layout) {
        for (int i = 0; i < linhas; ++i) {
            delete[] layout[i];
        }
        delete[] layout;
    }
}

bool Mapa::carregarMapa(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return false;
    }

    std::string line;
    bool mapDimensionsRead = false;

    // Ler as dimensões do mapa (linhas e colunas)
    while (std::getline(file, line)) {
        if (line.find("linhas") != std::string::npos) {
            std::istringstream iss(line);
            std::string key;
            iss >> key >> linhas;
        }
        if (line.find("colunas") != std::string::npos) {
            std::istringstream iss(line);
            std::string key;
            iss >> key >> colunas;
        }

        // Verificar se as dimensões foram lidas
        if (linhas > 0 && colunas > 0) {
            mapDimensionsRead = true;
            break;
        }
    }

    if (!mapDimensionsRead) {
        std::cerr << "Erro: as dimensões do mapa não foram encontradas no arquivo." << std::endl;
        return false;
    }

    layout = new char *[linhas];
    for (int i = 0; i < linhas; ++i) {
        layout[i] = new char[colunas];
    }

    int lineCount = 0;

    while (std::getline(file, line)) {
        // Ignorar linhas vazias
        if (line.empty()) continue;

        // Depois de ler "linhas" e "colunas", começamos a ler o layout do mapa
        if (lineCount < linhas) {
            for (int j = 0; j < colunas; ++j) { // && j < line.length()
                // Garantir que estamos apenas copiando caracteres imprimíveis
                //if (std::isprint(line[j])) {
                layout[lineCount][j] = line[j];
                //} else {
                //    mapa[lineCount][j] = '.';  // Substituir caracteres não imprimíveis por '.'
                //}
            }
            lineCount++;
        }

        // Se já lemos todas as linhas do mapa, podemos parar de processar o arquivo
        if (lineCount >= linhas) {
            break;
        }
    }

    file.close();
    return true;
}


void Mapa::mostrarMapa() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            std::cout << layout[i][j];  // Imprime cada caractere do mapa
        }
        std::cout << std::endl;
    }
}

void Mapa::criaElementosMapa() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            char tipo = layout[i][j];
            if (tipo == '.') {
                elementos.push_back(new Deserto(i, j, tipo));
            } else if (islower(tipo)) {
                elementos.push_back(new Cidade(i, j, tipo));
            } else if (isdigit(tipo)) {
                criaCaravana(i, j, tipo);
            } else if (tipo == '+') {
                elementos.push_back(new Montanha(i, j, tipo));
            }
        }
    }
}

void Mapa::criaCaravana(int x, int y, char num) {
    if (num >= '0' && num <= '3') {
        elementos.push_back(new CaravanaComercio(x, y));
    } else if (num >= '4' && num <= '6') {
        elementos.push_back(new CaravanaMilitar(x, y));
    } else if (num >= '7' && num <= '9') {
        elementos.push_back(new CaravanaSecreta(x, y));
    }
}

Elemento *Mapa::getCidade(char letra) {
    for (auto *elemento: elementos) {
        if (islower(elemento->getTipo())) {
            if (elemento->getTipo() == letra)
                return elemento;
        }
    }
    return nullptr;
}

const std::vector<Elemento *> &Mapa::getElementos() const {
    return elementos;
}

int Mapa::getColunas() const { return colunas; }

int Mapa::getLinhas() const { return linhas; }

Caravana* Mapa::getCaravana(int id) {
    return Caravana::getCaravana(id);
}








/*#include "mapa.h"
#include <fstream>
#include <sstream>
#include <iostream>

Mapa::Mapa() : linhas(0), colunas(0), layout(nullptr) {}

Mapa::~Mapa() {
    // Libera a memória alocada para o layout
    if (layout) {
        for (int i = 0; i < linhas; ++i) {
            delete[] layout[i];
        }
        delete[] layout;
    }
}

bool Mapa::carregarMapa(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return false;
    }

    std::string line;
    bool mapDimensionsRead = false;

    // Ler as dimensões do mapa (linhas e colunas)
    while (std::getline(file, line)) {
        if (line.find("linhas") != std::string::npos) {
            std::istringstream iss(line);
            std::string key;
            iss >> key >> linhas;
        }
        if (line.find("colunas") != std::string::npos) {
            std::istringstream iss(line);
            std::string key;
            iss >> key >> colunas;
        }

        // Verificar se as dimensões foram lidas
        if (linhas > 0 && colunas > 0) {
            mapDimensionsRead = true;
            break;
        }
    }

    if (!mapDimensionsRead) {
        std::cerr << "Erro: as dimensões do mapa não foram encontradas no arquivo." << std::endl;
        return false;
    }

    layout = new char*[linhas];
    for (int i = 0; i < linhas; ++i) {
        layout[i] = new char[colunas];
    }

    int lineCount = 0;

    while (std::getline(file, line)) {
        // Ignorar linhas vazias
        if (line.empty()) continue;

        // Depois de ler "linhas" e "colunas", começamos a ler o layout do mapa
        if (lineCount < linhas) {
            for (int j = 0; j < colunas && j < line.length(); ++j) {
                layout[lineCount][j] = line[j];
            }
            lineCount++;
        }

        // Se já lemos todas as linhas do mapa, podemos parar de processar o arquivo
        if (lineCount >= linhas) {
            break;
        }
    }

    file.close();
    return true;
}

void Mapa::mostrarMapa(Buffer& buffer) const {
    buffer.limpar(); // Esvazia o buffer antes de exibir o novo estado
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            buffer.moverCursor(i, j);
            buffer.imprimirChar(layout[i][j]); // Adiciona cada caractere do mapa ao buffer
        }
    }
    buffer.imprimir(); // Transcreve o conteúdo do buffer para o ecrã
}

void Mapa::atualizarBuffer(Buffer& buffer) const {
    buffer.limpar(); // Esvazia o buffer antes de atualizar
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            buffer.moverCursor(i, j);
            buffer.imprimirChar(layout[i][j]); // Adiciona cada caractere do mapa ao buffer
        }
    }
}

void Mapa::imprimirBuffer(const Buffer& buffer) const {
    buffer.imprimir(); // Transcreve o conteúdo do buffer para o ecrã
}

int Mapa::getColunas() const { return colunas; }
int Mapa::getLinhas() const { return linhas; }
*/