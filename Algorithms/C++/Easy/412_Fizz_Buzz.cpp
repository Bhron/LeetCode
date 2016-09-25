class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;

        if (n <= 0) {
            return result;
        }

        for (int num = 1; num <= n; num++) {
            bool isFizz = num % 3 == 0;
            bool isFuzz = num % 5 == 0;

            if (isFizz && isFuzz) {
                result.push_back("FizzBuzz");
            } else if (isFizz) {
                result.push_back("Fizz");
            } else if (isFuzz) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(num));
            }
        }

        return result;
    }
};
