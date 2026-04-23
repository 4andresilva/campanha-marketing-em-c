#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

typedef struct lista Lista;

Lista *cria_lista();
void insere_lista(Lista *lista, void *data);
Nodo *get_inicio(Lista *lista);
int get_quantidade(Lista *lista);
void libera_lista(Lista *lista);

#endif
