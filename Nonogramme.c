#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

void display_grid(char grid[ROWS][COLS], int row_clues[ROWS], int col_clues[COLS]) {
    // Afficher les indices des colonnes
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", col_clues[i]);
    }
    printf("\n");

    // Afficher les lignes avec les indices
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", row_clues[i]);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_grid_complete(char grid[ROWS][COLS], char solution[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] != solution[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void play_nonogram(char grid[ROWS][COLS], char solution[ROWS][COLS], int row_clues[ROWS], int col_clues[COLS]) {
    int row, col;
    char input;

    // Afficher la grille vide
    printf("Grille vide :\n");
    display_grid(grid, row_clues, col_clues);

    // Afficher la grille solution
    printf("\nGrille solution :\n");
    display_grid(solution, row_clues, col_clues);

    printf("\nAppuyez sur Entrée pour commencer le jeu..."); // Ajout d'un message pour démarrer le jeu
    getchar();
    // Attendez que l'utilisateur appuie sur Entrée pour commencer

    while (!is_grid_complete(grid, solution)) {
        printf("\nEnter row and column (0-%d): ", ROWS - 1);
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            printf("Enter 'X' to mark or ' ' to unmark: ");
            scanf(" %c", &input);

            if (input == 'X' || input == ' ') {
                grid[row][col] = input;
            } else {
                printf("Invalid input, press ENTER to continue...\n");
                getchar();
                getchar();
            }
        } else {
            printf("Invalid row or column, press ENTER to continue...\n");
            getchar();
            getchar();
        }

        // Effacer l'écran et afficher la grille mise à jour
        system("cls");
        display_grid(grid, row_clues, col_clues); // Afficher les modifications apportées à la grille
    }


    printf("\nCongratulations! You solved the Nonogram!\n");
}


int main() {
    char grid[ROWS][COLS] = {
            {'?', '?', '?', '?', '?'},
            {'?', '?', '?', '?', '?'},
            {'?', '?', '?', '?', '?'},
            {'?', '?', '?', '?', '?'},
            {'?', '?', '?', '?', '?'}

    };

    char solution[ROWS][COLS] = {
            {'X', ' ', 'X', ' ', 'X'},
            {' ', 'X', ' ', 'X', ' '},
            {'X', 'X', 'X', 'X', 'X'},
            {' ', 'X', ' ', 'X', ' '},
            {'X', ' ', 'X', ' ', 'X'}
    };

    int row_clues[ROWS] = {3, 2, 5, 2, 3};
    int col_clues[COLS] = {3, 4, 1, 4, 3};

    play_nonogram(grid, solution, row_clues, col_clues);

    return 0;
}
