class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9) {
            return false;
        }

        unordered_set<char> visited;

        for (int i = 0; i < 9; i++) {
            visited.clear();
            for (int j = 0; j < 9; j++) {
                if (check(visited, board[i][j]) == false) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            visited.clear();
            for (int j = 0; j < 9; j++) {
                if (check(visited, board[j][i]) == false) {
                    return false;
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                visited.clear();
                for (int k = 0; k < 9; k++) {
                    if (check(visited, board[i * 3 + k / 3][j * 3 + k % 3]) == false) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
private:
    bool check(unordered_set<char>& visited, char cell) {
        if (cell == '.') {
            return true;
        }

        if (cell < '1' || cell > '9') {
            return false;
        }

        if (visited.find(cell) != visited.end()) {
            return false;
        }

        visited.insert(cell);

        return true;
    }
};
