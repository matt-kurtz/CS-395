/*
* id: kurt0200
* Coin Collecting Problem
*/

#include <stdio.h>
#include <stdlib.h>

void printBoard(int x, int y, char board[x][y]);
void algo(int x, int y, char board[x][y]);

int main(int argc, char *argv[]) {
    if (argc > 3) {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        char arr[x][y];
        int index = 3; // variable for looping through command line arguments
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                arr[i][j] = argv[index][0];
                index++;
            }
        }
        printf("Board Inputed:\n");
        printBoard(x, y, arr);
        algo(x, y, arr);
    }

    return 0;
}

void printBoard(int x, int y, char board[x][y]) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n");
    }
}

void algo(int x, int y, char board[x][y]) {
    int arr[x][y];

    arr[0][0] = (board[0][0] == 'X') ? -1 : (board[0][0] - '0');

    for (int j = 1; j < y; j++) {
        if (board[0][j] == 'X')
            arr[0][j] = -1;
        else
            arr[0][j] = (arr[0][j - 1] == -1) ? -1 : arr[0][j - 1] + (board[0][j] - '0');
    }

    // Initialize the first column of F
    for (int i = 1; i < x; i++) {
        if (board[i][0] == 'X')
            arr[i][0] = -1;
        else
            arr[i][0] = (arr[i - 1][0] == -1) ? -1 : arr[i - 1][0] + (board[i][0] - '0');
    }

    // Fill in the rest of F using dynamic programming
    for (int i = 1; i < x; i++) {
        for (int j = 1; j < y; j++) {
            if (board[i][j] == 'X') {
                arr[i][j] = -1;
            } else {
                int up = (arr[i - 1][j] == -1) ? -1 : arr[i - 1][j] + (board[i][j] - '0');
                int left = (arr[i][j - 1] == -1) ? -1 : arr[i][j - 1] + (board[i][j] - '0');
                arr[i][j] = (up > left) ? up : left;
            }
        }
    }

    // Print the coin collecting table
    printf("\nCoin Collecting Table:\n");
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (arr[i][j] == -1) {
               printf("0\t");
            } else {
               printf("%d\t", arr[i][j]);
            }
        }
        printf("\n");
    }

    // Find the maximum number of coins
    int maxCoins = arr[x - 1][y - 1];
    if (maxCoins == -1) {
        printf("\nThe optimal path with this board is: No path exists\n");
    } else {
        printf("\nThe optimal path with this board is: %d\n", maxCoins);
    }
}

