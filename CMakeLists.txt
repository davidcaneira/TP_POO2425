cmake_minimum_required(VERSION 3.29)
project(projeto)

set(CMAKE_CXX_STANDARD 20)

add_executable(projeto main.cpp
        Simulador.cpp
        Simulador.h
        Buffer.cpp
        Buffer.h
        Caravana.cpp
        Caravana.h
        CaravanaComercio.cpp
        CaravanaComercio.h
        CaravanaMilitar.cpp
        CaravanaMilitar.h
        CaravanaSecreta.cpp
        CaravanaSecreta.h
        Cidade.cpp
        Cidade.h
        Mapa.cpp
        Mapa.h
        Tempestade.cpp
        Tempestade.h
        Configuracoes.cpp
        Configuracoes.h
        Elemento.cpp
        Elemento.h
        Deserto.cpp
        Deserto.h
        Montanha.cpp
        Montanha.h
        Item.cpp
        Item.h
        CaravaBarbara.cpp
        CaravaBarbara.h)

