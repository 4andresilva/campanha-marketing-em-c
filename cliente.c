#include <stdlib.h>
#include <string.h>
#include "cliente.h"

struct cliente {
    char nome[41];
    char bairro[41];
    int pessoas;
    int criancas;
    double renda;
};

Cliente* cria_cliente(char *nome, char *bairro, int pessoas, int criancas, double renda) {
    Cliente *c = malloc(sizeof(Cliente));
    if(!c) return NULL;
    strncpy(c->nome, nome, 40);     c->nome[40] = '\0';
    strncpy(c->bairro, bairro, 40); c->bairro[40] = '\0';
    c->pessoas  = pessoas;
    c->criancas = criancas;
    c->renda    = renda;
    return c;
}

char*  get_nome(Cliente *c)    { return c->nome; }
char*  get_bairro(Cliente *c)  { return c->bairro; }
int    get_pessoas(Cliente *c) { return c->pessoas; }
int    get_criancas(Cliente *c){ return c->criancas; }
double get_renda(Cliente *c)   { return c->renda; }

void libera_cliente(Cliente *c) { free(c); }
