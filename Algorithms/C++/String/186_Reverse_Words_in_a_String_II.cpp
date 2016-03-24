class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) {
            return;
        }

        int i = 0, start, end;
        while (i < s.length()) {
            start = i;
            while (i < s.length() && s[i] != ' ') {
                i++;
            }
            end = i - 1;

            reverse(s, start, end);

            i++;
        }

        reverse(s, 0, s.length() - 1);
    }
private:
    void reverse(string& s, int start, int end) {
        while (start < end) {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;

            start++;
            end--;
        }
    }
};
