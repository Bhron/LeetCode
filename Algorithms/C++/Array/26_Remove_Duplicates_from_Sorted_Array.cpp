class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[len]) {
                nums[++len] = nums[i];
            }
        }

        return len + 1;
    }
};
