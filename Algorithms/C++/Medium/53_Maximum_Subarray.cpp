class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int largest_sum = INT_MIN, min_prefix_sum = 0, prefix_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            largest_sum = max(largest_sum, prefix_sum - min_prefix_sum);
            min_prefix_sum = min(min_prefix_sum, prefix_sum);
        }

        return largest_sum;
    }
};
