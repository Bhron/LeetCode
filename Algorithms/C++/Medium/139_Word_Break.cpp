class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty()) {
            if (s.empty() && wordDict.empty()) {
                return true;
            }
            if (s.empty() && wordDict.find("") != wordDict.end()) {
                return true;
            }
            return false;
        }

        int n = s.length();
        bool F[n + 1];

        int max_word_length = get_max_word_length(wordDict);
        F[0] = true;

        for (int i = 1; i <= n; i++) {
            F[i] = false;
            for (int last_word_length = 1; last_word_length <= max_word_length && last_word_length <= i; last_word_length++) {
                if (!F[i - last_word_length]) {
                    continue;
                }
                string last_word = s.substr(i - last_word_length, last_word_length);
                if (wordDict.find(last_word) != wordDict.end()) {
                    F[i] = true;
                    break;
                }
            }
        }

        return F[n];
    }
private:
    int get_max_word_length(const unordered_set<string>& wordDict) {
        int max_length = 0;

        for (auto it = wordDict.begin(); it != wordDict.end(); it++) {
            if ((*it).length() > max_length) {
                max_length = (*it).length();
            }
        }

        return max_length;
    }
};
