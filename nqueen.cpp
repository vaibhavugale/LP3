#include<iostream>
using namespace std;

bool isSafe(int board[8][8], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < 8 && j <8; i++, j++)
        if (board[i][j])
            return false;

    return true;
}
void solveNQueens(int board[8][8], int col,int N) {
 
    if (col == N) {
        // Print the solution
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << "-------------------\n";
        return;
    }


    for (int row = 0; row < N; row++) {

        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;
            solveNQueens(board, col + 1,N);
            board[row][col] = 0;
        }
    }
}

int main(){

    int N = 8;
    int board[8][8] = {0};

    board[0][0] = 1;


    solveNQueens(board,1,N);

    return 0;
}