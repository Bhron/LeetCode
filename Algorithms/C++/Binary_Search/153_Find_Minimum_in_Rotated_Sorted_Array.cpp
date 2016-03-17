class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        int target = nums[end];

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] < nums[end]) {
            return nums[start];
        }
        return nums[end];
    }
};
