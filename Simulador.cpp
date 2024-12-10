#include "Simulador.h"

Simulador::Simulador() {
    mapa = nullptr;
}

Simulador::~Simulador() {
    delete mapa;
}

void Simulador::iniciaFase1() {
    bool iniciar;
    string comando;
    string primArg; //primeiro argumento do comando
    string nomeFicheiro;

    while (true) {
        exibirMenuFase1();
        getline(cin, comando);

        istringstream iss(comando);
        iss >> primArg;
        if (primArg == "config") {
            iss >> nomeFicheiro;
            if (nomeFicheiro.empty()) {
                cout << "O ficheiro nao pode estar vazio!" << endl;
            } else {
                iniciar = iniciarSimulacao(nomeFicheiro);
                if (iniciar) {
                    escolheComandoFase2();
                }
            }
        } else if (primArg == "sair") {
            break;
        } else {
            cout << "Comando invalido!" << endl;
        }
    }
}



bool Simulador::iniciarSimulacao(const string &nomeFicheiro) {
    ifstream ficheiro(nomeFicheiro); //abrir ficheiro
    if (!ficheiro) {
        cout << "Ficheiro nao existe!" << endl;
        return false;
    }

    Configuracoes configuracoes;
    if (!configuracoes.carregarConfiguracoes(nomeFicheiro)) {
        cout << "Erro a carregar configuracoes!" << endl;
        return false;
    }

    mapa = new Mapa();
    if (!mapa->carregarMapa(nomeFicheiro)) {
        cout << "Erro a carregar mapa!" << endl;
        delete mapa;
        mapa = nullptr;
        return false;
    }

    mapa->mostrarMapa();
    configuracoes.mostrarConfiguracoes();
    mapa->criaElementos();
    return true;
}

void Simulador::escolheComandoFase2() {
    string comando;
    bool escolhido;
    bool primeiraIteracao = true;


    do {
        if (!primeiraIteracao) {
            mapa->mostrarMapa();
        } else {
            primeiraIteracao = false;
        }
        exibirMenuFase2();

        getline(cin, comando);

        if (comando == "terminar")
            break;
        else
            escolhido = verificaComando(comando);

        if (!escolhido) {
            cout << "Erro no comando '" << comando << "'" << endl;
        }
    } while (comando != "terminar");
}

bool Simulador::verificaComando (const string &comando) {
    istringstream iss(comando);
    string primArg;
    iss >> primArg;
    bool escolhido;

    if (primArg == "exec") {
        escolhido = executaComandosFicheiro(comando);
    }else if (primArg == "prox") {
        escolhido = avancaTurnos (comando);
    }else if (primArg == "comprac") {
        escolhido = compraCaravana (comando);
    }else if (primArg == "precos") {
        escolhido = listaPrecosMercadorias (comando);
    }else if (primArg == "cidade") {
        escolhido = listaInfoCidade (comando);
    }else if (primArg == "caravana") {
        escolhido = mostraInfoCaravana (comando);
    }else if (primArg == "compra") {
        escolhido = compraMercadorias (comando);
    }else if (primArg == "vende") {
        escolhido = vendeMercadoria (comando);
    }else if (primArg == "move") {
        escolhido = moveCaravana (comando);
    }else if (primArg == "auto") {
        escolhido = autoCaravana (comando);
    }else if (primArg == "stop") {
        escolhido = stopAutoCaravana (comando);
    }else if (primArg == "barbaro") {
        escolhido = criaCaravanaBarbara (comando);
    }else if (primArg == "areia") {
        escolhido = criaTempestade (comando);
    }else if (primArg == "moedas") {
        escolhido = adicionaMoedas (comando);
    }else if (primArg == "tripul") {
        escolhido = compraTripulantes (comando);
    }else if (primArg == "saves") {
        escolhido = copiaBuffer (comando);
    }else if (primArg == "loads") {
        escolhido = recuperaCopiaBuffer (comando);
    }else if (primArg == "lists") {
        escolhido = listaCopias (comando);
    }else if (primArg == "dels") {
        escolhido = eliminaCopiaBuffer (comando);
    }else return false;
    return escolhido;
}

bool Simulador::executaComandosFicheiro(const string &comando) {
    std::cout << "Executando comandos do arquivo: " << comando << std::endl;
    return true;
}

bool Simulador::avancaTurnos(const string &comando) {
    std::cout << "Avançando turnos: " << comando << std::endl;
    return true;
}

bool Simulador::compraCaravana(const string &comando) {
    std::cout << "Comprando caravana: " << comando << std::endl;
    return true;
}

bool Simulador::listaPrecosMercadorias(const string &comando) {
    std::cout << "Listando preços de mercadorias: " << comando << std::endl;
    return true;
}

bool Simulador::listaInfoCidade(const string &comando) {
    istringstream iss(comando);
    string primArg;
    char letra;
    iss >> primArg >> letra;

    if (iss)
    {
        return mapa->getInfoCidade(letra);
    }
    return false;
}

bool Simulador::mostraInfoCaravana(const string &comando) {
    istringstream iss(comando);
    string primArg;
    int id;
    iss >> primArg >> id;

    if (iss)
    {
        return mapa->getInfoCaravana(id);
    }
    return false;
}

bool Simulador::compraMercadorias(const string &comando) {
    std::cout << "Comprando mercadorias: " << comando << std::endl;
    return true;
}

bool Simulador::vendeMercadoria(const string &comando) {
    std::cout << "Vendendo mercadoria: " << comando << std::endl;
    return true;
}

bool Simulador::moveCaravana(const string &comando) {
    std::cout << "Movendo caravana: " << comando << std::endl;
    return true;
}

bool Simulador::autoCaravana(const string &comando) {
    std::cout << "Colocando caravana no modo automático: " << comando << std::endl;
    return true;
}

bool Simulador::stopAutoCaravana(const string &comando) {
    std::cout << "Parando caravana do modo automático: " << comando << std::endl;
    return true;
}

bool Simulador::criaCaravanaBarbara(const string &comando) {
    std::cout << "Criando caravana bárbara: " << comando << std::endl;
    return true;
}

bool Simulador::criaTempestade(const string &comando) {
    std::cout << "Criando tempestade de areia: " << comando << std::endl;
    return true;
}

bool Simulador::adicionaMoedas(const string &comando) {
    std::cout << "Adicionando moedas: " << comando << std::endl;
    return true;
}

bool Simulador::compraTripulantes(const string &comando) {
    std::cout << "Comprando tripulantes: " << comando << std::endl;
    return true;
}

bool Simulador::copiaBuffer(const string &comando) {
    std::cout << "Copiando buffer: " << comando << std::endl;
    return true;
}

bool Simulador::recuperaCopiaBuffer(const string &comando) {
    std::cout << "Recuperando buffer: " << comando << std::endl;
    return true;
}

bool Simulador::listaCopias(const string &comando) {
    std::cout << "Listando cópias do buffer: " << comando << std::endl;
    return true;
}

bool Simulador::eliminaCopiaBuffer(const string &comando) {
    std::cout << "Eliminando cópia do buffer: " << comando << std::endl;
    return true;
}

void Simulador::exibirMenuFase1() {
    cout << endl;
    cout << "----------FASE 1----------" << endl;
    cout << "1. config <nomeFicheiro>" << endl;
    cout << "2. sair" << endl;
    cout << "Comando: ";
}

void Simulador::exibirMenuFase2() {
    cout << endl;
    cout << "----------FASE 2----------" << endl;
    cout << "1. exec <nomeFicheiro>" << endl;
    cout << "2. prox <n>" << endl;
    cout << "3. comprac <C> <T>" << endl;
    cout << "4. precos" << endl;
    cout << "5. cidade <C>" << endl;
    cout << "6. caravana <C>" << endl;
    cout << "7. compra <N> <M>" << endl;
    cout << "8. vende <N>" << endl;
    cout << "9. move <N> <X>" << endl;
    cout << "10. auto <N>" << endl;
    cout << "11. stop <N>" << endl;
    cout << "12. barbaro <l> <c>" << endl;
    cout << "13. areia <l> <c> <r>" << endl;
    cout << "14. moedas <N>" << endl;
    cout << "15. tripul <N> <T>" << endl;
    cout << "16. saves <nome>" << endl;
    cout << "17. loads <nome>" << endl;
    cout << "18. lists" << endl;
    cout << "19. dels <nome>" << endl;
    cout << "20. terminar" << endl;
    cout << "Comando: ";
}

