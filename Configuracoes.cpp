#include "Configuracoes.h"
#include <iostream>
#include <fstream>
#include <sstream>

Configuracoes::Configuracoes() : moedas(1000), preco_compra_mercadoria(1), preco_venda_mercadoria(2),
                                 preco_caravana(100), instantes_entre_novos_itens(10), duracao_item(20),
                                 max_itens(5), instantes_entre_novos_barbaros(40), duracao_barbaros(60) {}

bool Configuracoes::carregarConfiguracoes(const std::string& nomeFicheiro) {
    std::ifstream file(nomeFicheiro);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeFicheiro << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        int value;

        if (line.empty()) continue; // Ignorar linhas vazias

        iss >> key;
        if (iss.fail()) continue; // Se a linha não pode ser lida, ignore

        // Tenta capturar o valor inteiro após a chave
        if (iss >> value) {
            if (key == "moedas") {
                moedas = value;
            } else if (key == "preco_compra_mercadoria") {
                preco_compra_mercadoria = value;
            } else if (key == "preco_venda_mercadoria") {
                preco_venda_mercadoria = value;
            } else if (key == "preco_caravana") {
                preco_caravana = value;
            } else if (key == "instantes_entre_novos_itens") {
                instantes_entre_novos_itens = value;
            } else if (key == "duracao_item") {
                duracao_item = value;
            } else if (key == "max_itens") {
                max_itens = value;
            } else if (key == "instantes_entre_novos_barbaros") {
                instantes_entre_novos_barbaros = value;
            } else if (key == "duracao_barbaros") {
                duracao_barbaros = value;
            }
        }
    }

    file.close();
    return true;
}

// Getters
int Configuracoes::getMoedas() const { return moedas; }
int Configuracoes::getPrecoCompraMercadoria() const { return preco_compra_mercadoria; }
int Configuracoes::getPrecoVendaMercadoria() const { return preco_venda_mercadoria; }
int Configuracoes::getPrecoCaravana() const { return preco_caravana; }
int Configuracoes::getInstantesEntreNovosItens() const { return instantes_entre_novos_itens; }
int Configuracoes::getDuracaoItem() const { return duracao_item; }
int Configuracoes::getMaxItens() const { return max_itens; }
int Configuracoes::getInstantesEntreNovosBarbaros() const { return instantes_entre_novos_barbaros; }
int Configuracoes::getDuracaoBarbaros() const { return duracao_barbaros; }


void Configuracoes::mostrarConfiguracoes() const {
    std::cout << "Moedas: " << moedas << std::endl;
    std::cout << "Preco de Compra de Mercadoria: " << preco_compra_mercadoria << std::endl;
    std::cout << "Preco de Venda de Mercadoria: " << preco_venda_mercadoria << std::endl;
    std::cout << "Preco da Caravana: " << preco_caravana << std::endl;
    std::cout << "Instantes Entre Novos Itens: " << instantes_entre_novos_itens << std::endl;
    std::cout << "Duracao do Item: " << duracao_item << std::endl;
    std::cout << "Maximo de Itens: " << max_itens << std::endl;
    std::cout << "Instantes Entre Novos Barbaros: " << instantes_entre_novos_barbaros << std::endl;
    std::cout << "Duracao dos Barbaros: " << duracao_barbaros << std::endl;
}