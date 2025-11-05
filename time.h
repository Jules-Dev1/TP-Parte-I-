#ifndef TIME_H
#define TIME_H

typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_marcados;
    int gols_sofridos;
} Time;

// Atualiza estatísticas do time baseado em um resultado
void time_atualizar_estatisticas(Time* time, int gols_feitos, int gols_sofridos);

// Calcula pontos ganhos (3*vitorias + empates)
int time_calcular_pontos(const Time* time);

// Calcula saldo de gols (gols_marcados - gols_sofridos)
int time_calcular_saldo(const Time* time);

#endif