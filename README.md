Campeonato Computacional de Futebol - Parte I
Descrição

Sistema de gerenciamento de campeonato de futebol implementado em C para a disciplina de Estrutura de Dados do IFES Campus Serra.
Funcionalidades Implementadas

    Consultar Time - Busca por prefixo e exibe estatísticas

    Consultar Partidas - Busca por time mandante/visitante

    Imprimir Tabela - Exibe classificação completa

Estrutura do Projeto

.
├── main.c                # Programa principal
├── time.h/.c             # TAD Time
├── bd_times.h/.c         # TAD BDTimes  
├── partida.h             # TAD Partida
├── bd_partidas.h/.c      # TAD BDPartidas
├── Makefile              # Script de compilação
├── times.csv             # Dados dos times
├── partidas_*.csv        # Cenários de teste
└── README.md             # Documentação

Compilação e Execução

# Compilar
make

# Executar
./campeonato

# Limpar
make clean

Como Usar

    Preparar arquivo de partidas:

cp partidas_parcial.csv partidas.csv

Executar o programa:

./campeonato

    Menu de opções:

        1 - Consultar time por prefixo

        2 - Consultar partidas

        6 - Imprimir tabela

        Q - Sair

TADs Principais

    Time: Gerencia dados e estatísticas de um time

    BDTimes: Gerencia coleção de times

    Partida: Representa uma partida

    BDPartidas: Gerencia coleção de partidas

Cenários de Teste

# Cenário 1: Campeonato vazio
cp partidas_vazio.csv partidas.csv

# Cenário 2: Campeonato parcial  
cp partidas_parcial.csv partidas.csv

# Cenário 3: Campeonato completo
cp partidas_completo.csv partidas.csv

Ambiente

    Sistema: Linux Ubuntu 22.04

    Compilador: GCC 11

    Linguagem: C

Desenvolvido por

Jules Santos Campos
IFES Campus Serra - 2025
