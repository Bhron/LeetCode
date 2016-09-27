class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        if (n <= 0) {
            return result;
        }

        string cur = "";
        helper(result, cur, n, n);

        return result;
    }
private:
    void helper(vector<string>& result, string& cur, int leftParentheses, int rightParentheses) {
        if (leftParentheses == 0) {
            if (rightParentheses > 0) {
                result.push_back(cur + string(rightParentheses, ')'));
            } else {
                result.push_back(cur);
            }
            return;
        }

        if (leftParentheses < rightParentheses) {
            cur.push_back('(');
            helper(result, cur, leftParentheses - 1, rightParentheses);
            cur.pop_back();

            cur.push_back(')');
            helper(result, cur, leftParentheses, rightParentheses - 1);
            cur.pop_back();
        } else {
            // Equal
            cur.push_back('(');
            helper(result, cur, leftParentheses - 1, rightParentheses);
            cur.pop_back();
        }
    }
};
