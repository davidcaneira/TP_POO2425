//
// Created by anton on 13/11/2024.
//

#ifndef COMANDOS_H
#define COMANDOS_H

#include <string>

class Comandos {
public:
    Comandos(const std::string& filename); // Construtor para inicializar com o nome do arquivo

    void processar(); // Metodo para processar todos os comandos no arquivo
    void executarComando(const std::string& comando); // Executa um único comando

private:
    std::string nomeArquivo; // Nome do arquivo contendo os comandos
};



#endif //COMANDOS_H
