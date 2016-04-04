class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int largest_sum = INT_MIN, min_sum = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            largest_sum = max(largest_sum, sum - min_sum);
            min_sum = min(min_sum, sum);
        }

        return largest_sum;
    }
};
