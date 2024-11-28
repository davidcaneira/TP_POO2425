#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
using namespace std;
class Buffer {
private:
    int linhas;
    int colunas;
    char **tela; //armazena caracteres - matriz bidimensional constituido por linhas e colunas
    int cursorlinha;
    int cursorcoluna;
public:
    Buffer(int linhas, int colunas);
    void limpaBuffer();
    void moveCursor(int linha, int coluna);
    void imprimirChar(char c);
    void imprimirString(const char *str);
    void imprimirInt(int i);
    void mostrarTela();
    Buffer& operator<<(char c);
    Buffer& operator<<(const char *str);
    Buffer& operator<<(int i);
};

#endif
