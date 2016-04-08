class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (wordList.empty()) {
            return 0;
        }

        unordered_set<string> hash;
        queue<string> q;

        hash.insert(beginWord);
        q.push(beginWord);

        wordList.insert(endWord);

        int length = 1;
        while (!q.empty()) {
            length++;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                vector<string> transformations = get_transformations(word, wordList);
                for (int j = 0; j < transformations.size(); j++) {
                    if (transformations[j] == endWord) {
                        return length;
                    }

                    if (hash.find(transformations[j]) == hash.end()) {
                        q.push(transformations[j]);
                        hash.insert(transformations[j]);
                    }
                }
            }
        }

        return 0;
    }
private:
    vector<string> get_transformations(string word, const unordered_set<string> &wordList) {
        vector<string> transformations;

        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == c) {
                    continue;
                }

                string transformation(word);
                transformation[i] = c;

                if (wordList.find(transformation) != wordList.end()) {
                    transformations.push_back(transformation);
                }
            }
        }

        return transformations;
    }
};
