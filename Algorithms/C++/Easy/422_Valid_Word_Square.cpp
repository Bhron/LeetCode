class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m = words.size();
        int max = m;
        for (int i = 0; i < m; i++) {
            int wordLength = words[i].length();
            if (wordLength > max) {
                max = wordLength;
            }
        }

        for (int k = 0; k < max; k++) {
            if (k >= m) {
                break;
            }

            string row = words[k];
            string column = "";
            for (int i = 0; i < m; i++) {
                string word = words[i];
                if (k < word.length()) {
                    column += word[k];
                }
            }

            if (row != column) {
                return false;
            }
        }

        return true;
    }
};
