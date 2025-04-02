#include <stdio.h>

// Função para obter uma fração do usuário
void obter_fracao(int *num, int *den) {
    printf("Digite o numerador: ");
    scanf("%d", num);
    
    do {
        printf("Digite o denominador (diferente de zero): ");
        scanf("%d", den);
    } while (*den == 0);
}

// Função para calcular o Máximo Divisor Comum (MDC)
int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar uma fração
void simplificar_fracao(int *num, int *den) {
    int divisor = mdc(*num, *den);
    *num /= divisor;
    *den /= divisor;
}

// Função para somar frações
void somar_fracoes(int num1, int den1, int num2, int den2) {
    int num_res = num1 * den2 + num2 * den1;
    int den_res = den1 * den2;
    simplificar_fracao(&num_res, &den_res);
    printf("%d/%d + %d/%d = %d/%d\n", num1, den1, num2, den2, num_res, den_res);
}

// Função para subtrair frações
void subtrair_fracoes(int num1, int den1, int num2, int den2) {
    int num_res = num1 * den2 - num2 * den1;
    int den_res = den1 * den2;
    simplificar_fracao(&num_res, &den_res);
    printf("%d/%d - %d/%d = %d/%d\n", num1, den1, num2, den2, num_res, den_res);
}

// Função para multiplicar frações
void multiplicar_fracoes(int num1, int den1, int num2, int den2) {
    int num_res = num1 * num2;
    int den_res = den1 * den2;
    simplificar_fracao(&num_res, &den_res);
    printf("%d/%d * %d/%d = %d/%d\n", num1, den1, num2, den2, num_res, den_res);
}

// Função para dividir frações
void dividir_fracoes(int num1, int den1, int num2, int den2) {
    if (num2 == 0) {
        printf("Erro: Divisão por zero não permitida!\n");
        return;
    }
    int num_res = num1 * den2;
    int den_res = den1 * num2;
    simplificar_fracao(&num_res, &den_res);
    printf("%d/%d ÷ %d/%d = %d/%d\n", num1, den1, num2, den2, num_res, den_res);
}

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
            obter_fracao(&num1, &den1);
            if (den1 == 0) {
                printf("Denominador não pode ser zero. Tente novamente.\n");
            }
        } while (den1 == 0);
        
        do {
            printf("Digite a segunda fração:\n");
            obter_fracao(&num2, &den2);
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
