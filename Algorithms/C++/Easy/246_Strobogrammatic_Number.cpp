class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> map = {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };

        for (int start = 0, end = num.length() - 1; start <= end; start++, end--) {
            if (map.find(num[start]) == map.end() || map[num[start]] != num[end]) {
                return false;
            }
        }

        return true;
    }
};
