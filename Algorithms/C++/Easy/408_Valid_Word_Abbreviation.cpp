class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if (word.empty()) {
            return abbr.empty() || abbr == "0";
        }
        
        int i = 0, j = 0, wordLength = word.length(), abbrLength = abbr.length();
        while (i < abbrLength && j < wordLength) {
            if (!isdigit(abbr[i])) {
                if (abbr[i] != word[j]) {
                    return false;
                }
                i++, j++;
                continue;
            }
            
            if (abbr[i] == '0') {
                return false;
            }
            
            int length = 0;
            for (; i < abbrLength && isdigit(abbr[i]); i++) {
                length = length * 10 + abbr[i] - '0';
            }
            j += length;
        }
        
        return i == abbrLength && j == wordLength;
    }
};
