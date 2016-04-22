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

// Find the first row whose last number >= target
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size(), n = matrix[0].size();
        int low, high;
        int row;


        low = 0, high = m - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][n - 1] == target) {
                return true;
            } else if (matrix[mid][n - 1] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (matrix[low][n - 1] >= target) {
            row = low;
        } else if (matrix[high][n - 1] >= target) {
            row = high;
        } else {
            return false;
        }

        low = 0, high = n - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (matrix[row][low] == target ||
            matrix[row][high] == target) {
            return true;
        }
        return false;
    }
};

// Find last row whose first number <= target
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size(), n = matrix[0].size();
        int low, high;
        int row;

        // Find last row whose first number <= target
        low = 0, high = m - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] <= target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (matrix[high][0] <= target) {
            row = high;
        } else if (matrix[low][0] <= target) {
            row = low;
        } else {
            return false;
        }

        low = 0, high = n - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if (matrix[row][low] == target ||
            matrix[row][high] == target) {
            return true;
        }
        return false;
    }
};
