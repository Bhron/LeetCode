class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1, min_distance = INT_MAX;
        bool is_same_word = word1 == word2;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                if (is_same_word) {
                    index1 = index2;
                    index2 = i;
                } else {
                    index1 = i;
                }
            } else if (words[i] == word2) {
                index2 = i;
            }


            if (index1 != -1 && index2 != -1) {
                min_distance = min(abs(index1 - index2), min_distance);
            }
        }

        return min_distance;
    }
};
