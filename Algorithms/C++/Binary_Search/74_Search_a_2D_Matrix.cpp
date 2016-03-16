class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int x = mid / n, y =  mid % n;
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (matrix[start / n][start % n] == target) {
            return true;
        }
        if (matrix[end / n][end % n] == target) {
            return true;
        }
        return false;
    }
};
