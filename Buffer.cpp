#include "buffer.h"
#include <cstring>  // Para usar memset e strlen
#include <iostream>

//Construtor
Buffer::Buffer(int linhas, int colunas): linhas(linhas), colunas(colunas), cursorlinha(0), cursorcoluna(0) {
    tela = new char*[linhas];
    for (int i = 0; i < linhas; i++) {
        tela[i] = new char[colunas];
    }
    limpaBuffer();
}

//Destrutor
Buffer::~Buffer() {
    for (int i = 0; i < linhas; i++) {
        delete[] tela[i];
    }
    delete[] tela;
}

//Limpa o buffer e preenche com espaços vazios
void Buffer::limpaBuffer() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tela[i][j] = ' ';
        }
    }
}

//Move o cursor para uma nova posição
void Buffer::moveCursor(int linha, int coluna) {
    if (linha>=0 && linha<linhas && coluna>=0 && coluna<colunas) {
        cursorlinha = linha;
        cursorcoluna = coluna;
    }
}

//Imprime um caractere na posição atual do cursor
void Buffer::imprimirChar(char c) {
    tela[cursorlinha][cursorcoluna] = c;
    cursorcoluna++;
    if (cursorcoluna >= colunas) {
        cursorcoluna = 0;
        cursorlinha = (cursorlinha + 1) % linhas;
    }
}

//Imprime uma string
void Buffer::imprimirString(const char *str) {
    while (*str != '\0') {
        imprimirChar(*str++);
    }
}

//Imprime um inteiro
void Buffer::imprimirInt(int i) {
    string str=to_string(i);
    imprimirString(str.c_str());
}

// Mostra o conteúdo do buffer na tela
void Buffer::mostrarTela() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // imprimirChar(tela[i][j]);
             cout << tela[i][j];
        }
        cout << endl;
    }
}

// Sobrecarga do operador <<
Buffer& Buffer::operator<<(char c) {
    imprimirChar(c);
    return *this;
}

Buffer& Buffer::operator<<(const char *str) {
    imprimirString(str);
    return *this;
}

Buffer& Buffer::operator<<(int i) {
    imprimirInt(i);
    return *this;
}
