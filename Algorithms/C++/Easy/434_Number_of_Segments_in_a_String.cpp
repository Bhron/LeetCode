class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) {
            return 0;
        }

        int segments = 0;
        int i = 0, length = s.length();
        while (i < length) {
            if (s[i] == ' ') {
                i++;
                continue;
            }

            while (i < length && s[i] != ' ') {
                i++;
            }
            segments++;
        }

        return segments;
    }
};
