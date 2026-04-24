# Campanha Marketing em C — Desafio 2: Estruturas de Dados

## Descrição

Implementação de uma estrutura de armazenamento e recuperação de dados cadastrais de clientes,
desenvolvida em linguagem C com uso de tabela hash múltipla. O objetivo é suportar ações de
marketing orientadas a características dos clientes.

## Estrutura do Projeto
.
├── nodo.h / nodo.c       # TAD Nodo: bloco base da lista encadeada
├── lista.h / lista.c     # TAD Lista: retorno das buscas na estrutura
├── cliente.h / cliente.c # TAD Cliente: modelo de dados da aplicação
├── estrutura.h / estrutura.c # TAD Estrutura: tabela hash múltipla
└── teste2.c              # Programa de validação fornecido pelo professor

## TADs Implementados

### Nodo
Bloco básico da lista encadeada. Armazena um ponteiro genérico (`void*`) e
uma referência ao próximo nodo. A estrutura interna é opaca — acessada
exclusivamente via funções.

### Lista
Lista encadeada usada como retorno de todas as buscas. Mantém ponteiro para
o início e contador de elementos. Inserção em O(1).

### Cliente
Representa o dado central da aplicação, com os campos:
- **Nome** — string de até 40 caracteres
- **Bairro** — string de até 40 caracteres
- **Quantidade de pessoas na residência** — inteiro (1 a 5+)
- **Crianças menores de 5 anos** — booleano (0 ou 1)
- **Renda familiar bruta** — double

### Estrutura (Hash Múltipla)
Cinco tabelas hash independentes, uma por critério de busca:

| Critério | Chave | Função de Hash |
|----------|-------|----------------|
| 1 | Nome | Hash de string (soma ponderada, mod 101) |
| 2 | Bairro | Hash de string (soma ponderada, mod 101) |
| 3 | Qtd. pessoas | Direta — índice 0 a 4 (5+ mapeia para 4) |
| 4 | Crianças | Direta — índice 0 ou 1 |
| 5 | Faixa de renda | Direta — índice 0 a 3 |

#### Faixas de renda
| Índice | Faixa |
|--------|-------|
| 1 | Até R$ 2.000,00 |
| 2 | De R$ 2.000,01 a R$ 3.000,00 |
| 3 | De R$ 3.000,01 a R$ 5.000,00 |
| 4 | Acima de R$ 5.000,00 |

## Compilação

```bash
gcc -c nodo.c -o nodo.o
gcc -c lista.c -o lista.o
gcc -c cliente.c -o cliente.o
gcc -c estrutura.c -o estrutura.o
gcc teste2.c nodo.o lista.o cliente.o estrutura.o -o teste2
./teste2
```

## Interface de Recuperação

```c
Lista* recupera_cliente(Estrutura *estrutura, int criterio, int complemento, char *busca);
```

| Critério | Complemento | Busca |
|----------|-------------|-------|
| 1 — Nome | 0 | Nome do cliente |
| 2 — Bairro | 0 | Nome do bairro |
| 3 — Pessoas | Qtd. (1–5) | NULL |
| 4 — Crianças | 0 ou 1 | NULL |
| 5 — Renda | Faixa (1–4) | NULL |

## Validação

O programa `teste2.c` valida todos os cenários de busca sem nenhum `[ERRO]`,
confirmando a corretude da implementação para os 10 clientes de exemplo
distribuídos nos bairros Centro, Ingleses e Trindade.

## Requisitos

- Compilador GCC
- Padrão C99 ou superior

## Autor

André Luís  
Disciplina: Estruturas de Dados  
Instituição: UniSENAI Florianópolis

