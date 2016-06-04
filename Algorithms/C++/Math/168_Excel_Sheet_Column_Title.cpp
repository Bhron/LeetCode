class Solution {
public:
    string convertToTitle(int n) {
        string title;

        if (n <= 0) {
            return title;
        }

        while (n > 0) {
            int curCol = n % 26;
            if (curCol == 0) {
                curCol = 26;
            }

            title += 'A' + curCol - 1;

            n /= 26;
            if (curCol == 26) {
                n--;
            }
        }

        reverse(title.begin(), title.end());

        return title;
    }
};
