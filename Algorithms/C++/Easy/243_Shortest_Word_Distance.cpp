class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1, min_distance = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1 || words[i] == word2) {
                if (words[i] == word1) {
                    index1 = i;
                } else {
                    index2 = i;
                }

                if (index1 != -1 && index2 != -1) {
                    min_distance = min(abs(index1 - index2), min_distance);
                }
            }
        }

        return min_distance;
    }
};
