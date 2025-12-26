#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void visualizacao(short tabuleiro[10][10]) {
    printf("         >>>> TABULEIRO <<<<      \n");
    printf("  | 0  1  2  3  4  5  6  7  8  9 |\n");
    printf("--+------------------------------+");
    printf("\n");
    for (short linha = 0; linha < 10; linha++) {

        printf("%d |", linha);
        for (short col = 0; col < 10; col++) {
            printf(" %d ", tabuleiro[linha][col]);
        }

        printf("|\n");
    }
    printf("--+------------------------------+");
    printf("\n");
}


int main() {

    short lin_nav1 = 0, col_nav1 = 0;
    short lin_nav2 = 0, col_nav2 = 0;

    short tabuleiro[10][10] = {
    //   0  1  2  3  4  5  6  7  8  9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 0
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 1
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 2
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
    };

    visualizacao(tabuleiro);

    printf("Posicione 2 navios fornecendo as cordenadas\n");

    do {
        do {
            printf("Digite a posição do 1 Navio[Ex: 0 1]\n");
            printf("=> ");
            scanf(" %hd %hd", &lin_nav1, &col_nav1);

            if (!((lin_nav1 < 10 && lin_nav1 >= 0) && (col_nav1 < 10 && col_nav1 >= 0))) {
                printf("Coordenados Inválidas.\n Tente Novamente!\n");
            }else if(!(lin_nav1 + 3 < 10)) {
                printf("O Navio excede os limites do Tabuleiro.\n Tente Novamente!\n");
            }else {
                break; 
            }

        } while(1);

        do {
            printf("Digite a posição do 2 Navio[Ex: 0 1]\n");
            printf("=> ");
            scanf(" %hd %hd", &lin_nav2, &col_nav2);

            if (!((lin_nav2 < 10 && lin_nav2 >= 0) && (col_nav2 < 10 && col_nav2 >= 0))) {
                printf("Coordenados Inválidas.\n Tente Novamente!\n");
            }else if(!(col_nav2 + 3 < 10)) {
                printf("O Navio excede os limites do Tabuleiro.\n Tente Novamente!\n");
            }else {
                break; 
            }

        } while(1);


        if (lin_nav2 >= lin_nav1 && lin_nav2 <= lin_nav1 + 2) { 
            printf("Os navios se sobrepoem, escolha outras coordenadas\n");
            continue;
        }

        break;
    } while(1);

    // Navio 1
    for (short i = lin_nav1; i <= lin_nav1 + 2; i++) {
        tabuleiro[i][col_nav1] = 1;
    }

    // Navio 2
    for (short i = col_nav2; i <= col_nav2 + 2; i++) {
        tabuleiro[lin_nav2][i] = 1;
    }

    visualizacao(tabuleiro);

    return 0;
}
