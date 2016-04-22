class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> positions(2, -1);

        if (nums.empty()) {
            return positions;
        }

        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (nums[start] == target) {
            positions[0] = start;
        } else if (nums[end] == target) {
            positions[0] = end;
        } else {
            return positions;
        }


        start = positions[0], end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[end] == target) {
            positions[1] = end;
        } else {
            positions[1] = start;
        }

        return positions;
    }
};
