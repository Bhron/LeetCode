class Solution {
public:
    int findComplement(int num) {
        int bitsCount = 0;
        unsigned int tmp = num;
        while (tmp != 0) {
            bitsCount++;
            tmp >>= 1;
        }

        int xorBits = 0x0;
        while (bitsCount--) {
            xorBits *= 2;
            xorBits += 1;
        }

        return num ^ xorBits;
    }
};
