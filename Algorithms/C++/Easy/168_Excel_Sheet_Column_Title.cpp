class Solution {
public:
    string convertToTitle(int n) {
        string title;

        if (n <= 0) {
            return title;
        }

        while (n > 0) {
            n--;
            title += 'A' + n % 26;
            n /= 26;
        }

        reverse(title.begin(), title.end());

        return title;
    }
};
