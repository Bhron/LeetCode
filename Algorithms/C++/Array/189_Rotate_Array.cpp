class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) {
            return;
        }

        int n = nums.size();
        k = k % n;
        if (k == 0) {
            return;
        }

        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);

        return;
    }
private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;

            start++;
            end--;
        }
    }
};
