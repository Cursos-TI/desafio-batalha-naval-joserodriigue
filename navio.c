#include <stdio.h>

// Nível Mestre - Habilidades Especiais com Matrizes

// Função auxiliar para imprimir uma matriz (tabuleiro ou habilidade)
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Definindo um tamanho fixo para as matrizes de habilidade para os exemplos
    // Você pode imaginar que a origem (centro do efeito) de cada habilidade
    // estaria em um ponto específico do tabuleiro maior do Nível Aventureiro.
    // Para simplificar a visualização dos padrões, usaremos uma matriz 5x5 para cada habilidade.
    int tamanhoHabilidade = 5; // As habilidades serão centradas em uma matriz 5x5

    // Habilidade em Cone (Exemplo solicitado: 0 0 1 0 0; 0 1 1 1 0; 1 1 1 1 1)
    printf("--- Habilidade em Cone ---\n");
    int habilidadeCone[tamanhoHabilidade][tamanhoHabilidade];

    // Inicializa a matriz do cone com 0s
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            habilidadeCone[i][j] = 0;
        }
    }

    // Preenche o padrão do cone
    // O cone se expande para as bordas inferiores a partir de um ponto central no topo.
    // Considerando o centro da linha como (tamanhoHabilidade / 2)
    int centroColuna = tamanhoHabilidade / 2; // Para 5, será 2

    // Linha 0: Apenas o centro
    habilidadeCone[0][centroColuna] = 1;

    // Linha 1: Centro e adjacentes
    if (centroColuna - 1 >= 0) habilidadeCone[1][centroColuna - 1] = 1;
    habilidadeCone[1][centroColuna] = 1;
    if (centroColuna + 1 < tamanhoHabilidade) habilidadeCone[1][centroColuna + 1] = 1;

    // Linha 2 (e próximas): Todas as posições
    for (int j = 0; j < tamanhoHabilidade; j++) {
        habilidadeCone[2][j] = 1;
    }

    // Se o tamanho da habilidade fosse maior, as linhas posteriores ao centro se comportariam de forma diferente
    // Para este exemplo fixo 5x5, as linhas 0, 1 e 2 (a partir do topo) são as únicas que se encaixam no padrão.
    // As linhas 3 e 4 permaneceriam 0 se o padrão fosse estritamente o exemplo fornecido.
    // Se o cone continuasse expandindo, as linhas 3 e 4 também poderiam ser preenchidas.
    // Mas para replicar o exemplo, paramos na linha 2 que tem 5 elementos.

    imprimirMatriz(tamanhoHabilidade, tamanhoHabilidade, habilidadeCone);
    printf("\n");

    // Habilidade em Octaedro (Exemplo solicitado: 0 0 1 0 0; 0 1 1 1 0; 0 0 1 0 0)
    printf("--- Habilidade em Octaedro ---\n");
    int habilidadeOctaedro[tamanhoHabilidade][tamanhoHabilidade];

    // Inicializa a matriz do octaedro com 0s
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            habilidadeOctaedro[i][j] = 0;
        }
    }

    // Preenche o padrão do octaedro (diamante)
    // Centro (tamanhoHabilidade / 2, tamanhoHabilidade / 2)
    int centroLinha = tamanhoHabilidade / 2;
    centroColuna = tamanhoHabilidade / 2;

    // Linha do centro
    habilidadeOctaedro[centroLinha][centroColuna] = 1;
    if (centroColuna - 1 >= 0) habilidadeOctaedro[centroLinha][centroColuna - 1] = 1;
    if (centroColuna + 1 < tamanhoHabilidade) habilidadeOctaedro[centroLinha][centroColuna + 1] = 1;

    // Linha acima do centro
    if (centroLinha - 1 >= 0) {
        habilidadeOctaedro[centroLinha - 1][centroColuna] = 1;
    }

    // Linha abaixo do centro
    if (centroLinha + 1 < tamanhoHabilidade) {
        habilidadeOctaedro[centroLinha + 1][centroColuna] = 1;
    }

    imprimirMatriz(tamanhoHabilidade, tamanhoHabilidade, habilidadeOctaedro);
    printf("\n");

    // Habilidade em Cruz (Exemplo solicitado: 0 0 1 0 0; 1 1 1 1 1; 0 0 1 0 0)
    printf("--- Habilidade em Cruz ---\n");
    int habilidadeCruz[tamanhoHabilidade][tamanhoHabilidade];

    // Inicializa a matriz da cruz com 0s
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            habilidadeCruz[i][j] = 0;
        }
    }

    // Preenche o padrão da cruz
    centroLinha = tamanhoHabilidade / 2;
    centroColuna = tamanhoHabilidade / 2;

    // Linha central horizontal
    for (int j = 0; j < tamanhoHabilidade; j++) {
        habilidadeCruz[centroLinha][j] = 1;
    }

    // Coluna central vertical
    for (int i = 0; i < tamanhoHabilidade; i++) {
        habilidadeCruz[i][centroColuna] = 1;
    }

    imprimirMatriz(tamanhoHabilidade, tamanhoHabilidade, habilidadeCruz);
    printf("\n");

    return 0;
}
