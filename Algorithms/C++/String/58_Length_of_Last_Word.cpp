class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        // Skip the empty space at the end.
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        if (i < 0) {
            return 0;
        }

        int last_word_len = 0;
        while (i >= 0 && s[i] != ' ') {
            last_word_len++;
            i--;
        }

        return last_word_len;
    }
};
