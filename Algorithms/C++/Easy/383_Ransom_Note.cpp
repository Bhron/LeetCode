class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) {
            return true;
        }

        unordered_map<char, int> hash;
        for (int i = 0; i < ransomNote.length(); i++) {
            hash[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.length(); i++) {
            char c = magazine[i];
            if (hash.find(c) != hash.end()) {
                hash[c]--;
            }
        }

        bool result = true;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if (it->second > 0) {
                result = false;
                break;
            }
        }

        return result;
    }
};
