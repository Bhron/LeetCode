// O(n) Time for move(), O(n^2) Space
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        grid = vector<vector<int>>(n, vector<int>(n, 0));
        this->n = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row][col] = player;

        int row_counter = 0, col_counter = 0;
        for (int i = 0; i < n; i++) {
            if (grid[row][i] == player) {
                row_counter++;
            }
            if (grid[i][col] == player) {
                col_counter++;
            }
        }
        if (row_counter == n || col_counter == n) {
            return player;
        }

        int diagonal_counter = 0, anti_diagonal_counter = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][i] == player) {
                diagonal_counter++;
            }
            if (grid[n - 1 - i][i] == player) {
                anti_diagonal_counter++;
            }
        }
        if (diagonal_counter == n || anti_diagonal_counter == n) {
            return player;
        }

        return 0;
    }
private:
    vector<vector<int>> grid;
    int n;
};

// O(1) Time for move(), O(n) Space
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        anti_diagonal = 0;
        this->n = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int val = player == 1 ? 1 : -1;

        rows[row] += val;
        cols[col] += val;
        if (row == col) {
            diagonal += val;
        }
        if (row + col == n - 1) {
            anti_diagonal += val;
        }
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diagonal) == n || abs(anti_diagonal) == n) {
            return player;
        }

        return 0;
    }
private:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti_diagonal;
    int n;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
