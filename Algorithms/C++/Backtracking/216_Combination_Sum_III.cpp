class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> combinations;

        if (k <= 0 || n <= 0) {
            return combinations;
        }

        vector<int> candidates;
        for (int i = 1; i <= 9; i++) {
            candidates.push_back(i);
        }

        vector<int> cur;

        helper(combinations, cur, 0, candidates, k, n);

        return combinations;
    }
private:
    void helper(vector<vector<int>>& combinations, vector<int>& cur, int pos, vector<int>& candidates, int k, int n) {
        if (k == 0) {
            if (n == 0) {
                combinations.push_back(cur);
            }
            return;
        }

        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] > n) {
                break;
            }

            cur.push_back(candidates[i]);
            helper(combinations, cur, i + 1, candidates, k - 1, n - candidates[i]);
            cur.pop_back();
        }
    }
};
