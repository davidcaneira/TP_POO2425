#ifndef PROJETO_ELEMENTO_H
#define PROJETO_ELEMENTO_H


class Elemento {
protected:
    int x, y;
    char tipo; // ('c', '+', '1,' etc)

public:
    Elemento(int x, int y, char tipo);

    //virtual ~Elemento();
    virtual void getInfo();
    int getX() const;
    int getY() const;
    char getTipo() const;

};


#endif //PROJETO_ELEMENTO_H
