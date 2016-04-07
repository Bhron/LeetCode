// Recursion
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

// Non-Recursion
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> all_subsets;

        if (nums.empty()) {
            return all_subsets;
        }

        sort(nums.begin(), nums.end());

        vector<int> cur;
        all_subsets.push_back(cur);

        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = all_subsets.size();
            for (int j = start; j < n; j++) {
                cur = all_subsets[j];
                cur.push_back(nums[i]);
                all_subsets.push_back(cur);
            }

            if (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                start = n;
            } else {
                start = 0;
            }
        }

        return all_subsets;
    }
};
