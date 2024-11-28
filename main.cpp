#include "menu.h"
#include "Caravana.h"
#include "Comandos.h"

int main() {
    // Cria uma instância do menu
    Menu menu;

    // Inicia o menu e o loop do programa
    menu.iniciar();
    Caravana c = *new Caravana(0, 2, 5, 5, 2, 2);
    const std::string arquivoComandos = "comandos.txt"; // Nome fixo do arquivo de comandos

    Comandos comandos(arquivoComandos); // Cria um objeto da classe Comandos
    comandos.processar(); // Processa os comandos do arquivo

    return 0;
}

