class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;

        if (n <= 0 || k < 0 || k > n) {
            return combinations;
        }

        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<int> cur;

        helper(combinations, cur, 0, nums, k);

        return combinations;
    }
private:
    void helper(vector<vector<int>>& combinations, vector<int>& cur, int pos, vector<int> nums, int k) {
        if (k == 0) {
            combinations.push_back(cur);
            return;
        }

        for (int i = pos; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            helper(combinations, cur, i + 1, nums, k - 1);
            cur.pop_back();
        }
    }
};
