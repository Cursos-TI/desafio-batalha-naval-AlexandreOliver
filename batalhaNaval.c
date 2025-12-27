#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void visualizacao(char tabuleiro[10][10]) {
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
    short lin_nav3 = 0, col_nav3 = 0;
    short lin_nav4 = 0, col_nav4 = 0;

    char matriz_n1[3][2];
    char matriz_n2[3][2];
    char matriz_n3[3][2];
    char matriz_n4[3][2];
    
    char bool_loop = 0; // false

    char tabuleiro[10][10] = {
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
    
    printf("Posicione 4 navios fornecendo as cordenadas\n");
    
    do {
        bool_loop = 0;
        do {
            printf("Digite a posição do 1 Navio[Ex: 0 1]\n");
            printf("=> ");
            scanf(" %hd %hd", &lin_nav1, &col_nav1);

            if (!((lin_nav1 < 10 && lin_nav1 >= 0) && (col_nav1 < 10 && col_nav1 >= 0))) {
                printf("Coordenados Inválidas.\n Tente Novamente!\n");
            } else if (!(lin_nav1 + 2 < 10)) {
                printf("O Navio excede os limites do Tabuleiro.\n Tente Novamente!\n");
            } else {
                for (short i = 0; i < 3; ++i) {
                    matriz_n1[i][0] = lin_nav1 + i;
                    matriz_n1[i][1] = col_nav1;
                }

                break; 
            }

        } while(1);

        do {
            printf("Digite a posição do 2 Navio[Ex: 0 1]\n");
            printf("=> ");
            scanf(" %hd %hd", &lin_nav2, &col_nav2);

            if (!((lin_nav2 < 10 && lin_nav2 >= 0) && (col_nav2 < 10 && col_nav2 >= 0))) {
                printf("Coordenados Inválidas.\n Tente Novamente!\n");
            }else if(!(col_nav2 + 2 < 10)) {
                printf("O Navio excede os limites do Tabuleiro.\n Tente Novamente!\n");
            } else {
                for (short i = 0; i < 3; ++i) {
                    matriz_n2[i][0] = lin_nav2;
                    matriz_n2[i][1] = col_nav2 + i;
                }

                break; 
            }

        } while(1);

        do {
            printf("Digite a posição do 3 Navio[Ex: 0 1]\n");
            printf("=> ");
            scanf(" %hd %hd", &lin_nav3, &col_nav3);

            if (!((lin_nav3 < 10 && lin_nav3 >= 0) && (col_nav3 < 10 && col_nav3 >= 0))) {
                printf("Coordenados Inválidas.\n Tente Novamente!\n");
            } else if (!(col_nav3 + 2 < 10 && lin_nav3 + 2 < 10)) {
                printf("O Navio excede os limites do Tabuleiro.\n Tente Novamente!\n");
            } else {
                for (short i = 0; i < 3; ++i) {
                    matriz_n3[i][0] = lin_nav3 + i;
                    matriz_n3[i][1] = col_nav3 + i;
                }

                break; 
            }

        } while(1);

        do {
            printf("Digite a posição do 4 Navio[Ex: 0 1]\n");
            printf("=> ");
            scanf(" %hd %hd", &lin_nav4, &col_nav4);

            if (!((lin_nav4 < 10 && lin_nav4 >= 0) && (col_nav4 < 10 && col_nav4 >= 0))) {
                printf("Coordenados Inválidas.\n Tente Novamente!\n");
            }else if(!(col_nav4 + 2 < 10 && lin_nav4 + 2 < 10)) {
                printf("O Navio excede os limites do Tabuleiro.\n Tente Novamente!\n");
            }else {
                for (short i = 0; i < 3; ++i) {
                    matriz_n4[i][0] = lin_nav4 + i;
                    matriz_n4[i][1] = col_nav4 + i;
                }

                break; 
            }

        } while(1);

        //            Verificação de Coordenadas Comuns
        short c = 0; 
        while (c < 3) {
            char l1 = matriz_n1[c][0];
            char c1 = matriz_n1[c][1];
        
            for (short j = 0; j < 3; ++j) {
                if (l1 == matriz_n2[j][0] && c1 == matriz_n2[j][1]) {
                    printf("O navio 2 sobrepoe outro navio, escolha outras coordenadas\n Tente Novanmente!\n");
                    c = 3;
                    bool_loop = 1; // true
                    break;
                } else if (l1 == matriz_n3[j][0] && c1 == matriz_n3[j][1]) {
                    printf("O navio 3 sobrepoe outro navio, escolha outras coordenadas\n Tente Novanmente!\n");
                    c = 3;
                    bool_loop = 1;
                    break;
                } else if (l1 == matriz_n4[j][0] && c1 == matriz_n4[j][1]) {
                    printf("O navio 4 sobrepoe outro navio, escolha outras coordenadas\n Tente Novanmente!\n");
                    c = 3;
                    bool_loop = 1;
                    break;
                }
            }

            ++c;
        }

    } while(bool_loop);

    // Navio 1
    for (char i = lin_nav1; i <= lin_nav1 + 2; i++) {
        tabuleiro[i][col_nav1] = 3;
    }

    // Navio 2
    for (char i = col_nav2; i <= col_nav2 + 2; i++) {
        tabuleiro[lin_nav2][i] = 3;
    }

    // Navio 3
    for (char i = 0; i < 3; ++i) {
        tabuleiro[lin_nav3 + i][col_nav3 + i] = 3;
    }

    // Navio 4
    for (char i = 0; i < 3; ++i) {
        tabuleiro[lin_nav4 + i][col_nav4 + i] = 3;
    }

    visualizacao(tabuleiro);

    return 0;
}
