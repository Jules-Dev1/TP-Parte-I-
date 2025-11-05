#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bd_times.h"
#include <strings.h>

BDTimes* bd_times_carregar(const char* filename) {
    FILE* arquivo = fopen(filename, "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo %s\n", filename);
        return NULL;
    }
    
    BDTimes* bd = (BDTimes*)malloc(sizeof(BDTimes));
    if (!bd) {
        fclose(arquivo);
        return NULL;
    }
    
    bd->num_times = 0;
    
    // Pular cabeçalho
    char linha[256];
    fgets(linha, sizeof(linha), arquivo);
    
    // Ler times
    while (fgets(linha, sizeof(linha), arquivo)) {
        Time* time = &bd->times[bd->num_times];
        
        // Remover newline
        linha[strcspn(linha, "\n")] = 0;
        
        // Parse CSV simples
        char* token = strtok(linha, ",");
        if (token) time->id = atoi(token);
        
        token = strtok(NULL, ",");
        if (token) strcpy(time->nome, token);
        
        // Inicializar estatísticas
        time->vitorias = 0;
        time->empates = 0;
        time->derrotas = 0;
        time->gols_marcados = 0;
        time->gols_sofridos = 0;
        
        bd->num_times++;
        
        if (bd->num_times >= MAX_TIMES) break;
    }
    
    fclose(arquivo);
    return bd;
}

Time* bd_times_buscar_por_id(BDTimes* bd, int id) {
    for (int i = 0; i < bd->num_times; i++) {
        if (bd->times[i].id == id) {
            return &bd->times[i];
        }
    }
    return NULL;
}

int bd_times_buscar_por_prefixo(BDTimes* bd, const char* prefixo, Time* resultados[]) {
    int count = 0;
    int len_prefixo = strlen(prefixo);
    
    for (int i = 0; i < bd->num_times && count < MAX_TIMES; i++) {
        // Comparação case-insensitive por prefixo
        if (strncasecmp(bd->times[i].nome, prefixo, len_prefixo) == 0) {
            resultados[count++] = &bd->times[i];
        }
    }
    
    return count;
}

void bd_times_liberar(BDTimes* bd) {
    free(bd);
}