/*
Hash Talbe, Time Complexity O(n + m), Space Complexity O(n), n and m is the
length of array1 and array2 respectively.
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersections;

        if (nums1.empty() && nums2.empty()) {
            return intersections;
        }

        unordered_set<int> hash;
        for (int i = 0; i < nums1.size(); i++) {
            hash.insert(nums1[i]);
        }

        unordered_set<int> unique_result;
        for (int i = 0; i < nums2.size(); i++) {
            if (hash.find(nums2[i]) != hash.end()) {
                unique_result.insert(nums2[i]);
            }
        }

        for (auto const& elem: unique_result) {
            intersections.push_back(elem);
        }

        return intersections;
    }
};

/*
Sort & Binary Search, Time Complexity O(nlogn + mlogm + mlogn), Space Complexity
O(1), n and m is the length of array1 and array2 respectively.
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersections;

        if (nums1.empty() && nums2.empty()) {
            return intersections;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (i > 0 && nums2[i] == nums2[i - 1]) {
                continue;
            }

            if (helper(nums1, nums2[i]) != -1) {
                intersections.push_back(nums2[i]);
            }
        }

        return intersections;
    }
private:
    int helper(const vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }

        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }
};
