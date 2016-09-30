class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        string sumStr = "";
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;

            if (i >=0) {
                sum += num1[i--] - '0';
            }
            if (j >= 0) {
                sum += num2[j--] - '0';
            }

            carry = sum / 10;
            sumStr += '0' + sum % 10;
        }

        reverse(sumStr.begin(), sumStr.end());

        return  sumStr;
    }
};
