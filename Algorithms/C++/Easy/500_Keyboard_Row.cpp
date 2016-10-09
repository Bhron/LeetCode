class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            if (word.empty()) {
                continue;
            }

            bool canTypeUsingOneRow = true;
            int j = 0;
            int firstFlag = alphabetRowMap[toupper(word[j])];
            for (; j < word.length(); j++) {
                int flag = alphabetRowMap[toupper(word[j])];
                if (flag != firstFlag) {
                    canTypeUsingOneRow = false;
                    break;
                }
            }

            if (canTypeUsingOneRow) {
                result.push_back(word);
            }
        }

        return result;
    }

private:
    unordered_map<char, int> alphabetRowMap = {
        {'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}, {'T', 0}, {'Y', 0}, {'U', 0}, {'I', 0}, {'O', 0}, {'P', 0},
        {'A', 1}, {'S', 1}, {'D', 1}, {'F', 1}, {'G', 1}, {'H', 1}, {'J', 1}, {'K', 1}, {'L', 1},
        {'Z', 2}, {'X', 2}, {'C', 2}, {'V', 2}, {'B', 2}, {'N', 2}, {'M', 2},
    };
};
