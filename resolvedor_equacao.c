/*
UNIVERSIDADE AVANTIS 
Bacharelado em Sistemas de Informacao
Disciplina: Algoritmos I
Professor: Alessandro Joao Brassanini

RESOLVEDOR DE EQUACOES DO 1 E 2 GRAU

Autores:
- GABRIELA VIEIRA
- BRUNA CEVEI
- ISAC FRANCISCO


Data: Setembro 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Prototipos das funcoes
void mostrarMenu();
void equacao1Grau();
void equacao2Grau();
void sobrePrograma();
void pausar();
float lerCoeficiente(char nome, int obrigatorio);

int main() {
    int opcao;
    
    printf("===============================================\n");
    printf("    RESOLVEDOR DE EQUACOES MATEMATICAS\n");
    printf("===============================================\n\n");
    
    while (1) {
        mostrarMenu();
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n'); // Limpa buffer
            continue;
        }
        
        switch (opcao) {
            case 1:
                equacao1Grau();
                break;
            case 2:
                equacao2Grau();
                break;
            case 3:
                sobrePrograma();
                break;
            case 0:
                printf("\nObrigado por usar o programa!\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
        pausar();
    }
}

void mostrarMenu() {
    printf("\n===============================================\n");
    printf("               MENU PRINCIPAL\n");
    printf("===============================================\n");
    printf("1 - Resolver Equacao do 1 Grau (ax + b = 0)\n");
    printf("2 - Resolver Equacao do 2 Grau (ax^2 + bx + c = 0)\n");
    printf("3 - Sobre o Programa\n");
    printf("0 - Sair\n");
    printf("===============================================\n");
}

float lerCoeficiente(char nome, int obrigatorio) {
    float valor;
    
    while (1) {
        printf("Digite o coeficiente '%c': ", nome);
        
        if (scanf("%f", &valor) == 1) {
            if (obrigatorio && valor == 0) {
                printf("ERRO: O coeficiente '%c' nao pode ser zero!\n", nome);
                continue;
            }
            return valor;
        } else {
            printf("Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n'); // Limpa buffer
        }
    }
}

void equacao1Grau() {
    printf("\n===============================================\n");
    printf("        EQUACAO DO PRIMEIRO GRAU\n");
    printf("===============================================\n");
    printf("Formato: ax + b = 0\n\n");
    
    float a = lerCoeficiente('a', 1); // 'a' nao pode ser zero
    float b = lerCoeficiente('b', 0); // 'b' pode ser zero
    
    printf("\n--- RESOLUCAO ---\n");
    printf("Equacao: %.2fx + %.2f = 0\n\n", a, b);
    
    printf("Passo 1: Isolar x\n");
    printf("%.2fx = -%.2f\n\n", a, b);
    
    printf("Passo 2: Dividir por %.2f\n", a);
    printf("x = -%.2f / %.2f\n\n", b, a);
    
    float x = -b / a;
    printf("Solucao: x = %.4f\n\n", x);
    
    // Verificacao
    float verificacao = a * x + b;
    printf("--- VERIFICACAO ---\n");
    printf("%.2f x %.4f + %.2f = %.6f\n", a, x, b, verificacao);
    
    if (fabs(verificacao) < 0.0001) {
        printf("CORRETO Solucao correta!\n");
    } else {
        printf("AVISO Erro de precisao\n");
    }
}

void equacao2Grau() {
    printf("\n===============================================\n");
    printf("        EQUACAO DO SEGUNDO GRAU\n");
    printf("===============================================\n");
    printf("Formato: ax^2 + bx + c = 0\n\n");
    
    float a = lerCoeficiente('a', 1); // 'a' nao pode ser zero
    float b = lerCoeficiente('b', 0);
    float c = lerCoeficiente('c', 0);
    
    printf("\n--- RESOLUCAO ---\n");
    printf("Equacao: %.2fx^2 + %.2fx + %.2f = 0\n\n", a, b, c);
    
    // Calcular discriminante (delta)
    float delta = (b * b) - (4 * a * c);
    
    printf("Passo 1: Calcular discriminante (delta)\n");
    printf("delta = b^2 - 4ac\n");
    printf("delta = (%.2f)^2 - 4 x (%.2f) x (%.2f)\n", b, a, c);
    printf("delta = %.4f - %.4f = %.4f\n\n", b*b, 4*a*c, delta);
    
    printf("Passo 2: Analisar o discriminante\n");
    
    if (delta > 0) {
        // Duas raizes reais
        printf("delta > 0: Duas raizes reais distintas\n\n");
        
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        
        printf("Passo 3: Aplicar formula de Bhaskara\n");
        printf("x = (-b +/- raiz(delta)) / 2a\n");
        printf("x = (-%.2f +/- raiz(%.4f)) / %.2f\n\n", b, delta, 2*a);
        
        printf("Solucoes:\n");
        printf("x1 = %.4f\n", x1);
        printf("x2 = %.4f\n", x2);
        
    } else if (delta == 0) {
        // Uma raiz real dupla
        printf("delta = 0: Uma raiz real (dupla)\n\n");
        
        float x = -b / (2 * a);
        
        printf("Passo 3: Calcular raiz dupla\n");
        printf("x = -b / 2a = -%.2f / %.2f\n\n", b, 2*a);
        
        printf("Solucao: x = %.4f\n", x);
        
    } else {
        // Raizes complexas
        printf("delta < 0: Raizes complexas\n\n");
        
        float parteReal = -b / (2 * a);
        float parteImag = sqrt(-delta) / (2 * a);
        
        printf("Passo 3: Calcular raizes complexas\n");
        printf("x = (-b +/- i x raiz(|delta|)) / 2a\n\n");
        
        printf("Solucoes:\n");
        printf("x1 = %.4f + %.4fi\n", parteReal, parteImag);
        printf("x2 = %.4f - %.4fi\n", parteReal, parteImag);
    }
    
    // Informacoes extras
    if (delta >= 0) {
        printf("\n--- PROPRIEDADES ---\n");
        printf("Soma das raizes: %.4f\n", -b/a);
        printf("Produto das raizes: %.4f\n", c/a);
        
        float xv = -b / (2*a);
        float yv = a*xv*xv + b*xv + c;
        printf("Vertice: (%.4f, %.4f)\n", xv, yv);
    }
}

void sobrePrograma() {
    printf("\n===============================================\n");
    printf("            SOBRE O PROGRAMA\n");
    printf("===============================================\n");
    printf("RESOLVEDOR DE EQUACOES\n\n");
    
    printf("Desenvolvedores:\n");
    printf("- GABRIELA VIEIRA\n");
    printf("- BRUNA CEVEI\n");
    printf("- ISAC FRANCISCO\n\n");
    
    printf("Universidade Avantis - Sistemas de Informacao\n");
    printf("Disciplina: Algoritmos I\n");
    printf("Professor: Alessandro Joao Brassanini\n");
    printf("Data: Setembro de 2025\n\n");
    
    printf("Funcionalidades:\n");
    printf("- Equacoes do 1 grau com validacao\n");
    printf("- Equacoes do 2 grau com analise completa\n");
    printf("- Verificacao automatica das solucoes\n");
    
    printf("===============================================\n");
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n'); // Limpa buffer
    getchar(); // Aguarda Enter
}
