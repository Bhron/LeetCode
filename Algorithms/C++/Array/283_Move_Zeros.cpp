class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }

        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[start++] = nums[i];
            }
        }

        for (int i = nums.size() - 1, j = 0; j < nums.size() - start; i--, j++) {
            nums[i] = 0;
        }
    }
};
