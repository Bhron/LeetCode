class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;

        if (digits.empty()) {
            return result;
        }

        string cur;
        helper(digits, 0, cur, result);

        return result;
    }
private:
    vector<vector<char>> mapping = {
        {'0'},
        {'1'},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };

    void helper(const string& digits, int pos, string& cur, vector<string>& result) {
        if (pos >= digits.size()) {
            result.push_back(string(cur));
            return;
        }

        int index = digits[pos] - '0';
        for (int i = 0; i < mapping[index].size(); i++) {
            cur.push_back(mapping[index][i]);
            helper(digits, pos + 1, cur, result);
            cur.pop_back();
        }
    }
};
