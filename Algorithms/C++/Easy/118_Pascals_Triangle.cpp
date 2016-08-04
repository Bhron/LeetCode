class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        if (numRows <= 0) {
            return triangle;
        }

        triangle.push_back(vector<int>(1, 1));

        for (int i = 2; i <= numRows; i++) {
            vector<int> row(1, 1);

            vector<int> previousRow = triangle[i - 2];
            for (int j = 0; j < i - 2; j++) {
                row.push_back(previousRow[j] + previousRow[j + 1]);
            }
            row.push_back(1);

            triangle.push_back(row);
        }

        return triangle;
    }
};
