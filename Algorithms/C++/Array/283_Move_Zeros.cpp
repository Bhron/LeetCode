class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }

        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[start++] = nums[i];
            }
        }

        return start;
    }
};
