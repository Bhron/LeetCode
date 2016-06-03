class Solution {
public:
    int titleToNumber(string s) {
        int num = 0;

        if (s.empty()) {
            return num;
        }

        for (int i = 0; i < s.length(); i++) {
            char label = s[i];
            num = num * 26 + label - 'A' + 1;
        }

        return num;
    }
};
