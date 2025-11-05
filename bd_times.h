#ifndef BD_TIMES_H
#define BD_TIMES_H

#include "time.h"

#define MAX_TIMES 10

typedef struct {
    Time times[MAX_TIMES];
    int num_times;
} BDTimes;

// Carrega times do arquivo CSV
BDTimes* bd_times_carregar(const char* filename);

// Busca time por ID
Time* bd_times_buscar_por_id(BDTimes* bd, int id);

// Busca times por prefixo do nome
int bd_times_buscar_por_prefixo(BDTimes* bd, const char* prefixo, Time* resultados[]);

// Libera memória do BDTimes
void bd_times_liberar(BDTimes* bd);

#endif