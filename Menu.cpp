#include "menu.h"

// Construtor e destruidor
Menu::Menu() {
    mapa = nullptr;
}

Menu::~Menu() {
    delete mapa;
}

// Função principal
void Menu::iniciar() {
    string comando;
    bool fase1 = true;

    while (true) {
        if (fase1) {
            exibirMenuFase1();
            cin >> comando;

            if (comando == "config") {
                string nomeFicheiro;
                cin >> nomeFicheiro;
                if (nomeFicheiro.empty()) {
                    cout << "Erro: Nome do ficheiro nao pode ser vazio.\n";
                } else {
                    if (iniciarSimulacao(nomeFicheiro)) {
                        fase1 = false;
                    } else {
                        fase1 = true;
                    }
                }
            } else if (comando == "sair") {
                cout << "A sair...\n";
                break;
            } else {
                cout << "Comando invalido para a fase 1.\n";
            }
        } else {
            exibirMenuFase2();
            cin >> comando;

            if (comando == "exec") {
                string nomeFicheiro;
                cin >> nomeFicheiro;
                if (nomeFicheiro.empty()) {
                    cout << "Erro: Nome do ficheiro nao pode ser vazio.\n";
                } else {
                    //executarComandos(nomeFicheiro);
                }
            } else if (comando == "prox") {
                int turnos;
                cin >> turnos;
                if (turnos <= 0) {
                    cout << "Erro: O numero de turnos deve ser maior que 0.\n";
                } else {
                    avancarTurnos(turnos);
                }
            } else if (comando == "comprac") {
                char cidade, tipoCaravana;
                cin >> cidade >> tipoCaravana;
                if (tipoCaravana != 'C' && tipoCaravana != 'M' && tipoCaravana != 'S') {
                    cout << "Erro: Tipo de caravana invalido. Use 'C', 'M' ou 'S'.\n";
                } else {
                    comprarCaravana(cidade, tipoCaravana);
                }
            } else if (comando == "precos") {
                listarPrecos();
            } else if (comando == "cidade") {
                char cidade;
                cin >> cidade;
                listarCidade(cidade);
            } else if (comando == "caravana") {
                int caravanaId;
                cin >> caravanaId;
                mostrarCaravana(caravanaId);
            } else if (comando == "compra") {
                int caravanaId, quantidade;
                cin >> caravanaId >> quantidade;
                comprarMercadoria(caravanaId, quantidade);
            } else if (comando == "vende") {
                int caravanaId;
                cin >> caravanaId;
                venderMercadoria(caravanaId);
            } else if (comando == "move") {
                int caravanaId;
                string direcao;
                cin >> caravanaId >> direcao;
                moverCaravana(caravanaId, direcao);
            } else if (comando == "auto") {
                int caravanaId;
                cin >> caravanaId;
                colocarAuto(caravanaId);
            } else if (comando == "stop") {
                int caravanaId;
                cin >> caravanaId;
                pararAuto(caravanaId);
            } else if (comando == "barbaro") {
                int linha, coluna;
                cin >> linha >> coluna;
                criarBarbaro(linha, coluna);
            } else if (comando == "areia") {
                int linha, coluna, raio;
                cin >> linha >> coluna >> raio;
                criarTempestade(linha, coluna, raio);
            } else if (comando == "moedas") {
                int quantidade;
                cin >> quantidade;
                adicionarMoedas(quantidade);
            } else if (comando == "tripul") {
                int caravanaId, quantidade;
                cin >> caravanaId >> quantidade;
                comprarTripulantes(caravanaId, quantidade);
            } else if (comando == "saves") {
                string nome;
                cin >> nome;
                salvarEstado(nome);
            } else if (comando == "loads") {
                string nome;
                cin >> nome;
                carregarEstado(nome);
            } else if (comando == "lists") {
                listarEstados();
            } else if (comando == "dels") {
                string nome;
                cin >> nome;
                deletarEstado(nome);
            } else if (comando == "terminar") {
                terminarSimulacao();
                fase1 = true;
            } else {
                cout << "Comando invalido para a fase 2.\n";
            }
        }
    }
}

void Menu::exibirMenuFase1() {
    cout << "----------FASE 1----------\n";
    cout << "->Comandos disponiveis:\n";
    cout << "1. config <nomeFicheiro>\n";
    cout << "2. sair\n";
    cout << "Digite um comando: ";
}

void Menu::exibirMenuFase2() {
    cout << "----------FASE 2----------\n";
    cout << "->Comandos disponiveis:\n";
    cout << "1. exec <nomeFicheiro>\n";
    cout << "2. prox <n>\n";
    cout << "3. comprac <C> <T>\n";
    cout << "4. precos\n";
    cout << "5. cidade <C>\n";
    cout << "6. caravana <C>\n";
    cout << "7. compra <N> <M>\n";
    cout << "8. vende <N>\n";
    cout << "9. move <N> <X> \n";
    cout << "10. auto <N>\n";
    cout << "11. stop <N>\n";
    cout << "12. barbaro <l> <c>\n";
    cout << "13. areia <l> <c> <r>\n";
    cout << "14. moedas <N>\n";
    cout << "15. tripul <N> <T> \n";
    cout << "16. saves <nome>\n";
    cout << "17. loads <nome>\n";
    cout << "18. lists\n";
    cout << "19. dels <nome>\n";
    cout << "20. terminar\n";
    cout << "Digite um comando: ";
}

bool Menu::iniciarSimulacao(const std::string& nomeFicheiro) {
    std::ifstream arquivoTeste(nomeFicheiro);
    if (!arquivoTeste) {
        std::cerr << "Erro: O arquivo \"" << nomeFicheiro << "\" nao existe ou nao pode ser aberto.\n";
        return false;
    }

    cout << "Iniciando simulacao com o arquivo: " << nomeFicheiro << endl;
    Configuracoes configuracoes;
    if (!configuracoes.carregarConfiguracoes(nomeFicheiro)) {
        std::cerr << "Erro ao carregar as configuracoes.\n";
        return false;
    }

    mapa = new Mapa();
    if (!mapa->carregarMapa(nomeFicheiro)) {
        std::cerr << "Erro ao carregar o mapa.\n";
        delete mapa;
        mapa = nullptr;
        return false;
    }

    std::cout << "Mapa carregado com sucesso.\n";
    mapa->mostrarMapa();
    configuracoes.mostrarConfiguracoes();
    //mapa->criaElementosMapa();
    return true;
}

void Menu::terminarSimulacao() {
    cout << "Simulacao terminada.\n";
    delete mapa;
    mapa = nullptr;
}

void Menu::avancarTurnos(int n) {
    cout << "Avancando " << n << " turno(s).\n";
    // Implementar lógica para avançar turnos
}

void Menu::comprarCaravana(char cidade, char tipoCaravana) {
    cout << "Comprando caravana do tipo " << tipoCaravana << " na cidade " << cidade << ".\n";
    // Implementar compra de caravana
}

void Menu::listarPrecos() {
    cout << "Listando precos das mercadorias.\n";
    // Implementar lógica para listar os preços
}

void Menu::listarCidade(char cidade) {
    cout << "Listando informacoes da cidade " << cidade << ".\n";
    //Elemento *c = mapa->getCidade(cidade);
    //c->getInfo();
}

void Menu::mostrarCaravana(int caravanaId) {
    cout << "Mostrando informacoes da caravana com ID " << caravanaId << ".\n";
    //Caravana *caravana = mapa->getCaravana(caravanaId);
    //caravana->getInfo();
}

void Menu::comprarMercadoria(int caravanaId, int quantidade) {
    cout << "Comprando " << quantidade << " mercadorias para a caravana " << caravanaId << ".\n";
    // Implementar compra de mercadorias
}

void Menu::venderMercadoria(int caravanaId) {
    cout << "Vendendo mercadorias da caravana " << caravanaId << ".\n";
    // Implementar venda de mercadorias
}

void Menu::moverCaravana(int caravanaId, const string &direcao) {
    cout << "Movendo caravana " << caravanaId << " para a direcao " << direcao << ".\n";
    // Implementar movimento da caravana
}

void Menu::colocarAuto(int caravanaId) {
    cout << "Ativando modo automatico para a caravana " << caravanaId << ".\n";
    // Implementar modo automático
}

void Menu::pararAuto(int caravanaId) {
    cout << "Desativando modo automatico para a caravana " << caravanaId << ".\n";
    // Implementar parar modo automático
}

void Menu::criarBarbaro(int linha, int coluna) {
    cout << "Criando barbaro na posicao (" << linha << ", " << coluna << ").\n";
    // Implementar criação de bárbaro
}

void Menu::criarTempestade(int linha, int coluna, int raio) {
    cout << "Criando tempestade de areia na posicao (" << linha << ", " << coluna << ") com raio " << raio << ".\n";
    // Implementar criação de tempestade
}

void Menu::adicionarMoedas(int quantidade) {
    cout << "Adicionando " << quantidade << " moedas ao jogo.\n";
    // Implementar adição de moedas
}

void Menu::comprarTripulantes(int caravanaId, int quantidade) {
    cout << "Comprando " << quantidade << " tripulantes para a caravana " << caravanaId << ".\n";
    // Implementar compra de tripulantes
}

void Menu::salvarEstado(const string& nome) {
    cout << "Salvando o estado com o nome " << nome << ".\n";
    // Implementar salvamento de estado
}

void Menu::carregarEstado(const string& nome) {
    cout << "Carregando o estado do nome " << nome << ".\n";
    // Implementar carregamento de estado
}

void Menu::listarEstados() {
    cout << "Listando os estados salvos.\n";
    // Implementar listagem de estados
}

void Menu::deletarEstado(const string& nome) {
    cout << "Eliminando o estado com o nome " << nome << ".\n";
    // Implementar deletação de estado
}
