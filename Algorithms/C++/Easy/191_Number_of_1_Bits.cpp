// Loop & Check
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;

        for (int i = 0; i < 32; i++) {
            counter += n & 0x1;
            n >>= 1;
        }

        return counter;
    }
};

// Bit Trick, O(m), m is the number of 1 bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;

        while (n != 0) {
            counter++;
            n &= (n - 1);
        }

        return counter;
    }
};
