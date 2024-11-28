#include "buffer.h"
#include <cstring>  // Para usar memset e strlen
#include <iostream>

Buffer::Buffer(int linhas, int colunas): linhas(linhas), colunas(colunas), cursorlinha(0), cursorcoluna(0) {
    tela = new char*[linhas];
    for (int i = 0; i < linhas; i++) {
        tela[i] = new char[colunas];
    }
    limpaBuffer();
}

void Buffer::limpaBuffer() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tela[i][j] = ' ';
        }
    }
}
void Buffer::moveCursor(int linha, int coluna) {
    if (linha>=0 && linha<linhas && coluna>=0 && coluna<colunas) {
        cursorlinha = linha;
        cursorcoluna = coluna;
    }
}

void Buffer::imprimirChar(char c) {
    tela[cursorlinha][cursorcoluna] = c;
    cursorcoluna++;
    if (cursorcoluna >= colunas) {
        cursorcoluna = 0;
        cursorlinha = (cursorlinha + 1) % linhas;
    }
}

void Buffer::imprimirString(const char *str) {
    while (*str != '\0') {
        imprimirChar(*str++);
    }
}
void Buffer::imprimirInt(int i) {
    string str=to_string(i);
    imprimirString(str.c_str());
}

void Buffer::mostrarTela() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // imprimirChar(tela[i][j]);
             cout << tela[i][j];
        }
        cout << endl;
    }
}

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