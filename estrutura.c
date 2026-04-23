#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

#define TAM_NOME    101
#define TAM_BAIRRO  101
#define TAM_PESSOAS 5
#define TAM_CRIANCA 2
#define TAM_RENDA   4

struct estrutura {
    Lista *hash_nome[TAM_NOME];
    Lista *hash_bairro[TAM_BAIRRO];
    Lista *hash_pessoas[TAM_PESSOAS];
    Lista *hash_crianca[TAM_CRIANCA];
    Lista *hash_renda[TAM_RENDA];
};

/* Hash para strings */
static int hash_string(char *str, int tam) {
    unsigned int h = 0;
    while(*str) h = h * 31 + (unsigned char)*str++;
    return h % tam;
}

/* Faixa de renda: retorna índice 0-3 */
static int faixa_renda(double renda) {
    if(renda <= 2000.00)             return 0;
    if(renda <= 3000.00)             return 1;
    if(renda <= 5000.00)             return 2;
    return 3;
}

/* Pessoas: valor 1-5, mapeia para índice 0-4 */
static int idx_pessoas(int p) {
    if(p >= 5) return 4;
    return p - 1;
}

Estrutura* cria_estrutura() {
    Estrutura *e = malloc(sizeof(Estrutura));
    if(!e) return NULL;
    int i;
    for(i = 0; i < TAM_NOME;    i++) e->hash_nome[i]    = cria_lista();
    for(i = 0; i < TAM_BAIRRO;  i++) e->hash_bairro[i]  = cria_lista();
    for(i = 0; i < TAM_PESSOAS; i++) e->hash_pessoas[i]  = cria_lista();
    for(i = 0; i < TAM_CRIANCA; i++) e->hash_crianca[i]  = cria_lista();
    for(i = 0; i < TAM_RENDA;   i++) e->hash_renda[i]    = cria_lista();
    return e;
}

void insere_cliente(Estrutura *e, int criterio, Cliente *c) {
    int idx;
    switch(criterio) {
        case 1: idx = hash_string(get_nome(c),   TAM_NOME);
                insere_lista(e->hash_nome[idx], c);    break;
        case 2: idx = hash_string(get_bairro(c), TAM_BAIRRO);
                insere_lista(e->hash_bairro[idx], c);  break;
        case 3: idx = idx_pessoas(get_pessoas(c));
                insere_lista(e->hash_pessoas[idx], c); break;
        case 4: insere_lista(e->hash_crianca[get_criancas(c)], c); break;
        case 5: idx = faixa_renda(get_renda(c));
                insere_lista(e->hash_renda[idx], c);   break;
    }
}

Lista* recupera_cliente(Estrutura *e, int criterio, int complemento, char *busca) {
    int idx;
    switch(criterio) {
        case 1: idx = hash_string(busca, TAM_NOME);
                return e->hash_nome[idx];
        case 2: idx = hash_string(busca, TAM_BAIRRO);
                return e->hash_bairro[idx];
        case 3: return e->hash_pessoas[idx_pessoas(complemento)];
        case 4: return e->hash_crianca[complemento];
        case 5: return e->hash_renda[complemento - 1];
    }
    return NULL;
}

void libera_estrutura(Estrutura *e) {
    int i;
    for(i = 0; i < TAM_NOME;
