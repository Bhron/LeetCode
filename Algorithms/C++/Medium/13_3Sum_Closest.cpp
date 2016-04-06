class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty()) {
            return INT_MAX;
        }

        sort(nums.begin(), nums.end());

        int closest_sum = INT_MAX;
        bool found = false;
        for (int i = 0; i < nums.size(); i++) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    start++;
                } else {
                    end--;
                }

                if (!found || abs(target - sum) < abs(target - closest_sum)) {
                    closest_sum = sum;
                    found = true;
                }
            }
        }

        return closest_sum;
    }
};
