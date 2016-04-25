class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() && str.empty()) {
            return true;
        }
        if (pattern.empty() || str.empty()) {
            return false;
        }

        unordered_map<char, string> hash;
        unordered_set<string> words;
        pos = 0;
        for (int i = 0; i < pattern.length(); i++) {
            string word = get_next(str);
            if (word.empty()) {
                return false;
            }

            if (hash.find(pattern[i]) == hash.end()) {
                if (words.find(word) != words.end()) {
                    return false;
                }
                hash[pattern[i]] = word;
                words.insert(word);
            } else if (hash[pattern[i]] != word) {
                return false;
            }
        }

        return pos == str.length();
    }
private:
    int pos;

    string get_next(string str) {
        if (pos >= str.length()) {
            return "";
        }

        int i, begin = pos;
        for (i = begin; i < str.length() && str[i] != ' '; i++) {
            ;
        }

        if (i < str.length()) {
            pos = i + 1;
        } else {
            pos = i;
        }

        return str.substr(begin, i - begin);
    }
};
