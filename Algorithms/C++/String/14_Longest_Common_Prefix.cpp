class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;

        if (strs.empty()) {
            return prefix;
        }

        int min_len = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].length() < min_len) {
                min_len = strs[i].length();
            }
        }

        for (int i = 0; i < min_len; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return prefix;
                }
            }

            prefix += strs[0][i];
        }

        return prefix;
    }
};
