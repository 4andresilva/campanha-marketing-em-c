#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente Cliente;

Cliente* cria_cliente(char *nome, char *bairro, int pessoas, int criancas, double renda);

char*  get_nome(Cliente *c);
char*  get_bairro(Cliente *c);
int    get_pessoas(Cliente *c);
int    get_criancas(Cliente *c);
double get_renda(Cliente *c);

void libera_cliente(Cliente *c);

#endif
