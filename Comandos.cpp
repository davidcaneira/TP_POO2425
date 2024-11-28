#include "Comandos.h"
#include <iostream>
#include <fstream>
#include <sstream>
// Construtor: inicializa com o nome do arquivo
Comandos::Comandos(const std::string& filename) : nomeArquivo(filename) {}

// Método para processar todos os comandos no arquivo
void Comandos::processar() {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "[Erro] Não foi possível abrir o arquivo: " << nomeArquivo << "\n";
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        // Remove espaços em branco e quebras de linha no final
        linha.erase(linha.find_last_not_of(" \n\r\t") + 1);

        if (!linha.empty()) {
            std::cout << "[Processando] Comando: " << linha << "\n";
            executarComando(linha); // Executa o comando
        }
    }

    arquivo.close();
    std::cout << "[Info] Todos os comandos do arquivo foram processados.\n";
}

// Método para executar um único comando
void Comandos::executarComando(const std::string& comando) {
    std::istringstream iss(comando);
    std::string cmd;
    iss >> cmd;

    if (cmd == "prox") {
        int n = 1; // Valor padrão: 1 turno
        iss >> n;
        std::cout << "[Executando] Avançar a simulação por " << n << " turno(s).\n";
        // Adicione a lógica para avançar turnos aqui
    } else if (cmd == "comprac") {
        char cidade, tipo;
        iss >> cidade >> tipo;
        std::cout << "[Executando] Comprar uma caravana do tipo " << tipo << " na cidade " << cidade << ".\n";
        // Adicione a lógica para comprar caravanas aqui
    } else {
        std::cout << "[Erro] Comando desconhecido: " << comando << "\n";
    }
}