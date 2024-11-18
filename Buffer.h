// buffer.h
#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

class Buffer {
public:
    // Construtor e destrutor
    Buffer(int linhas, int colunas);
    ~Buffer();

    // Esvazia o buffer
    void limpar();

    // Imprime o conteúdo do buffer na consola
    void imprimir() const;

    // Movimenta o cursor para uma posição específica
    void moverCursor(int linha, int coluna);

    // Insere tipos de dados no buffer na posição do cursor
    void imprimirChar(char c);
    void imprimirString(const char* str);
    void imprimirInt(int numero);

    // Sobrecarga do operador << para facilitar o uso
    Buffer& operator<<(char c);
    Buffer& operator<<(const char* str);
    Buffer& operator<<(int numero);

private:
    int linhas;
    int colunas;
    int cursorLinha;
    int cursorColuna;
    char* tela;  // Array unidimensional para armazenar os caracteres

    // Calcula o índice de um caractere com base em linha e coluna
    int calcularIndice(int linha, int coluna) const;
};

#endif
