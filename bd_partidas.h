#ifndef BD_PARTIDAS_H
#define BD_PARTIDAS_H

#include "partida.h"

#define MAX_PARTIDAS 100

typedef struct {
    Partida partidas[MAX_PARTIDAS];
    int num_partidas;
} BDPartidas;

// Carrega partidas do arquivo CSV
BDPartidas* bd_partidas_carregar(const char* filename);

// Busca partidas por ID do time (mandante, visitante ou ambos)
int bd_partidas_buscar_por_time(BDPartidas* bd, int time_id, int modo, Partida* resultados[]);

// Libera memória do BDPartidas
void bd_partidas_liberar(BDPartidas* bd);

#endif