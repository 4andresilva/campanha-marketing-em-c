#ifndef NODO_H
#define NODO_H

typedef struct nodo Nodo;

Nodo *cria_nodo(void *data);
void *get_data(Nodo *nodo);
Nodo *get_next(Nodo *nodo);
void set_next(Nodo *nodo, Nodo *next);

#endif
