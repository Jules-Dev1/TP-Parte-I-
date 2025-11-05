#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_partidas.h"

BDPartidas* bd_partidas_carregar(const char* filename) {
    FILE* arquivo = fopen(filename, "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo %s\n", filename);
        return NULL;
    }
    
    BDPartidas* bd = (BDPartidas*)malloc(sizeof(BDPartidas));
    if (!bd) {
        fclose(arquivo);
        return NULL;
    }
    
    bd->num_partidas = 0;
    
    // Pular cabeçalho
    char linha[256];
    fgets(linha, sizeof(linha), arquivo);
    
    // Ler partidas
    while (fgets(linha, sizeof(linha), arquivo) && bd->num_partidas < MAX_PARTIDAS) {
        Partida* partida = &bd->partidas[bd->num_partidas];
        
        // Remover newline
        linha[strcspn(linha, "\n")] = 0;
        
        // Parse CSV
        char* token = strtok(linha, ",");
        if (token) partida->id = atoi(token);
        
        token = strtok(NULL, ",");
        if (token) partida->time1_id = atoi(token);
        
        token = strtok(NULL, ",");
        if (token) partida->time2_id = atoi(token);
        
        token = strtok(NULL, ",");
        if (token) partida->gols_time1 = atoi(token);
        
        token = strtok(NULL, ",");
        if (token) partida->gols_time2 = atoi(token);
        
        bd->num_partidas++;
    }
    
    fclose(arquivo);
    return bd;
}

int bd_partidas_buscar_por_time(BDPartidas* bd, int time_id, int modo, Partida* resultados[]) {
    int count = 0;
    
    for (int i = 0; i < bd->num_partidas && count < MAX_PARTIDAS; i++) {
        Partida* partida = &bd->partidas[i];
        
        int match = 0;
        switch (modo) {
            case 1: // Time mandante
                match = (partida->time1_id == time_id);
                break;
            case 2: // Time visitante
                match = (partida->time2_id == time_id);
                break;
            case 3: // Time mandante ou visitante
                match = (partida->time1_id == time_id || partida->time2_id == time_id);
                break;
        }
        
        if (match) {
            resultados[count++] = partida;
        }
    }
    
    return count;
}

void bd_partidas_liberar(BDPartidas* bd) {
    free(bd);
}