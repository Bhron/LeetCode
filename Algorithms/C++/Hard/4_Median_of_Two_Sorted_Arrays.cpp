class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() && nums2.empty()) {
            return 0;
        }

        int size = nums1.size() + nums2.size();

        if (size % 2 == 1) {
            return find_Kth(nums1, 0, nums2, 0, size / 2 + 1);
        } else {
            return ((double)find_Kth(nums1, 0, nums2, 0, size / 2) + (double)find_Kth(nums1, 0, nums2, 0, size / 2 + 1)) / 2;
        }
    }
private:
    int find_Kth(vector<int>& nums1, int nums1_start, vector<int>& nums2, int nums2_start, int k) {
        if (nums1_start >= nums1.size()) {
            return nums2[nums2_start + k - 1];
        }
        if (nums2_start >= nums2.size()) {
            return nums1[nums1_start + k - 1];
        }
        if (k == 1) {
            return min(nums1[nums1_start], nums2[nums2_start]);
        }

        int val1 = nums1_start + k / 2 - 1 < nums1.size() ? nums1[nums1_start + k / 2 - 1] : INT_MAX;
        int val2 = nums2_start + k / 2 - 1 < nums2.size() ? nums2[nums2_start + k / 2 - 1] : INT_MAX;

        if (val1 < val2) {
            return find_Kth(nums1, nums1_start + k / 2, nums2, nums2_start, k - k / 2);
        } else {
            return find_Kth(nums1, nums1_start, nums2, nums2_start + k / 2, k - k / 2);
        }
    }
};
