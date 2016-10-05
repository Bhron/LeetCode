class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int xorResult = x ^ y;

        int distance = 0;
        while (xorResult != 0) {
            distance += (xorResult & 0x1) == 1 ? 1 : 0;
            xorResult >>= 1;
        }

        return distance;
    }
};
