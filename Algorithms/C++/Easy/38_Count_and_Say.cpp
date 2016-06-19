class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) {
            return "";
        }

        string sequence = "1";
        while (--n > 0) {
            string tmp;

            int i = 0, j;
            while (i < sequence.length()) {
                char c = sequence[i];
                for (j = i; j < sequence.length() && sequence[j] == c; j++) {
                    ;
                }

                tmp += to_string(j - i) + c;
                i = j;
            }

            sequence = tmp;
        }

        return sequence;
    }
};
