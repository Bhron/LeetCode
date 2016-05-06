class Solution {
public:
    bool canPermutePalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        unordered_map<char, int> character_counter;
        for (int i = 0; i < s.length(); i++) {
            if (character_counter.find(s[i]) == character_counter.end()) {
                character_counter[s[i]] = 1;
            } else {
                character_counter[s[i]]++;
            }
        }

        int odd_character_counter = 0;
        for (auto it = character_counter.begin(); it != character_counter.end(); it++) {
            int num = it->second;
            if (num % 2 == 1) {
                odd_character_counter++;
                if (odd_character_counter > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};
