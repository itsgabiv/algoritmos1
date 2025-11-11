/* Trabalho N2 - Simulação de Vendas de uma Loja

Alunos: Gabriela, Isac e Bruna Cevei

Descrição:
- Simula um dia de vendas de uma loja
- Os preços dos produtos vendidos nesta loja variam de R$ 5,00 a R$ 100,00
- Cada cliente compra apenas um produto
- O número e preço de cada produto, o número de clientes e os produtos 
  comprados pelos clientes devem ser gerados aleatoriamente
- No máximo 200 produtos
- No máximo 50 clientes

*/
// Constantes do programa
#define MIN_PRECO 5         // Preço mínimo dos produtos
#define MAX_PRECO 100       // Preço máximo dos produtos
#define MAX_PRODUTOS 200    // Número máximo de produtos
#define MAX_CLIENTES 50     // Número máximo de clientes

#include <stdio.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()
#include <locale.h>

// Função para gerar números inteiros aleatórios em um intervalo
int randInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Função para gerar números aleatórios de 0 até max-1
int randomIndex(int max)
{
    return rand() % max;
}

int main()
{
    // Inicializa o gerador de números aleatórios com a hora atual
    srand(time(NULL)); 
    setlocale(LC_ALL, "Portuguese");

    // Declaração das variáveis
    float precos[MAX_PRODUTOS];     // Array para armazenar os preços dos produtos
    int compras[MAX_CLIENTES];      // Array para armazenar qual produto cada cliente comprou
    int n_prod = 0, i = 0, n_clientes = 0;  // Variáveis auxiliares

    // Gera número aleatório de produtos (1 a MAX_PRODUTOS)
    n_prod = randInt(1, MAX_PRODUTOS);

    // Gera preços aleatórios entre R$ 5,00 e R$ 100,00 (com centavos)
    for (i = 0; i < n_prod; i++)
    {
        precos[i] = (randInt(500, 10000)) / 100.0; // Gera valores de 5.00 a 100.00
    }

    // Gera número aleatório de clientes (1 a MAX_CLIENTES)
    n_clientes = randInt(1, MAX_CLIENTES);

    // Gera as compras: cada cliente compra um produto aleatório
    for (i = 0; i < n_clientes; i++)
    {
        compras[i] = randomIndex(n_prod); // Índice do produto comprado
    }

    // Calcula o faturamento total
    float faturamento = 0;

    // Exibe informações da simulação
    printf("\n=======================================");
    printf("\n       SIMULACAO DE VENDAS");
    printf("\n=======================================");
    printf("\n Produtos cadastrados: %d", n_prod);
    printf("\n Clientes atendidos: %d", n_clientes);
    printf("\n=======================================");
    printf("\n Cliente   Produto     Preco");
    printf("\n=======================================");

    // Exibe as vendas realizadas e calcula o faturamento
    for (i = 0; i < n_clientes; i++)
    {
        faturamento += precos[compras[i]];
        printf("\n %7d   %7d   R$ %7.2f", i, compras[i], precos[compras[i]]);
    }

    printf("\n=======================================");
    printf("\n Faturamento total: R$ %.2f", faturamento);
    printf("\n=======================================\n");

    return 0;
}
