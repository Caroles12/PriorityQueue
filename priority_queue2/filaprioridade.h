#ifndef FILAPRIORIDADE_H_INCLUDED
#define FILAPRIORIDADE_H_INCLUDED

#include "dados_paciente.h"

typedef struct filaprioridades fila_t;

fila_t* criar_fila_prioridade();

int enqueue(fila_t *fila,dado_t **p);

#endif // FILAPRIORIDADE_H_INCLUDED
