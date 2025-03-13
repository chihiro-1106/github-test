#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void initBoard() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin(char player) {
    for(int i=0;i<3;i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) return 1;
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player) return 1;
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) return 1;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) return 1;
    return 0;
}

int isFull() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ') return 0;
    return 1;
}

void playerMove() {
    int row, col;
    while(1) {
        printf("あなたの番です (行  列 1-3 1-3): ");
        scanf("%d %d", &row, &col);
        row--; col--;

        if(row>=0 && row<3 && col>=0 && col<3 && board[row][col]==' ') {
            board[row][col] = 'X';
            break;
        } else {
            printf("もう一度お願いします.\n");
        }
    }
}

void computerMove() {
    int row, col;
    printf("CPUの番です:\n");
    while(1) {
        row = rand() % 3;
        col = rand() % 3;
        if(board[row][col] == ' ') {
            board[row][col] = 'O';
            break;
        }
    }
}

int main() {
    srand(time(NULL));
    initBoard();

    while(1) {
        printBoard();
        playerMove();
        if(checkWin('X')) {
            printBoard();
            printf("あなた　勝ち!\n");
            break;
        }
        if(isFull()) {
            printBoard();
            printf("引き分け!\n");
            break;
        }

        computerMove();
        if(checkWin('O')) {
            printBoard();
            printf("CPU　勝ち!\n");
            break;
        }
        if(isFull()) {
            printBoard();
            printf("引き分け!\n");
            break;
        }
    }

    return 0;
}
