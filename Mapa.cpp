#include "mapa.h"
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

int Mapa::getColunas() const { return colunas; }
int Mapa::getLinhas() const { return linhas; }
