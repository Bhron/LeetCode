class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                char top = stk.top();
                if (c == ')' && top != '('
                || c == '}' && top != '{'
                || c == ']' && top != '[') {
                    return false;
                }
                stk.pop();
            }
        }

        if (!stk.empty()) {
            return false;
        }
        return true;
    }
};
