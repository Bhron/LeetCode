class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        hash.clear();
        for (int i = 0; i < dictionary.size(); i++) {
            string word = dictionary[i];
            string abbreviation = get_abbreviation(word);
            hash[abbreviation].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbreviation = get_abbreviation(word);

        if (hash.find(abbreviation) == hash.end()) {
            return true;
        } else {
            const unordered_set<string>& word_set = hash[abbreviation];

            if (word_set.find(word) == word_set.end()) {
                return false;
            } else {
                return word_set.size() == 1;
            }
        }
    }
private:
    unordered_map<string, unordered_set<string>> hash;

    string get_abbreviation(const string& word) {
        string abbreviation;

        if (word.length() <= 2) {
            abbreviation = word;
        } else {
            abbreviation = word[0];
            abbreviation += to_string(word.length() - 2);
            abbreviation += word[word.length() - 1];
        }

        return abbreviation;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
