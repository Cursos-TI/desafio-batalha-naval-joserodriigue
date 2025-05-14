#include <stdio.h>

int main() {
    // 1. Representação do Tabuleiro
    int tabuleiro[10][10];

    // Inicializa todas as posições do tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionamento dos Navios
    int navioTamanho = 3;

    // Navio Vertical
    int navioVerticalInicioLinha = 2;
    int navioVerticalInicioColuna = 1;

    // Validação do posicionamento do navio vertical
    if (navioVerticalInicioLinha + navioTamanho > 10) {
        printf("Erro: Navio vertical excede os limites do tabuleiro.\n");
        return 1; // Indica erro na execução
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < navioTamanho; i++) {
        if (tabuleiro[navioVerticalInicioLinha + i][navioVerticalInicioColuna] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
            return 1; // Indica erro na execução
        }
        tabuleiro[navioVerticalInicioLinha + i][navioVerticalInicioColuna] = 3;
    }

    // Navio Horizontal
    int navioHorizontalInicioLinha = 7;
    int navioHorizontalInicioColuna = 5;

    // Validação do posicionamento do navio horizontal
    if (navioHorizontalInicioColuna + navioTamanho > 10) {
        printf("Erro: Navio horizontal excede os limites do tabuleiro.\n");
        return 1; // Indica erro na execução
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < navioTamanho; i++) {
        if (tabuleiro[navioHorizontalInicioLinha][navioHorizontalInicioColuna + i] == 3) {
            printf("Erro: Sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1; // Indica erro na execução
        }
        tabuleiro[navioHorizontalInicioLinha][navioHorizontalInicioColuna + i] = 3;
    }

    // 3. Exibição do Tabuleiro
    printf("\nTabuleiro do Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Posicionamento dos navios no tabuleiro concluído e exibido.\n");

    return 0;
}