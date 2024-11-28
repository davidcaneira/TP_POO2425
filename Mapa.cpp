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
                elementos.push_back(new Deserto(i, j, tipo));
            } else if (islower(tipo)) {
                elementos.push_back(new Cidade(i, j, tipo));
            } else if (isdigit(tipo)) {
                // elementos.push_back();
            } else if (tipo == '+') {
                elementos.push_back(new Montanha(i, j, tipo));
            }
        }
    }
}