#include "menu.h"
#include "Caravana.h"

int main() {
    // Cria uma instância do menu
    Menu menu;

    // Inicia o menu e o loop do programa
    menu.iniciar();
    Caravana c = *new Caravana(0, 2, 5, 5, 2, 2);


    return 0;
}

