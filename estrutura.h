#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "cliente.h"
#include "lista.h"

typedef struct estrutura Estrutura;

Estrutura* cria_estrutura();
void       insere_cliente(Estrutura *e, int criterio, Cliente *c);
Lista*     recupera_cliente(Estrutura *e, int criterio, int complemento, char *busca);
void       libera_estrutura(Estrutura *e);

#endif
