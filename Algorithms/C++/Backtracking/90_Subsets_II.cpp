class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> all_subsets;

        if (nums.empty()) {
            return all_subsets;
        }

        sort(nums.begin(), nums.end());
        vector<int> init_set;

        helper(all_subsets, init_set, nums, 0);

        return all_subsets;
    }
private:
    void helper(vector<vector<int>>& all_subsets, vector<int>& cur_set, vector<int>& nums, int pos) {
        all_subsets.push_back(cur_set);

        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i - 1]) {
                continue;
            }

            cur_set.push_back(nums[i]);
            helper(all_subsets, cur_set, nums, i + 1);
            cur_set.pop_back();
        }
    }
};
