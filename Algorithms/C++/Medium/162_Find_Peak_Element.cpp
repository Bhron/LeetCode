class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[mid + 1]) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] > nums[end]) {
            return start;
        }
        return end;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid - 1] > nums[mid] && nums[mid] < nums[mid + 1]) {
                high = mid;
            } else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
                low = mid;
            } else {
                high = mid;
            }
        }
    }
};
