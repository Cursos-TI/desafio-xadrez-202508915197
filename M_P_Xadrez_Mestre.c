// Programa em C Movimentando as Peças do xadrez
// Desafio Nível Mestre: Implementar recursividade e loops complexos para movimentação das peças

// Biblioteca necessária
#include <stdio.h>

// Definições de constantes
#define TABULEIRO_SIZE 8
#define MOVIMENTO_TORRE 5    // Torre move 5 casas para a direita
#define MOVIMENTO_BISPO 5    // Bispo move 5 casas na diagonal (cima-direita)
#define MOVIMENTO_RAINHA 8   // Rainha move 8 casas para a esquerda

// Nível Mestre - Funções Recursivas e Loops Aninhados
// Sugestão: Substitua as movimentações das peças por funções recursivas.
// Exemplo: Crie uma função recursiva para o movimento do Bispo.

// Declaração das funções recursivas
void mover_torre_recursivo(int casas_restantes);
void mover_bispo_recursivo(int casas_restantes);
void mover_bispo_loops_aninhados(int casas_verticais, int casas_horizontais);
void mover_rainha_recursivo(int casas_restantes);

// Função principal

int main() {
    
    printf("=== SIMULAÇÃO NÍVEL MESTRE - MOVIMENTOS DAS PEÇAS DE XADREZ ===\n\n");

    // TORRE - Implementação com função recursiva
    printf("TORRE - Movimento horizontal recursivo (5 casas para a direita):\n");
    mover_torre_recursivo(MOVIMENTO_TORRE);
    printf("\n");

    // BISPO - Implementação com função recursiva
    printf("BISPO - Movimento diagonal recursivo (5 casas para cima e direita):\n");
    mover_bispo_recursivo(MOVIMENTO_BISPO);
    printf("\n");

    // BISPO - Implementação com loops aninhados (vertical externo, horizontal interno)
    printf("BISPO - Movimento com loops aninhados (5 casas verticais e horizontais):\n");
    mover_bispo_loops_aninhados(MOVIMENTO_BISPO, MOVIMENTO_BISPO);
    printf("\n");

    // RAINHA - Implementação com função recursiva
    printf("RAINHA - Movimento horizontal recursivo (8 casas para a esquerda):\n");
    mover_rainha_recursivo(MOVIMENTO_RAINHA);
    printf("\n");

    // CAVALO - Implementação com loops complexos aninhados (duas casas para cima, uma para a direita)
    printf("CAVALO - Movimento em L complexo (2 casas para cima, 1 casa para a direita):\n");
    
    // Variáveis para loops complexos do Cavalo
    int movimento_vertical_cavalo = 2;
    int movimento_horizontal_cavalo = 1;
    int etapa_atual = 0;
    int total_etapas = movimento_vertical_cavalo + movimento_horizontal_cavalo;
    
    // Loop externo complexo com múltiplas condições
    for (int etapa = 0; etapa < total_etapas; etapa++) {
        
        // Loop interno para movimento vertical (2 casas para cima)
        for (int vertical = 0; vertical < movimento_vertical_cavalo; vertical++) {
            if (etapa_atual >= movimento_vertical_cavalo) {
                break; // Para de mover verticalmente após 2 casas
            }
            printf("Cima\n");
            etapa_atual++;
            
            // Continue para próxima iteração se ainda há movimento vertical
            if (etapa_atual < movimento_vertical_cavalo) {
                continue;
            }
        }
        
        // Loop interno para movimento horizontal (1 casa para a direita)
        for (int horizontal = 0; horizontal < movimento_horizontal_cavalo; horizontal++) {
            if (etapa_atual < movimento_vertical_cavalo) {
                break; // Só move horizontalmente após completar movimento vertical
            }
            printf("Direita\n");
            etapa_atual++;
        }
        
        // Break do loop externo quando movimento completo
        if (etapa_atual >= total_etapas) {
            break;
        }
    }
    
    printf("\n=== SIMULAÇÃO NÍVEL MESTRE CONCLUÍDA ===\n");
    return 0;
}

// Implementação das funções recursivas

// Função recursiva para movimento da Torre
void mover_torre_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, retorna
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime a direção do movimento
    printf("Direita\n");
    
    // Chamada recursiva com uma casa a menos
    mover_torre_recursivo(casas_restantes - 1);
}

// Função recursiva para movimento do Bispo
void mover_bispo_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, retorna
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime a direção do movimento diagonal
    printf("Cima Direita\n");
    
    // Chamada recursiva com uma casa a menos
    mover_bispo_recursivo(casas_restantes - 1);
}

// Função com loops aninhados para o Bispo (vertical externo, horizontal interno)
void mover_bispo_loops_aninhados(int casas_verticais, int casas_horizontais) {
    // Loop externo para movimento vertical
    for (int vertical = 0; vertical < casas_verticais; vertical++) {
        
        // Loop interno para movimento horizontal (simulando diagonal)
        for (int horizontal = 0; horizontal < 1; horizontal++) {
            printf("Cima\n");
            printf("Direita\n");
        }
    }
}

// Função recursiva para movimento da Rainha
void mover_rainha_recursivo(int casas_restantes) {
    // Caso base: se não há mais casas para mover, retorna
    if (casas_restantes <= 0) {
        return;
    }
    
    // Imprime a direção do movimento
    printf("Esquerda\n");
    
    // Chamada recursiva com uma casa a menos
    mover_rainha_recursivo(casas_restantes - 1);
}