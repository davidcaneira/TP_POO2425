#ifndef PROJETO_ELEMENTO_H
#define PROJETO_ELEMENTO_H

#include <iostream>

class Elemento {
protected:
    int x, y; //coordenadas Mapa
    char tipo; // ('c', '+', '1,' etc)

public:
    Elemento(int x, int y, char tipo);

    virtual ~Elemento() = default; //Destrutor virtual para suporte de herança
    virtual void getInfo() const; //Pode ser escrito por cima por derivadas

    //Métodos de consulta
    int getX() const;
    int getY() const;
    char getTipo() const;

    virtual std::string getAsString() const;

};


#endif //PROJETO_ELEMENTO_H
