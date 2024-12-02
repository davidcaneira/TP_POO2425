#include "mapa.h"
#include <fstream>
#include <sstream>
#include <iostream>

Mapa::Mapa(): linhas(0), colunas(0), buffer(0, 0) {
}

bool Mapa::carregarMapa(const string &nomeFicheiro) {
    ifstream file(nomeFicheiro);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeFicheiro << endl;
        return false;
    }

    string line;
    bool mapDimensionsRead = false;

    while (getline(file, line)) {
        if (line.find("linhas") < line.size()) {
            istringstream iss(line);
            string valor;
            iss >> valor >> linhas;
        }
        if (line.find("colunas") < line.size()) {
            istringstream iss(line);
            string valor;
            iss >> valor >> colunas;
        }

        if (linhas > 0 && colunas > 0) {
            buffer = Buffer(linhas, colunas);
            mapDimensionsRead = true;
            break;
        }
    }

    if (!mapDimensionsRead) {
        cerr << "As dimensões do mapa não foram encontradas no ficheiro!" << endl;
        return false;
    }

    //Inicializa mapa logico com linhas e colunas
    mapaLogico = new char *[linhas];
    for (int i = 0; i < linhas; i++) {
        mapaLogico[i] = new char[colunas];
    }

    int lineCount = 0;
    while (getline(file, line) && lineCount < linhas) {
        if (line.empty()) continue;
        for (int j = 0; j < colunas && j < line.length(); ++j) {
            mapaLogico[lineCount][j] = line[j]; // Preenche o mapa lógico com os caracteres lidos
        }
        ++lineCount;
    }

    file.close();
    return true;
}

void Mapa::mostrarMapa() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            buffer.moveCursor(i, j);
            buffer << mapaLogico[i][j];
        }
    }
    buffer.mostrarTela();
}

void Mapa::criaElementos() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            char tipo = mapaLogico[i][j];

            if (tipo == '.') {
                // Adiciona um Deserto
                elementos.push_back(new Deserto(i, j, tipo));
            } else if (islower(tipo)) {
                // Para as cidades (quando o tipo é uma letra minúscula)
                std::string nomeCidade = "Cidade_" + std::to_string(i) + "_" + std::to_string(j);

                // Inicializar precoCompra e precoVenda com valores válidos
                int precoCompra = 10 + (i * 2);  // Exemplo de preço de compra
                int precoVenda = 20 + (j * 3);  // Exemplo de preço de venda

                // Cria a cidade e a adiciona ao vetor de elementos
                elementos.push_back(new Cidade(nomeCidade, i, j, precoCompra, precoVenda));
            } else if (isdigit(tipo)) {
                // Se for um número, talvez você queira criar outro tipo de objeto
                // elementos.push_back();
            } else if (tipo == '+') {
                // Adiciona uma Montanha
                elementos.push_back(new Montanha(i, j, tipo));
            }
        }
    }
}

/*
void Mapa::criaElementos() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            char tipo = mapaLogico[i][j];
            if (tipo == '.') {
                elementos.push_back(new Deserto(i, j, tipo));
            } else if (islower(tipo)) {
                std::string nomeCidade = "Cidade_" + std::to_string(i) + "_" + std::to_string(j);
                elementos.push_back(new Cidade(nomeCidade, i, j, precoCompra, precoVenda));
            } else if (isdigit(tipo)) {
                // elementos.push_back();
            } else if (tipo == '+') {
                elementos.push_back(new Montanha(i, j, tipo));
            }
        }
    }
}
*/

const std::vector<Cidade>& Mapa::getCidades() const {
    return cidades;  // Retorna a lista de cidades
}

std::vector<Elemento*>& Mapa::getElementos() {
    return elementos;  // Retorna o vetor de elementos
}

Mapa::~Mapa() {
    // Destruidor (liberação de memória, se necessário)
}