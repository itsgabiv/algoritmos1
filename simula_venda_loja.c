/*
 * Trabalho de Algoritmos I – Primeira Fase (N2) – Peso 3
 * Simulação de um dia de vendas em loja
 * 
 * Autor: Gabriela Vieira
 * Curso: Bacharelado em Sistemas de Informação
 * Professor: Alessandro João Brassanini
 * Data de entrega: 28/05/2025
 *
 * Descrição:
 *   - Gera aleatoriamente até 200 produtos, com preços inteiros de R$5 a R$100.
 *   - Gera aleatoriamente até 50 clientes, cada um comprando um único produto.
 *   - Armazena o índice do produto comprado por cada cliente em `compra[]`.
 *   - Exibe detalhes das vendas e um breve resumo (receita total e produto mais vendido).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUTOS 200
#define MAX_CLIENTES   50
#define PRECO_MIN       5
#define PRECO_MAX     100

int main(void) {
    int numProdutos, numClientes;
    int precoProdutos[MAX_PRODUTOS];
    int compra[MAX_CLIENTES];
    int vendasPorProduto[MAX_PRODUTOS] = {0};
    int i;

    /* Semente diferente a cada execução */
    srand((unsigned) time(NULL));

    /* 1) Número de produtos (1 a MAX_PRODUTOS) */
    numProdutos = (rand() % MAX_PRODUTOS) + 1;

    /* 2) Atribuição de preços aleatórios (PRECO_MIN a PRECO_MAX) */
    for (i = 0; i < numProdutos; i++) {
        precoProdutos[i] = (rand() % (PRECO_MAX - PRECO_MIN + 1)) + PRECO_MIN;
    }

    /* 3) Número de clientes (1 a MAX_CLIENTES) */
    numClientes = (rand() % MAX_CLIENTES) + 1;

    /* 4) Cada cliente compra um produto aleatório */
    for (i = 0; i < numClientes; i++) {
        compra[i] = rand() % numProdutos;       /* índice 0…numProdutos-1 */
        vendasPorProduto[ compra[i] ]++;        /* contabiliza vendas */
    }

    /* 5) Exibição da simulação */
    printf("=== Simulação de Vendas - Hoje ===\n\n");
    printf("Produtos disponíveis: %d\n", numProdutos);
    printf("Preços dos produtos:\n");
    for (i = 0; i < numProdutos; i++) {
        printf("  Produto %3d: R$%3d,00\n", i+1, precoProdutos[i]);
    }
    printf("\nClientes atendidos: %d\n", numClientes);
    printf("Registro de compras:\n");
    for (i = 0; i < numClientes; i++) {
        printf("  Cliente %2d comprou o Produto %3d (R$%d,00)\n",
               i+1, compra[i]+1, precoProdutos[ compra[i] ]);
    }

    /* 6) Resumo: receita total e produto mais vendido */
    {
        int total = 0, produtoMaisVendido = 0, maxVendas = 0;
        for (i = 0; i < numClientes; i++) {
            total += precoProdutos[ compra[i] ];
        }
        for (i = 0; i < numProdutos; i++) {
            if (vendasPorProduto[i] > maxVendas) {
                maxVendas = vendasPorProduto[i];
                produtoMaisVendido = i;
            }
        }
        printf("\n=== Resumo de Vendas ===\n");
        printf("Receita total: R$%d,00\n", total);
        printf("Produto mais vendido: %d (vendas: %d)\n",
               produtoMaisVendido+1, maxVendas);
    }

    return EXIT_SUCCESS;
}
