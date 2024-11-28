#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H

#include <string>

class Configuracoes {
    int moedas;
    int preco_compra_mercadoria;
    int preco_venda_mercadoria;
    int preco_caravana;
    int instantes_entre_novos_itens;
    int duracao_item;
    int max_itens;
    int instantes_entre_novos_barbaros;
    int duracao_barbaros;

public:
    // Construtor
    Configuracoes();

    // Metodo para carregar as configurações a partir de um arquivo
    bool carregarConfiguracoes(const std::string& nomeFicheiro);

    // Métodos getters para acessar os valores
    int getMoedas() const;
    int getPrecoCompraMercadoria() const;
    int getPrecoVendaMercadoria() const;
    int getPrecoCaravana() const;
    int getInstantesEntreNovosItens() const;
    int getDuracaoItem() const;
    int getMaxItens() const;
    int getInstantesEntreNovosBarbaros() const;
    int getDuracaoBarbaros() const;

    void mostrarConfiguracoes() const;

};

#endif // CONFIGURACOES_H

