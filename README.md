Campeonato Computacional de Futebol - Parte I

Sistema de gerenciamento de campeonato de futebol implementado em C, desenvolvido como trabalho prático para a disciplina de Estrutura de Dados. O sistema carrega dados de times e partidas de arquivos CSV, permitindo consultas e exibição da tabela de classificação.
Tabela de Conteúdos

    Descrição do Projeto

    Funcionalidades Implementadas

    Estrutura do Projeto

    TADs Principais

    Como Compilar e Executar

    Como Usar

    Decisões de Implementação

    Cenários de Teste

    Ambiente de Desenvolvimento

Descrição do Projeto

O Campeonato Computacional de Futebol é um sistema simplificado desenvolvido em linguagem C para gerenciar dados de um campeonato de futebol "computacional". O sistema persiste dados em arquivos CSV e utiliza Tipos Abstratos de Dados (TADs) para gerenciar as informações em memória.

Características principais:

    Campeonato com 10 clubes em turno único de pontos corridos

    Todos jogam contra todos sem repetição de jogos

    Sistema de consulta de partidas e resultados

    Cálculo automático de estatísticas e pontuação

Funcionalidades Implementadas

    Consultar Time: Busca times por prefixo do nome e exibe estatísticas completas (vitórias, empates, derrotas, gols, saldo, pontos)

    Consultar Partidas: Busca partidas por time mandante, visitante ou ambos usando prefixo

    Imprimir Tabela: Exibe tabela de classificação completa ordenada por ID dos times

    Carregamento de Dados: Importação automática de arquivos CSV times.csv e partidas.csv

Estrutura do Projeto
text

campeonato-futebol/
├── main.c
├── time.h
├── time.c
├── bd_times.h
├── bd_times.c
├── partida.h
├── bd_partidas.h
├── bd_partidas.c
├── Makefile
├── times.csv
├── partidas_vazio.csv
├── partidas_parcial.csv
├── partidas_completo.csv
└── README.md

TADs Principais
TAD Time

Gerencia os dados de uma equipe de futebol:

    Dados armazenados: ID, nome, vitórias, empates, derrotas, gols marcados, gols sofridos

    Operações: time_atualizar_estatisticas(), time_calcular_pontos(), time_calcular_saldo()

TAD BDTimes

Gerencia a coleção de todos os times do sistema:

    Responsabilidades: Carregar dados do arquivo times.csv, buscar times por ID ou prefixo

    Estrutura: Vetor estático de 10 times

TAD Partida

Representa as informações de um jogo de futebol:

    Campos: ID, Time1ID, Time2ID, GolsTime1, GolsTime2

TAD BDPartidas

Gerencia a coleção de todas as partidas:

    Responsabilidades: Carregar dados do arquivo partidas.csv, buscar partidas por time

    Estrutura: Vetor estático de até 100 partidas

Como Compilar e Executar
Pré-requisitos

    GCC 11 ou superior

    Ambiente Linux Ubuntu 22.04 (recomendado)

    Make

Compilação
text

make

text

make clean

Execução
text

./campeonato

Como Usar
Menu Principal

Ao executar o programa, você terá acesso ao menu:
text

=== Campeonato Computacional de Futebol ===
1 - Consultar time
2 - Consultar partidas
6 - Imprimir tabela
Q - Sair
Opção:

Consultar Time
text

Digite o nome ou prefixo do time: NET

ID Time      V E D GM GS S  PG
6  NETunos   3 2 5 15 18 -3 11

Consultar Partidas
text

Escolha o modo de consulta:
1 - Por time mandante
2 - Por time visitante
3 - Por time mandante ou visitante
4 - Retornar ao menu principal
Opção: 3

Digite o nome: NET

ID Time1     x Time2
23 NETunos   1 x 1 SemCTRL
47 REACTivos 4 x 2 NETunos

Imprimir Tabela
text

Imprimindo classificação...
ID Time        V E D GM GS S  PG
0  JAVAlis     8 1 1 32 10 22 25
1  ESCorpiões  5 2 3 21 15 6  17
...

Decisões de Implementação
1. Estrutura de Dados

    Vetores estáticos para simplicidade e previsibilidade de memória

    Máximo de 10 times e 100 partidas atendem ao escopo do projeto

2. Processamento de Dados

    Carregamento único dos arquivos CSV na inicialização

    Processamento em memória para melhor performance

    Atualização em tempo real das estatísticas

3. Busca e Consultas

    Busca por prefixo case-insensitive para melhor usabilidade

    Múltiplos modos de consulta de partidas para flexibilidade

4. Tratamento de Erros

    Verificação de abertura e leitura de arquivos

    Validação de dados carregados

    Mensagens informativas para o usuário

Cenários de Teste
Cenário 1: Campeonato Vazio
text

cp partidas_vazio.csv partidas.csv
./campeonato

Resultado esperado: Todos os times com estatísticas zeradas
Cenário 2: Campeonato em Andamento
text

cp partidas_parcial.csv partidas.csv
./campeonato

Resultado esperado: Estatísticas parciais calculadas corretamente
Cenário 3: Campeonato Finalizado
text

cp partidas_completo.csv partidas.csv
./campeonato

Resultado esperado: Estatísticas finais completas
Ambiente de Desenvolvimento

    Sistema Operacional: Linux Ubuntu 22.04

    Compilador: GCC 11.4.0

    Linguagem: C

    Ferramenta de Build: Make

Notas de Desenvolvimento

Este projeto representa a Parte I do Campeonato Computacional de Futebol, focando nas funcionalidades básicas de consulta e exibição de dados. As operações de inserção, atualização e exclusão serão implementadas na próxima fase.

Desenvolvido por: Jules Santos Campos
Disciplina: Estrutura de Dados
Instituição: Instituto Federal do Espírito Santo - Campus Serra
Professor: Thiago M. Paixãox