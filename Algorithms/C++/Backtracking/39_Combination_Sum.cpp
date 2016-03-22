class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;

        if (candidates.empty()) {
            return combinations;
        }

        sort(candidates.begin(), candidates.end());
        vector<int> cur;

        helper(combinations, cur, 0, candidates, target);

        return combinations;
    }
private:
    void helper(vector<vector<int>>& combinations, vector<int>& cur, int pos, vector<int>& candidates, int target) {
        if (target == 0) {
            combinations.push_back(cur);
            return;
        }

        int prev = -1;
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }

            if (prev == -1 && prev == candidates[i]) {
                continue;
            }

            cur.push_back(candidates[i]);
            helper(combinations, cur, i, candidates, target - candidates[i]);
            cur.pop_back();

            prev = candidates[i];
        }
    }
};
