class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        } else if (haystack.empty()) {
            return -1;
        }

        int haystack_length = haystack.length();
        int needle_length = needle.length();

        for (int i = 0; i < haystack_length - needle_length + 1; i++) {
            int j;
            for (j = 0; j < needle_length && haystack[i + j] == needle[j]; j++) {
                ;
            }

            if (j == needle_length) {
                return i;
            }
        }

        return -1;
    }
};
