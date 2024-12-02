#include "menu.h"
#include "Caravana.h"
#include "Comandos.h"

int main() {
    // Criação do objeto Mapa
    Mapa mapa;  // Inicializa o mapa, que contém o vetor de elementos

    // Passa o ponteiro para o Mapa ao criar o Menu
    Menu menu(&mapa);  // Agora Menu tem acesso ao Mapa e pode acessar os elementos

    // Inicia o menu
    menu.iniciar();

    // Criação de uma Caravana (exemplo de como usar)
    Caravana c = *new Caravana(0, 2, 5, 5, 2, 2);

    // Nome do arquivo de comandos
    const std::string arquivoComandos = "comandos.txt";  // Nome fixo do arquivo de comandos

    // Processamento dos comandos do arquivo
    Comandos comandos(arquivoComandos);  // Cria um objeto da classe Comandos
    comandos.processar();  // Processa os comandos do arquivo

    return 0;

    /*
    // Cria uma instância do menu
    Menu menu;

    // Inicia o menu e o loop do programa
    menu.iniciar();
    Caravana c = *new Caravana(0, 2, 5, 5, 2, 2);
    const std::string arquivoComandos = "comandos.txt"; // Nome fixo do arquivo de comandos

    Comandos comandos(arquivoComandos); // Cria um objeto da classe Comandos
    comandos.processar(); // Processa os comandos do arquivo

    return 0;

    */
}

