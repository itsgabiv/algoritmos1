#include <stdio.h>

// Declaração das funções
void obter_fracao(int num, int den);
void simplificar_fracao(int num, int den);
void somar_fracoes(int num1, int den1, int num2, int den2);
void subtrair_fracoes(int num1, int den1, int num2, int den2);
void multiplicar_fracoes(int num1, int den1, int num2, int den2);
void dividir_fracoes(int num1, int den1, int num2, int den2);

int main() {
    int opcao;
    int num1, den1, num2, den2;
    
    while (1) {
        // Exibir menu
        printf("\nCalculadora de Frações\n");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }
        
        if (opcao == 9) {
            break;
        }
        
        // Obter as frações do usuário
        do {
            printf("Digite a primeira fração:\n");
            printf("Digite o numerador: ");
            scanf("%d", &num1);
            printf("Digite o denominador: ");
            scanf("%d", &den1);
            if (den1 == 0) {
                printf("Denominador não pode ser zero. Tente novamente.\n");
            }
        } while (den1 == 0);
        
        do {
            printf("Digite a segunda fração:\n");
            printf("Digite o numerador: ");
            scanf("%d", &num2);
            printf("Digite o denominador: ");
            scanf("%d", &den2);
            if (den2 == 0) {
                printf("Denominador não pode ser zero. Tente novamente.\n");
            }
        } while (den2 == 0);
        
        // Chamar a operação correspondente
        switch (opcao) {
            case 1: somar_fracoes(num1, den1, num2, den2); break;
            case 2: subtrair_fracoes(num1, den1, num2, den2); break;
            case 3: multiplicar_fracoes(num1, den1, num2, den2); break;
            case 4: dividir_fracoes(num1, den1, num2, den2); break;
            default: 
                printf("Opção inválida!\n");
                printf("Por favor, escolha uma opção válida.\n");
        }
    }
    return 0;
}

// Implementação das funções
void somar_fracoes(int num1, int den1, int num2, int den2) {
    int num_res = num1 * den2 + num2 * den1;
    int den_res = den1 * den2;
    printf("Resultado da soma: %d/%d\n", num_res, den_res);
}

void subtrair_fracoes(int num1, int den1, int num2, int den2) {
    int num_res = num1 * den2 - num2 * den1;
    int den_res = den1 * den2;
    printf("Resultado da subtração: %d/%d\n", num_res, den_res);
}

void multiplicar_fracoes(int num1, int den1, int num2, int den2) {
    int num_res = num1 * num2;
    int den_res = den1 * den2;
    printf("Resultado da multiplicação: %d/%d\n", num_res, den_res);
}

void dividir_fracoes(int num1, int den1, int num2, int den2) {
    if (num2 == 0) {
        printf("Erro: divisão por zero não permitida.\n");
        return;
    }
    int num_res = num1 * den2;
    int den_res = den1 * num2;
    printf("Resultado da divisão: %d/%d\n", num_res, den_res);
}
