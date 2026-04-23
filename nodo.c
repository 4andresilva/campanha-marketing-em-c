#include <stdlib.h>
#include "nodo.h"

struct nodo
{
    void *data;
    Nodo *next;
};

Nodo *cria_nodo(void *data)
{
    Nodo *n = malloc(sizeof(Nodo));
    if (n)
    {
        n->data = data;
        n->next = NULL;
    }
    return n;
}

void *get_data(Nodo *n) { return n->data; }
Nodo *get_next(Nodo *n) { return n->next; }
void set_next(Nodo *n, Nodo *next) { n->next = next; }
