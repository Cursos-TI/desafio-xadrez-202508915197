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
    int casas_bispo = 5;    // Número de casas que o Bispo se move
    int casas_torre = 5;    // Número de casas que a Torre se move
    int casas_rainha = 8;   // Número de casas que a Rainha se move
    
    // Variáveis de controle para as estruturas de repetição
    int i;
    int contador;
    
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
    printf("\n");

    // Nível Aventureiro - Movimentação do Cavalo
    // Um loop pode representar a movimentação horizontal e outro vertical.
    
    // Constantes para o movimento do Cavalo em "L"
    int movimento_vertical = 2;    // Duas casas para baixo
    int movimento_horizontal = 1;  // Uma casa para a esquerda
    
    printf("CAVALO - Movimento em L (2 casas para baixo, 1 casa para a esquerda):\n");
    
    // Loop externo (FOR) - controla o movimento vertical (2 casas para baixo)
    for (int vertical = 0; vertical < movimento_vertical; vertical++) {
        printf("Baixo\n");
    }
    
    // Loop interno (WHILE) - controla o movimento horizontal (1 casa para a esquerda)  
    int horizontal = 0;
    while (horizontal < movimento_horizontal) {
        printf("Esquerda\n");
        horizontal++;
    }
    
    printf("\n=== SIMULAÇÃO CONCLUÍDA ===\n");

    return 0;
}