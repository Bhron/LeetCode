class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> sequences;

        if (wordList.empty()) {
            return sequences;
        }

        wordList.insert(endWord);
        bfs(beginWord, endWord, wordList);

        vector<string> sequence;
        dfs(beginWord, wordList, sequences, sequence, endWord);

        distance.clear();
        transformations_map.clear();

        return sequences;
    }
private:
    unordered_map<string, int> distance;
    unordered_map<string, vector<string>> transformations_map;

    void bfs(const string& beginWord, const string& endWord, const unordered_set<string>& wordList) {
        queue<string> q;
        q.push(beginWord);

        distance[beginWord] = 1;

        for (auto it = wordList.begin(); it != wordList.end(); it++) {
            transformations_map[*it] = vector<string>();
        }

        int length = 1;
        bool reach_end = false;
        while (!q.empty() && !reach_end) {
            length++;

            int size = q.size();
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                vector<string> transformations = get_transformations(word, wordList);
                for (int j = 0; j < transformations.size(); j++) {
                    string next = transformations[j];

                    (transformations_map[next]).push_back(word);

                    if (distance.find(next) == distance.end()) {
                        distance[next] = length;
                        q.push(next);
                    }

                    if (next == endWord) {
                        reach_end = true;
                    }
                }
            }
        }
    }

    void dfs(const string& beginWord, const unordered_set<string>& wordList, vector<vector<string>>& sequences, vector<string>& sequence, const string word) {

        sequence.push_back(word);

        if (word == beginWord) {
            generate_sequence(sequences, sequence);
        } else {
            vector<string> transformations = transformations_map[word];
            for (int i = 0; i < transformations.size(); i++) {
                string next = transformations[i];

                if (distance.find(next) != distance.end() && distance[next] + 1 == distance[word]) {
                    dfs(beginWord, wordList, sequences, sequence, next);
                }
            }
        }

        sequence.pop_back();
    }

    vector<string> get_transformations(const string& word, const unordered_set<string>& wordList) {
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

    void generate_sequence(vector<vector<string>>& sequences, vector<string>& sequence) {
        vector<string> result;

        for (int i = sequence.size() - 1; i >= 0; i--) {
            result.push_back(sequence[i]);
        }

        sequences.push_back(result);
    }
};
