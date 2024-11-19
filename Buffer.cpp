#include "buffer.h"
#include <cstring>  // Para usar memset e strlen
#include <iostream>

// Construtor: inicializa o buffer com espaços
Buffer::Buffer(int linhas, int colunas)
    : linhas(linhas), colunas(colunas), cursorLinha(0), cursorColuna(0) {
    // Alocação dinâmica para o array bidimensional
    tela = new char*[linhas];
    for (int i = 0; i < linhas; ++i) {
        tela[i] = new char[colunas];
    }
    limpar();  // Inicializa o buffer com espaços
}

// Destrutor: libera a memória alocada para o buffer
Buffer::~Buffer() {
    for (int i = 0; i < linhas; ++i) {
        delete[] tela[i];
    }
    delete[] tela;
}

// Esvazia o buffer (preenche com espaços)
void Buffer::limpar() {
    for (int i = 0; i < linhas; ++i) {
        memset(tela[i], ' ', colunas);
    }
}

// Imprime o conteúdo do buffer na consola
void Buffer::imprimir() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            std::cout << tela[i][j];
        }
        std::cout << '\n';
    }
}

// Move o cursor para uma posição específica
void Buffer::moverCursor(int linha, int coluna) {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        cursorLinha = linha;
        cursorColuna = coluna;
    }
}

// Imprime um caractere na posição do cursor e move o cursor
void Buffer::imprimirChar(char c) {
    tela[cursorLinha][cursorColuna] = c;
    cursorColuna++;
    if (cursorColuna >= colunas) {
        cursorColuna = 0;
        cursorLinha = (cursorLinha + 1) % linhas;
    }
}

// Imprime uma string na posição do cursor e move o cursor
void Buffer::imprimirString(const char* str) {
    while (*str) {
        imprimirChar(*str++);
    }
}

// Imprime um número inteiro na posição do cursor e move o cursor
void Buffer::imprimirInt(int numero) {
    char buffer[12];  // Suporta até inteiros grandes
    snprintf(buffer, sizeof(buffer), "%d", numero);
    imprimirString(buffer);
}

// Sobrecarga do operador << para char
Buffer& Buffer::operator<<(char c) {
    imprimirChar(c);
    return *this;
}

// Sobrecarga do operador << para strings
Buffer& Buffer::operator<<(const char* str) {
    imprimirString(str);
    return *this;
}

// Sobrecarga do operador << para inteiros
Buffer& Buffer::operator<<(int numero) {
    imprimirInt(numero);
    return *this;
}
