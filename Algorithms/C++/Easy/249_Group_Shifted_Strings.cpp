class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> groups;

        if (strings.empty()) {
            return groups;
        }

        sort(strings.begin(), strings.end());

        unordered_map<string, vector<string>> hash;
        for (int i = 0; i < strings.size(); i++) {
            string last_shift = get_last_shift(strings[i]);
            if (hash.find(last_shift) == hash.end()) {
                hash[last_shift] = vector<string>{ strings[i] };
            } else {
                hash[last_shift].push_back(strings[i]);
            }
        }

        for (auto it = hash.begin(); it != hash.end(); it++) {
            groups.push_back(it->second);
        }

        return groups;
    }
private:
    string get_last_shift(const string& str) {
        if (str.empty()) {
            return "";
        }

        string result;

        int offset = str[0] - 'a';
        for (int i = 0; i < str.length(); i++) {
            char c = str[i] - offset;
            if (c < 'a') {
                c += 26;
            }
            result += c;
        }

        return result;
    }
};
