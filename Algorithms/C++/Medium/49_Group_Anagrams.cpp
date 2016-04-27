class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;

        if (strs.empty()) {
            return groups;
        }

        sort(strs.begin(), strs.end());

        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strs.size(); i++) {
            string anagram = get_anagram(strs[i]);
            if (hash.find(anagram) == hash.end()) {
                hash[anagram] = vector<string>{ strs[i] };
            } else {
                hash[anagram].push_back(strs[i]);
            }
        }

        for (auto it = hash.begin(); it != hash.end(); it++) {
            groups.push_back(it->second);
        }

        return groups;
    }
private:
    string get_anagram(const string& str) {
        if (str.empty()) {
            return "";
        }

        vector<int> alphabet(26, 0);
        for (int i = 0; i < str.length(); i++) {
            alphabet[str[i] - 'a']++;
        }

        string anagram;
        for (int i = 0; i < alphabet.size(); i++) {
            if (alphabet[i] > 0) {
                anagram += string(alphabet[i], 'a' + i);
            }
        }

        return anagram;
    }
};
