#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bd_times.h"
#include "bd_partidas.h"
#include "time.h"

void processar_partidas(BDTimes* bd_times, BDPartidas* bd_partidas) {
    for (int i = 0; i < bd_partidas->num_partidas; i++) {
        Partida* partida = &bd_partidas->partidas[i];
        
        Time* time1 = bd_times_buscar_por_id(bd_times, partida->time1_id);
        Time* time2 = bd_times_buscar_por_id(bd_times, partida->time2_id);
        
        if (time1 && time2) {
            time_atualizar_estatisticas(time1, partida->gols_time1, partida->gols_time2);
            time_atualizar_estatisticas(time2, partida->gols_time2, partida->gols_time1);
        }
    }
}

void consultar_time(BDTimes* bd_times) {
    char prefixo[50];
    printf("Digite o nome ou prefixo do time: ");
    scanf("%s", prefixo);
    
    Time* resultados[MAX_TIMES];
    int num_encontrados = bd_times_buscar_por_prefixo(bd_times, prefixo, resultados);
    
    if (num_encontrados == 0) {
        printf("Nenhum time encontrado com o prefixo '%s'.\n", prefixo);
    } else {
        printf("ID Time        V E D GM GS S  PG\n");
        for (int i = 0; i < num_encontrados; i++) {
            Time* t = resultados[i];
            printf("%-2d %-11s %d %d %d %-2d %-2d %-3d %-2d\n", 
                    t->id, t->nome, t->vitorias, t->empates, t->derrotas,
                    t->gols_marcados, t->gols_sofridos, 
                    time_calcular_saldo(t), time_calcular_pontos(t));
        }
    }
}

void consultar_partidas(BDTimes* bd_times, BDPartidas* bd_partidas) {
    int modo;
    printf("Escolha o modo de consulta:\n");
    printf("1 - Por time mandante\n");
    printf("2 - Por time visitante\n");
    printf("3 - Por time mandante ou visitante\n");
    printf("4 - Retornar ao menu principal\n");
    printf("Opcao: ");
    scanf("%d", &modo);
    
    if (modo == 4) return;
    
    char nome[50];
    printf("Digite o nome: ");
    scanf("%s", nome);
    
    // Buscar time por prefixo
    Time* times_encontrados[MAX_TIMES];
    int num_times = bd_times_buscar_por_prefixo(bd_times, nome, times_encontrados);
    
    if (num_times == 0) {
        printf("Nenhum time encontrado com o nome '%s'.\n", nome);
        return;
    }
    
    printf("ID Time1     x Time2\n");
    int partidas_encontradas = 0;
    
    for (int i = 0; i < num_times; i++) {
        Time* time = times_encontrados[i];
        Partida* resultados[MAX_PARTIDAS];
        int num_partidas = bd_partidas_buscar_por_time(bd_partidas, time->id, modo, resultados);
        
        for (int j = 0; j < num_partidas; j++) {
            Partida* p = resultados[j];
            Time* time1 = bd_times_buscar_por_id(bd_times, p->time1_id);
            Time* time2 = bd_times_buscar_por_id(bd_times, p->time2_id);
            
            if (time1 && time2) {
                printf("%-2d %-10s %d x %d %-10s\n", 
                        p->id, time1->nome, p->gols_time1, p->gols_time2, time2->nome);
                partidas_encontradas++;
            }
        }
    }
    
    if (partidas_encontradas == 0) {
        printf("Nenhuma partida encontrada.\n");
    }
}

void imprimir_tabela(BDTimes* bd_times) {
    printf("Imprimindo classificacao...\n");
    printf("ID Time        V E D GM GS S  PG\n");
    
    for (int i = 0; i < bd_times->num_times; i++) {
        Time* t = &bd_times->times[i];
        printf("%-2d %-11s %d %d %d %-2d %-2d %-3d %-2d\n", 
                t->id, t->nome, t->vitorias, t->empates, t->derrotas,
                t->gols_marcados, t->gols_sofridos, 
                time_calcular_saldo(t), time_calcular_pontos(t));
    }
}

int main() {
    // Carregar dados
    BDTimes* bd_times = bd_times_carregar("times.csv");
    if (!bd_times) {
        printf("Erro ao carregar times.\n");
        return 1;
    }
    
    BDPartidas* bd_partidas = bd_partidas_carregar("partidas.csv");
    if (!bd_partidas) {
        printf("Erro ao carregar partidas.\n");
        bd_times_liberar(bd_times);
        return 1;
    }
    
    // Processar estatísticas das partidas
    processar_partidas(bd_times, bd_partidas);
    
    // Menu principal
    char opcao;
    do {
        printf("\n=== Campeonato Computacional de Futebol ===\n");
        printf("1 - Consultar time\n");
        printf("2 - Consultar partidas\n");
        printf("6 - Imprimir tabela\n");
        printf("Q - Sair\n");
        printf("Opcao: ");
        scanf(" %c", &opcao);
        
        switch(opcao) {
            case '1': 
                consultar_time(bd_times); 
                break;
            case '2': 
                consultar_partidas(bd_times, bd_partidas); 
                break;
            case '6': 
                imprimir_tabela(bd_times); 
                break;
            case 'Q':
            case 'q':
                printf("Encerrando sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 'Q' && opcao != 'q');
    
    // Liberar memória
    bd_times_liberar(bd_times);
    bd_partidas_liberar(bd_partidas);
    
    return 0;
}