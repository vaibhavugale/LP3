
class Nqueen {
    public static boolean isSafe(int[][] board, int row, int col) {

        for (int i = 0; i < col; i++) { // row check kr
            if (board[row][i] == 1)
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) { // upper-diagonal check kr
            if (board[i][j] == 1)
                return false;
        }

        for (int i = row, j = col; i < board.length && j >= 0; i++, j--) { // bottom-diagonal check kr
            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    public static boolean solveNQueenUtil(int[][] board, int col) {

        if (col >= board.length) {
            return true;
        }

        for (int i = 0; i < board.length; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 1;
                printboard(board);
                System.out.println();
                if (solveNQueenUtil(board, col + 1)) {
                    return true;
                }
                board[i][col] = 0;

            }
        }
        return false;
    }

    public static void printboard(int board[][]) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void solveNQueen(int n) {
        int[][] board = new int[n][n];

        if (!solveNQueenUtil(board, 0)) {
            System.out.println("Solution does not exist");
        } else {
            printboard(board);
        }
    }

    public static void main(String args[]) {
        int n = 4;

        solveNQueen(n);
    }
}