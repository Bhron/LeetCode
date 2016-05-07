class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty() && t.empty()) {
            return true;
        }
        if (s.empty() || t.empty()) {
            return false;
        }
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> character_map;
        unordered_set<char> character_set;
        for (int i = 0; i < s.length(); i++) {
            if (character_map.find(s[i]) == character_map.end()) {
                if (character_set.find(t[i]) != character_set.end()) {
                    return false;
                }
                character_map[s[i]] = t[i];
                character_set.insert(t[i]);
            } else if (character_map[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};
