#include <stdio.h>

#define BOARD_SIZE         10
#define VERT_SHIP_LEN      3
#define HOR_SHIP_LEN       4
#define DIAG_SHIP_LEN      4
#define PATTERN_SIZE       5

int main() {
    // --- Posicionamento de navios via coordenadas ---
    int vertShip[VERT_SHIP_LEN][2];
    int horShip[HOR_SHIP_LEN][2];

    // navio vertical começando em (1,1)
    for (int i = 0; i < VERT_SHIP_LEN; i++) {
        vertShip[i][0] = 1 + i;  // linha
        vertShip[i][1] = 1;      // coluna fixa
    }

    // navio horizontal começando em (4,3)
    for (int i = 0; i < HOR_SHIP_LEN; i++) {
        horShip[i][0] = 4;       // linha fixa
        horShip[i][1] = 3 + i;   // coluna
    }

    printf("Coordenadas do navio vertical (%d):\n", VERT_SHIP_LEN);
    for (int i = 0; i < VERT_SHIP_LEN; i++) {
        printf("  (%d, %d)\n", vertShip[i][0], vertShip[i][1]);
    }
    printf("Coordenadas do navio horizontal (%d):\n", HOR_SHIP_LEN);
    for (int i = 0; i < HOR_SHIP_LEN; i++) {
        printf("  (%d, %d)\n", horShip[i][0], horShip[i][1]);
    }
    printf("\n");

    // --- Montagem de tabuleiro 10x10 e posicionamento de 4 navios ---
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    // vertical em (0,0)
    for (int i = 0; i < DIAG_SHIP_LEN; i++) {
        board[0 + i][0] = 3;
    }
    // horizontal em (2,2)
    for (int j = 0; j < DIAG_SHIP_LEN; j++) {
        board[2][2 + j] = 3;
    }
    // diagonal principal em (5,5)
    for (int k = 0; k < DIAG_SHIP_LEN; k++) {
        board[5 + k][5 + k] = 3;
    }
    // diagonal secundária em (9,3)
    for (int k = 0; k < DIAG_SHIP_LEN; k++) {
        board[9 - k][3 + k] = 3;
    }

    printf("Tabuleiro 10x10 (0 = vazio, 3 = navio):\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --- Geração de padrões de habilidade (5x5) ---
    int cone[PATTERN_SIZE][PATTERN_SIZE] = {0};
    int cruz[PATTERN_SIZE][PATTERN_SIZE] = {0};
    int octaedro[PATTERN_SIZE][PATTERN_SIZE] = {0};

    // padrão cone (triângulo invertido central)
    for (int i = 0; i < 3; i++) {
        for (int j = (PATTERN_SIZE/2 - i); j <= (PATTERN_SIZE/2 + i); j++) {
            cone[i][j] = 1;
        }
    }

    // padrão cruz (linha e coluna central)
    for (int i = 0; i < PATTERN_SIZE; i++) {
        cruz[PATTERN_SIZE/2][i] = 1;
        cruz[i][PATTERN_SIZE/2] = 1;
    }

    // padrão octaedro (losango simétrico)
    for (int i = 0; i < PATTERN_SIZE; i++) {
        int dist = (i <= PATTERN_SIZE/2) ? (PATTERN_SIZE/2 - i) : (i - PATTERN_SIZE/2);
        for (int j = dist; j < PATTERN_SIZE - dist; j++) {
            octaedro[i][j] = 1;
        }
    }

    printf("Padrão Cone:\n");
    for (int i = 0; i < PATTERN_SIZE; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Padrão Cruz:\n");
    for (int i = 0; i < PATTERN_SIZE; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Padrão Octaedro:\n");
    for (int i = 0; i < PATTERN_SIZE; i++) {
        for (int j = 0; j < PATTERN_SIZE; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
