// Programa em C Movimentando as Peças do xadrez
// Desafio: Simular movimento de Torre, Bispo e Rainha usando diferentes estruturas de repetição

// Biblioteca necessária
#include <stdio.h>

// Definições de constantes
#define TABULEIRO_SIZE 8
#define MOVIMENTO_TORRE 5    // Torre move 5 casas para a direita
#define MOVIMENTO_BISPO 5    // Bispo move 5 casas na diagonal (cima-direita)
#define MOVIMENTO_RAINHA 8   // Rainha move 8 casas para a esquerda

// Função principal

int main() {
    
    // Nível Novato - Movimentação das Peças

    // Número de casas que o Bispo se move
    int casas_bispo = 5; 
    
    // Número de casas que a Torre se move
    int casas_torre = 5; 
    
    // Número de casas que a Rainha se move
    int casas_rainha = 8;   
    
    // Variáveis de controle para as estruturas de repetição
    int i;
    int contador;
    
    // Início da simulação
    printf("=== SIMULAÇÃO DE MOVIMENTOS DAS PEÇAS DE XADREZ ===\n\n");

    // Implementação de Movimentação do Bispo
    printf("BISPO - Movimento diagonal (5 casas para cima e direita):\n");
    i = 0;
    while (i < casas_bispo) {
        printf("Cima Direita\n");
        i++;
    }
    printf("\n");

    // Implementação de Movimentação da Torre

    printf("TORRE - Movimento horizontal (5 casas para a direita):\n");
    for (contador = 0; contador < casas_torre; contador++) {
        printf("Direita\n");
    }
    printf("\n");

    // Implementação de Movimentação da Rainha

    printf("RAINHA - Movimento horizontal (8 casas para a esquerda):\n");
    contador = 0;
    do {
        printf("Esquerda\n");
        contador++;
    } while (contador < casas_rainha);
    
    printf("\n=== SIMULAÇÃO CONCLUÍDA ===\n");

    return 0;
}