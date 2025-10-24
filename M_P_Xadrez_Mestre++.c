// PROGRAMA: MOVIMENTAÇÃO DAS PEÇAS DE XADREZ - NÍVEL MESTRE PLUS

#include <stdio.h>  // Biblioteca padrão para entrada e saída

// Constantes do programa
#define TABULEIRO_SIZE 8        // Tamanho padrão do tabuleiro de xadrez (8x8)
#define MOVIMENTO_TORRE 5       // Torre se move 5 casas horizontalmente
#define MOVIMENTO_BISPO 5       // Bispo se move 5 casas na diagonal
#define MOVIMENTO_RAINHA 8      // Rainha se move 8 casas horizontalmente

// DECLARAÇÃO DAS FUNÇÕES

// Funções de movimentação recursiva das peças
void mover_torre_recursivo(int casas_restantes, int *pos_linha, int *pos_coluna);
void mover_bispo_recursivo(int casas_restantes, int *pos_linha, int *pos_coluna);
void mover_rainha_recursivo(int casas_restantes, int *pos_linha, int *pos_coluna);

// Função de movimentação com loops aninhados
void mover_bispo_loops_aninhados(int casas_verticais, int casas_horizontais);

// Funções de exibição do tabuleiro
void exibir_tabuleiro_peca(int linha, int coluna, char peca, int passo);
void exibir_tabuleiro_cavalo(int linha, int coluna, int passo);

// Função não utilizada (mantida para compatibilidade)
void exibir_tabuleiro_rainha(int posicao_coluna);

// IMPLEMENTAÇÃO DAS FUNÇÕES DE EXIBIÇÃO

void exibir_tabuleiro_peca(int linha, int coluna, char peca, int passo) {
    printf("=== PASSO %d - POSIÇÃO DA %c ===\n", passo, peca);
    
    // Loop para percorrer todas as linhas do tabuleiro
    for (int l = 0; l < TABULEIRO_SIZE; l++) {
        // Loop para percorrer todas as colunas do tabuleiro
        for (int c = 0; c < TABULEIRO_SIZE; c++) {
            // Verifica se é a posição atual da peça
            if (l == linha && c == coluna) {
                printf("%c ", peca);  // Exibe a peça
            } else {
                printf(". ");        // Exibe espaço vazio
            }
        }
        printf("\n");  // Nova linha após cada linha do tabuleiro
    }
    printf("===============================\n\n");
}

void exibir_tabuleiro_cavalo(int linha, int coluna, int passo) {
    printf("=== PASSO %d - POSIÇÃO DO CAVALO ===\n", passo);
    
    // Loop duplo para construir o tabuleiro
    for (int l = 0; l < TABULEIRO_SIZE; l++) {
        for (int c = 0; c < TABULEIRO_SIZE; c++) {
            // Marca a posição do cavalo com 'C'
            if (l == linha && c == coluna) {
                printf("C ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("==================================\n\n");
}

// IMPLEMENTAÇÃO DAS FUNÇÕES RECURSIVAS DE MOVIMENTAÇÃO

void mover_torre_recursivo(int casas_restantes, int *pos_linha, int *pos_coluna) {
    // Condição de parada da recursão
    if (casas_restantes <= 0) {
        return;  // Fim da recursão
    }
    
    // Executa o movimento
    (*pos_coluna)++;  // Move uma casa para a direita
    
    // Verifica limites do tabuleiro
    if (*pos_coluna >= TABULEIRO_SIZE) {
        *pos_coluna = TABULEIRO_SIZE - 1;  // Mantém dentro dos limites
    }
    
    // Exibe o movimento atual
    printf("Direita\n");
    exibir_tabuleiro_peca(*pos_linha, *pos_coluna, 'T', MOVIMENTO_TORRE - casas_restantes + 1);
    
    // Chamada recursiva para o próximo movimento
    mover_torre_recursivo(casas_restantes - 1, pos_linha, pos_coluna);
}

void mover_bispo_recursivo(int casas_restantes, int *pos_linha, int *pos_coluna) {
    // Caso base da recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Movimento diagonal: cima e direita simultaneamente
    (*pos_linha)--;   // Move para cima (decrementa linha)
    (*pos_coluna)++;  // Move para direita (incrementa coluna)
    
    // Controle de limites do tabuleiro
    if (*pos_linha < 0) *pos_linha = 0;  // Não sai pela parte superior
    if (*pos_coluna >= TABULEIRO_SIZE) *pos_coluna = TABULEIRO_SIZE - 1;  // Não sai pela direita
    
    // Exibição do movimento
    printf("Diagonal (Cima-Direita)\n");
    exibir_tabuleiro_peca(*pos_linha, *pos_coluna, 'B', MOVIMENTO_BISPO - casas_restantes + 1);
    
    // Próxima iteração recursiva
    mover_bispo_recursivo(casas_restantes - 1, pos_linha, pos_coluna);
}

void mover_rainha_recursivo(int casas_restantes, int *pos_linha, int *pos_coluna) {
    // Condição de término da recursão
    if (casas_restantes <= 0) {
        return;
    }
    
    // Movimento horizontal para esquerda
    (*pos_coluna)--;  // Decrementa coluna
    
    // Verificação de limites
    if (*pos_coluna < 0) *pos_coluna = 0;  // Não permite sair do tabuleiro
    
    // Feedback visual do movimento
    printf("Esquerda\n");
    exibir_tabuleiro_peca(*pos_linha, *pos_coluna, 'R', MOVIMENTO_RAINHA - casas_restantes + 1);
    
    // Continuação da recursão
    mover_rainha_recursivo(casas_restantes - 1, pos_linha, pos_coluna);
}

// IMPLEMENTAÇÃO DAS FUNÇÕES COM LOOPS ANINHADOS

void mover_bispo_loops_aninhados(int casas_verticais, int casas_horizontais) {
    // Loop externo: controla movimento vertical
    for (int v = 0; v < casas_verticais; v++) {
        // Loop interno: controla movimento horizontal
        for (int h = 0; h < casas_horizontais; h++) {
            // Condição para movimento diagonal (v == h)
            if (v == h) {
                printf("Diagonal (Cima-Direita)\n");
            }
        }
    }
}

// FUNÇÃO PRINCIPAL

int main() {
    // Cabeçalho do programa
    printf("=== SIMULAÇÃO NÍVEL MESTRE - MOVIMENTOS DAS PEÇAS DE XADREZ ===\n\n");

    // SIMULAÇÃO DA TORRE - MOVIMENTO RECURSIVO HORIZONTAL
    
    printf("TORRE - Movimento horizontal recursivo (5 casas para a direita):\n");
    
    // Inicialização da posição da torre
    int torre_linha = 0, torre_coluna = 0;
    
    // Exibe posição inicial
    exibir_tabuleiro_peca(torre_linha, torre_coluna, 'T', 0);
    
    // Executa movimento recursivo
    mover_torre_recursivo(MOVIMENTO_TORRE, &torre_linha, &torre_coluna);
    printf("\n");

    // SIMULAÇÃO DO BISPO - MOVIMENTO RECURSIVO DIAGONAL
    
    printf("BISPO - Movimento diagonal recursivo (5 casas para cima e direita):\n");
    
    // Posição inicial do bispo (canto inferior esquerdo)
    int bispo_linha = 7, bispo_coluna = 0;
    
    // Estado inicial do bispo
    exibir_tabuleiro_peca(bispo_linha, bispo_coluna, 'B', 0);
    
    // Movimento diagonal recursivo
    mover_bispo_recursivo(MOVIMENTO_BISPO, &bispo_linha, &bispo_coluna);
    printf("\n");

    // SIMULAÇÃO DO BISPO - LOOPS ANINHADOS
    
    printf("BISPO - Movimento com loops aninhados (5 casas verticais e horizontais):\n");
    
    // Demonstração com loops aninhados
    mover_bispo_loops_aninhados(MOVIMENTO_BISPO, MOVIMENTO_BISPO);
    printf("\n");

    // SIMULAÇÃO DA RAINHA - MOVIMENTO RECURSIVO HORIZONTAL
    
    printf("RAINHA - Movimento horizontal recursivo (8 casas para a esquerda):\n");
    
    // Posição inicial da rainha (centro-direita do tabuleiro)
    int rainha_linha = 4, rainha_coluna = 7;
    
    // Posição de partida da rainha
    exibir_tabuleiro_peca(rainha_linha, rainha_coluna, 'R', 0);
    
    // Movimento recursivo para esquerda
    mover_rainha_recursivo(MOVIMENTO_RAINHA, &rainha_linha, &rainha_coluna);
    printf("\n");

    // SIMULAÇÃO DO CAVALO - LOOPS COMPLEXOS ANINHADOS
    
    printf("CAVALO - Movimento em L complexo (2 casas para cima, 1 casa para a direita):\n");
    
    // Inicialização das variáveis do cavalo
    int cavalo_linha = 7, cavalo_coluna = 1;          // Posição inicial
    int passo_cavalo = 0;                              // Contador de passos
    
    // Exibe estado inicial do cavalo
    exibir_tabuleiro_cavalo(cavalo_linha, cavalo_coluna, passo_cavalo);
    
    // Parâmetros do movimento em L do cavalo
    int movimento_vertical_cavalo = 2;     // Duas casas verticais
    int movimento_horizontal_cavalo = 1;   // Uma casa horizontal
    int etapa_atual = 0;                   // Controle de etapas
    int total_etapas = movimento_vertical_cavalo + movimento_horizontal_cavalo;
    
    // LOOPS COMPLEXOS ANINHADOS PARA O CAVALO
    
    // Loop externo: controla as etapas gerais do movimento
    for (int etapa = 0; etapa < total_etapas; etapa++) {
        
        // ------ FASE 1: MOVIMENTO VERTICAL (2 casas para cima) ------
        for (int vertical = 0; vertical < movimento_vertical_cavalo; vertical++) {
            // Verifica se ainda deve mover verticalmente
            if (etapa_atual >= movimento_vertical_cavalo) {
                break; // Sai do loop vertical quando completado
            }
            
            // Executa movimento vertical
            cavalo_linha--; // Move para cima
            if (cavalo_linha < 0) cavalo_linha = 0; // Controle de limites
            
            // Atualiza e exibe o movimento
            passo_cavalo++;
            printf("Cima\n");
            exibir_tabuleiro_cavalo(cavalo_linha, cavalo_coluna, passo_cavalo);
            etapa_atual++;
            
            // Continua se ainda há movimento vertical pendente
            if (etapa_atual < movimento_vertical_cavalo) {
                continue;
            }
        }
        
        // ------ FASE 2: MOVIMENTO HORIZONTAL (1 casa para direita) ------
        for (int horizontal = 0; horizontal < movimento_horizontal_cavalo; horizontal++) {
            // Só executa após completar movimento vertical
            if (etapa_atual < movimento_vertical_cavalo) {
                break; // Ainda não terminou fase vertical
            }
            
            // Executa movimento horizontal
            cavalo_coluna++; // Move para direita
            if (cavalo_coluna >= TABULEIRO_SIZE) cavalo_coluna = TABULEIRO_SIZE - 1; // Limites
            
            // Atualiza e exibe o movimento
            passo_cavalo++;
            printf("Direita\n");
            exibir_tabuleiro_cavalo(cavalo_linha, cavalo_coluna, passo_cavalo);
            etapa_atual++;
        }
        
        // Sai do loop externo quando movimento completo
        if (etapa_atual >= total_etapas) {
            break;
        }
    }
    
    // FINALIZAÇÃO DO PROGRAMA
    
    printf("\n=== SIMULAÇÃO NÍVEL MESTRE CONCLUÍDA ===\n");
    return 0; // Término bem-sucedido do programa
}
