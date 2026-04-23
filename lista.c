#include <stdlib.h>
#include "lista.h"

struct lista
{
    Nodo *inicio;
    int quantidade;
};

Lista *cria_lista()
{
    Lista *l = malloc(sizeof(Lista));
    if (l)
    {
        l->inicio = NULL;
        l->quantidade = 0;
    }
    return l;
}

void insere_lista(Lista *lista, void *data)
{
    Nodo *n = cria_nodo(data);
    if (!n)
        return;
    n->next = lista->inicio;
    lista->inicio = n;
    lista->quantidade++;
}

Nodo *get_inicio(Lista *lista) { return lista->inicio; }
int get_quantidade(Lista *lista) { return lista ? lista->quantidade : 0; }

void libera_lista(Lista *lista)
{
    Nodo *cur = lista->inicio;
    while (cur)
    {
        Nodo *prox = get_next(cur);
        free(cur);
        cur = prox;
    }
    free(lista);
}
