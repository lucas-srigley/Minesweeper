#include <stdio.h>
#include <stdlib.h>

/*
 * This program is designed to mimic minesweeper.
 */

//introduce all recursive functions
void fillCells(int row, int col);
int check(int row, int col);
void printGrid();
void flag(int row, int col);
int checkWin();

//introduce char-type arrays with a 10 x 10 grid
char minesNumberValues[10][10];
char infoAI[10][10];

int main() {
    //seeding the rand function
    srand(2);

    //Put mines into the minesNumberValues array
    for (int i = 0; i < 10; i++) {
        int row = rand() % 10;
        int col = rand() % 10;

        if (minesNumberValues[row][col] != 'M') {
            minesNumberValues[row][col] = 'M';
        } else {
            i--;
        }
    }

    //checking for mines in the grid and generating numbers of mines that are around a given cell
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int countAdjacentMines = 0;

            if (i == 0) {
                if (j == 0 && minesNumberValues[i][j] != 'M') {
                    if (minesNumberValues[i + 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j + 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }

                countAdjacentMines = 0;

                if (j == 9 && (minesNumberValues[i][j] != 'M')) {
                    if (minesNumberValues[i + 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j - 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }

                countAdjacentMines = 0;

                if (j < 9 && j > 0 && minesNumberValues[i][j] != 'M') {
                    if (minesNumberValues[i + 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j - 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }
                countAdjacentMines = 0;
            }

            if (i < 9 && i > 0) {
                if (minesNumberValues[i][j] != 'M' && j == 0) {
                    if (minesNumberValues[i - 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j + 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }

                countAdjacentMines = 0;

                if (j == 9 && (minesNumberValues[i][j] != 'M')) {
                    if (minesNumberValues[i - 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j - 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }

                countAdjacentMines = 0;

                if (j < 9 && j > 0 && (minesNumberValues[i][j] != 'M')) {
                    if (minesNumberValues[i + 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i + 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j - 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }

                countAdjacentMines = 0;
            }
            if (i == 9) {
                if (j == 0 && (minesNumberValues[i][j] != 'M')) {
                    if (minesNumberValues[i - 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j + 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }

                countAdjacentMines = 0;

                if (j == 9 && (minesNumberValues[i][j] != 'M')) {
                    if (minesNumberValues[i - 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j - 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }

                countAdjacentMines = 0;

                if (j < 9 && j > 0 && (minesNumberValues[i][j] != 'M')) {
                    if (minesNumberValues[i - 1][j - 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i - 1][j] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j + 1] == 'M') countAdjacentMines++;
                    if (minesNumberValues[i][j - 1] == 'M') countAdjacentMines++;
                    minesNumberValues[i][j] = countAdjacentMines + '0';
                }
            }
        }
    }

    //hide information in starting grid using *
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            infoAI[i][j] = '*';
        }
    }

    //display the grid
    for (int i = 0; i < 10; i++) {
        printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c\n", minesNumberValues[i][0], minesNumberValues[i][1], minesNumberValues[i][2], minesNumberValues[i][3], minesNumberValues[i][4], minesNumberValues[i][5], minesNumberValues[i][6], minesNumberValues[i][7], minesNumberValues[i][8], minesNumberValues[i][9]);
    }

    //introduce input variables
    char command;
    int row, col;

    //do-while loop for printing out necessary lines, setting command controls, and obtaining input from the user
    do {
        row = 0;
        col = 0;
        printf("Enter 'c' for check cell, 'f' for flag cell.\n");
        printf("Enter command & cell row col: ");
        scanf("%s %d %d", &command, &row, &col);

        if (check(row, col) == 0 && command == 'c') {
            fillCells(row, col);
        }
        if (command == 'f') {
            flag(row, col);
        }

        if (checkWin() == 1) {
            break;
        }
        printGrid();
    } while (command != 'e' && infoAI[row][col] != 'M');

    //checks win and loss conditions for the game
    if (checkWin() == 1) {
        printf("You win!\n");
    } else {
        printf("Game over!\n");
    }
    return 0;
}

//fillCells function to generate numbers if blank spaces are checked
void fillCells(int row, int col) {
    if (infoAI[row][col] == '*' && minesNumberValues[row][col] == '0') {
        infoAI[row][col] = minesNumberValues[row][col];
        if (row > 0) fillCells(row - 1, col);
        if (row < 9) fillCells(row + 1, col);
        if (col > 0) fillCells(row, col - 1);
        if (col < 9) fillCells(row, col + 1);
        if (row > 0 && col > 0) fillCells(row - 1, col - 1);
        if (row > 0 && col < 9) fillCells(row - 1, col + 1);
        if (row < 9 && col > 0) fillCells(row + 1, col - 1);
        if (row < 9 && col < 9) fillCells(row + 1, col + 1);
    } else {
        infoAI[row][col] = minesNumberValues[row][col];
    }
}

//check function to find if the player lost the game by stepping on a mine
int check(int row, int col) {
    if (minesNumberValues[row][col] == 'M') {
        return 1;
    }
    return 0;
}

//printGrid function for generating a grid and filling cells
void printGrid() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c  ", infoAI[i][j]);
        }
        printf("\n");
    }
}

//flag function to place flags on the cells
void flag(int row, int col) {
    infoAI[row][col] = 'F';
}

//checkWin function for the win condition
int checkWin() {
    int countClosedCells = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (infoAI[i][j] == '*') {
                countClosedCells++;
            }
        }
    }
    return countClosedCells == 10;
}