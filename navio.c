#include <stdio.h>

int main() {
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal

    // 1. Matriz 10x10: Representação do Tabuleiro
    int tabuleiro[10][10];

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int navioTamanho = 3; // Tamanho fixo para todos os navios neste nível

    // Posicionamento do Navio Vertical (Exemplo existente, ajustado para 10x10)
    int nv_inicioLinha = 2;
    int nv_inicioColuna = 1;
    printf("Posicionando Navio Vertical (Tamanho %d) em (%d, %d)\n", navioTamanho, nv_inicioColuna, nv_inicioLinha);
    // Validação de limites e sobreposição para o navio vertical
    if (nv_inicioLinha + navioTamanho > 10) {
        printf("Erro: Navio vertical excede os limites do tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < navioTamanho; i++) {
        if (tabuleiro[nv_inicioLinha + i][nv_inicioColuna] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
            return 1;
        }
        tabuleiro[nv_inicioLinha + i][nv_inicioColuna] = 3;
    }

    // Posicionamento do Navio Horizontal (Exemplo existente, ajustado para 10x10)
    int nh_inicioLinha = 7;
    int nh_inicioColuna = 5;
    printf("Posicionando Navio Horizontal (Tamanho %d) em (%d, %d)\n", navioTamanho, nh_inicioColuna, nh_inicioLinha);
    // Validação de limites e sobreposição para o navio horizontal
    if (nh_inicioColuna + navioTamanho > 10) {
        printf("Erro: Navio horizontal excede os limites do tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < navioTamanho; i++) {
        if (tabuleiro[nh_inicioLinha][nh_inicioColuna + i] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1;
        }
        tabuleiro[nh_inicioLinha][nh_inicioColuna + i] = 3;
    }

    // Posicionamento do Navio Diagonal Superior Esquerda para Inferior Direita
    int nd1_inicioLinha = 0;
    int nd1_inicioColuna = 0;
    printf("Posicionando Navio Diagonal (Superior Esquerda para Inferior Direita, Tamanho %d) em (%d, %d)\n", navioTamanho, nd1_inicioColuna, nd1_inicioLinha);
    // Validação de limites e sobreposição para o navio diagonal 1
    if (nd1_inicioLinha + navioTamanho > 10 || nd1_inicioColuna + navioTamanho > 10) {
        printf("Erro: Navio diagonal 1 excede os limites do tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < navioTamanho; i++) {
        if (tabuleiro[nd1_inicioLinha + i][nd1_inicioColuna + i] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar o navio diagonal 1.\n");
            return 1;
        }
        tabuleiro[nd1_inicioLinha + i][nd1_inicioColuna + i] = 3;
    }

    // Posicionamento do Navio Diagonal Superior Direita para Inferior Esquerda
    int nd2_inicioLinha = 1;
    int nd2_inicioColuna = 9; // Começa na última coluna
    printf("Posicionando Navio Diagonal (Superior Direita para Inferior Esquerda, Tamanho %d) em (%d, %d)\n", navioTamanho, nd2_inicioColuna, nd2_inicioLinha);
    // Validação de limites e sobreposição para o navio diagonal 2
    if (nd2_inicioLinha + navioTamanho > 10 || nd2_inicioColuna - navioTamanho < -1) { // A coluna diminui, então a verificação é diferente
        printf("Erro: Navio diagonal 2 excede os limites do tabuleiro.\n");
        return 1;
    }
    for (int i = 0; i < navioTamanho; i++) {
        if (tabuleiro[nd2_inicioLinha + i][nd2_inicioColuna - i] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar o navio diagonal 2.\n");
            return 1;
        }
        tabuleiro[nd2_inicioLinha + i][nd2_inicioColuna - i] = 3;
    }

    // Exibição Completa do Tabuleiro 10x10
    printf("\nTabuleiro do Batalha Naval (10x10) com 0s (água) e 3s (navios):\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n"); // Cabeçalho das colunas
    printf("  ---------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%d |", i); // Cabeçalho das linhas
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("  ---------------------\n");
    printf("\nPosicionamento dos quatro navios concluído e tabuleiro exibido.\n");

    return 0;
}