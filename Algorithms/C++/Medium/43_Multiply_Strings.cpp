class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) {
            return "";
        }

        int len1 = num1.length(), len2 = num2.length();
        int len = len1 + len2;

        vector<int> num3(len, 0);

        int i, j;
        for (i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            for (j = len2 - 1; j >= 0; j--) {
                int product = (num2[j] - '0') * (num1[i] - '0') + num3[i + j + 1] + carry;
                num3[i + j + 1] = product % 10;
                carry = product / 10;
            }
            num3[i + j + 1] = carry;
        }

        string result;
        i = 0;
        while (i < len - 1 && num3[i] == 0) {
            i++;
        }
        while (i < len) {
            result.push_back(num3[i++] + '0');
        }

        return result;
    }
};
