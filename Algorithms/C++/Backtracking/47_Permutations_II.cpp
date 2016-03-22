class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;

        if (nums.empty()) {
            return permutations;
        }

        sort(nums.begin(), nums.end());
        vector<bool> selected(nums.size(), false);
        vector<int> init;

        helper(permutations, selected, init, nums);

        return permutations;
    }
private:
    void helper(vector<vector<int>>& permutations, vector<bool>& selected, vector<int>& cur, vector<int>& nums) {
        if (cur.size() == nums.size()) {
            permutations.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!selected[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !selected[i - 1]) {
                    continue;
                }

                cur.push_back(nums[i]);
                selected[i] = true;
                helper(permutations, selected, cur, nums);
                selected[i] = false;
                cur.pop_back();
            }
        }
    }
};
