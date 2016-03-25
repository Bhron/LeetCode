class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = 0;
        int i = 0, j;
        while (i < nums.size()) {
            int val = nums[i];
            for (j = i; j < nums.size() && nums[j] == val; j++) {
                if (j - i < 2) {
                    nums[len++] = val;
                }
            }
            i = j;
        }

        return len;
    }
};
