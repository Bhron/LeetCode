// O(n * m) Space
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        int** F = new int*[n + 1];
        for (int i = 0; i <= n; i++) {
            F[i] = new int[m + 1];
        }

        for (int i = 0; i <= n; i++) {
            F[i][0] = 1;
        }
        for (int i = 1; i <= m; i++) {
            F[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    F[i][j] = F[i - 1][j] + F[i - 1][j - 1];
                } else {
                    F[i][j] = F[i - 1][j];
                }
            }
        }

        int distinct_subsequences = F[n][m];
        delete F;

        return distinct_subsequences;
    }
};
