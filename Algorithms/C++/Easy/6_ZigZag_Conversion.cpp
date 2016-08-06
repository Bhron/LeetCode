class Solution {
public:
    string convert(string s, int numRows) {
        if (s.empty() || numRows <= 1) {
            return s;
        }

        string result;
        vector<string> rows(numRows, "");

        int cycle = numRows + numRows - 2;
        for (int i = 0; i < s.length(); i++) {
            int row = i % cycle;
            if (row < numRows) {
                rows[row] += s[i];
            } else {
                rows[cycle - row] += s[i];
            }
        }

        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }

        return result;
    }
};
