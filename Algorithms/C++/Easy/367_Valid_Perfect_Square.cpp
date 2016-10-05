class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0, end = num;
        while (start + 1 < end) {
            long mid = start + (end - start) / 2;
            long square = mid * mid;
            if (square == num) {
                return true;
            } else if (square < num) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (start * start == num || end * end == num) {
            return true;
        }
        return false;
    }
};
