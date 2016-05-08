class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            word_indexes[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int>& indexes1 = word_indexes[word1];
        vector<int>& indexes2 = word_indexes[word2];

        int min_distance = INT_MAX;
        for (int i = 0; i < indexes1.size(); i++) {
            for (int j = 0; j < indexes2.size(); j++) {
                min_distance = min(abs(indexes1[i] - indexes2[j]), min_distance);
            }
        }

        return min_distance;
    }
private:
    unordered_map<string,vector<int>> word_indexes;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
