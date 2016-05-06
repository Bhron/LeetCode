class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> all_palindromes;

        if (s.empty()) {
            all_palindromes.push_back("");
            return all_palindromes;
        }

        unordered_map<char, int> character_counter;
        for (int i = 0; i < s.length(); i++) {
            if (character_counter.find(s[i]) == character_counter.end()) {
                character_counter[s[i]] = 1;
            } else {
                character_counter[s[i]]++;
            }
        }

        odd_character_counter = 0;
        string characters;

        for (auto it = character_counter.begin(); it != character_counter.end(); it++) {
            char c = it->first;
            int num = it->second;

            if (num % 2 == 1) {
                odd_character_counter++;
                odd_character = c;

                if (odd_character_counter > 1) {
                    return all_palindromes;
                }
            } else {
                characters += string(num / 2, c);
            }
        }

        if (odd_character_counter != 0) {
            int num = character_counter[odd_character];
            if (num > 1) {
                characters += string(num / 2, odd_character);
            }
        }

        vector<bool> selected(characters.length(), false);
        string cur;
        helper(character_counter, characters, selected, cur, all_palindromes);

        return all_palindromes;
    }
private:
    int odd_character_counter;
    char odd_character;

    void helper(unordered_map<char, int>& character_counter, const string& characters, vector<bool>& selected, string& cur, vector<string>& all_palindromes) {
        if (cur.length() == characters.length()) {
            string palindrome = cur;

            if (odd_character_counter != 0) {
                palindrome += string(1, odd_character);
            }

            string right_part = cur;
            reverse(right_part.begin(), right_part.end());
            palindrome += right_part;

            all_palindromes.push_back(palindrome);
            return;
        }

        for (int i = 0; i < characters.length(); i++) {
            if (selected[i] || i > 0 && characters[i] == characters[i - 1] && !selected[i - 1]) {
                continue;
            }

            selected[i] = true;
            cur += characters[i];
            helper(character_counter, characters, selected, cur, all_palindromes);
            cur.pop_back();
            selected[i] = false;
        }
    }
};
